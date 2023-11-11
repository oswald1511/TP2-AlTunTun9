#include "Consola.h"
#include "Jugadores.h"
#include "ExportarBmp.h"
#include "Constantes.h"
#include "TableroMaster.h"

using namespace std;

int main(){
	srand(time(NULL));


	Consola* consola = new Consola();
	consola->bienvenida();
	Vector<int>* dimensionesTablero = consola->pedirTamanioTablero();
	int cantidadJugadores = consola->pedirCantidadJugadores();
	int cantidadTesoros = consola->pedirCantidadTesoros();

	Jugadores* jugadores = new Jugadores(dimensionesTablero, cantidadJugadores, cantidadTesoros);
	TableroMaster* tableroGeneral = new TableroMaster(dimensionesTablero, jugadores);

	//creacion de los .bmp
	ExportarBmp* bmp= new ExportarBmp(cantidadJugadores, dimensionesTablero);

	//para probar a ver donde estan los tesoros
	//consola->imprimirTablero(tableroGeneral->getTablero());
	Vector <Jugador*> *jugador = new Vector<Jugador*>(cantidadJugadores);
	for (int i =1; i<= cantidadJugadores; i++){

		jugador->set(i,jugadores->getJugador(i));
		for(unsigned int j=1; j <= jugador->get(i)->getTesoros()->contarElementos(); j++){
			bmp->moverTesoro(jugador->get(i)->getTesoros()->obtener(j)->getPosicion(),jugador->get(i)->getTesoros()->obtener(j)->getPosicion(),i);
		}
	}

	while(cantidadJugadores > 1){

		for (int i =1; i<= cantidadJugadores; i++){

			Vector<Lista<Carta*>*>* cartas = new Vector<Lista<Carta*>*>(cantidadJugadores);
			jugador->get(i)->robarCarta();
			jugador->get(i)->getCartas();
			bool juegaCarta = consola->tomaDecision("Desea jugar una carta?");
			if (juegaCarta){
				int posicionCarta = consola->seleccionarCarta(cartas->get(i));
				jugador->get(i)->jugarCarta(posicionCarta);
			}
			cout<<"Se juega la carta y sigue el turno"<<endl;

			//tesoros mina
			if(jugador->get(i)->quedanTesorosMina()){
				bool usaTesoroMina = consola->tomaDecision("Desea colocar un tesoro mina?");
				if(usaTesoroMina){
					TesoroMina* tesoroMina;
					tesoroMina = jugador->get(i)->getTesoroMinaDisponible();
					Vector<int>* posicion = consola->pedirPosicion();

					//primero chequear si hay fichas de otros jugadores
					Casillero* casilleroOcupado = tableroGeneral->chequearPosicion(jugador->get(i)->getNumeroJugador(), posicion);
					if(casilleroOcupado){
						int jugadorAtacado = casilleroOcupado->getJugador();
						if(casilleroOcupado->getFicha() == TESORO){
							cout << "El tesoro mina encontro un tesoro del jugador ";
						} else if (casilleroOcupado->getFicha() == ESPIA){
							cout << "El tesoro mina encontro un espia del jugador ";
						} else if (casilleroOcupado->getFicha() == TESORO_MINA){
							cout << "El tesoro mina encontro un tesoro mina del juagdor ";
						}
						cout << jugadorAtacado << "!" << endl;
						cout << "Sera eliminado y se inactiva la casilla" << endl;
						tableroGeneral->deshabilitarCasillero(posicion);
					}else{
						tesoroMina->setPosicion(posicion);
						bmp->ponerTesoroMina(posicion, i);
						jugador->get(i)->getTablero()->setCasillero(posicion, TESORO_MINA, jugador->get(i)->getNumeroJugador());
					}
					tableroGeneral->actualizarTablero();

					delete posicion;
				}
			}
		}
	}
	delete bmp;
	delete tableroGeneral;
	delete jugador;
	delete jugadores;
	delete consola;
	return 0;
}



