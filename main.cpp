#include "Consola.h"
#include "Jugadores.h"
#include "ExportarBmp.h"
#include "Constantes.h"
#include "TableroMaster.h"

using namespace std;

int main(){
	srand(time(NULL));


	Consola* consola = new Consola();
	//consola->bienvenida();
	Vector<int>* dimensionesTablero = consola->pedirTamanioTablero();
	int cantidadJugadores = consola->pedirCantidadJugadores();
	int cantidadTesoros = consola->pedirCantidadTesoros();

	Jugadores* jugadores = new Jugadores(dimensionesTablero, cantidadJugadores, cantidadTesoros);
	TableroMaster* tableroGeneral = new TableroMaster(dimensionesTablero, jugadores);

	//creacion de los .bmp
	ExportarBmp* bmp= new ExportarBmp(cantidadJugadores, dimensionesTablero);

	//para probar a ver donde estan los tesoros(esta mal, los planos los imprime en el orden zyx, no en el xyz)
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
			cout << "JUGADOR " << i << endl;
			//mover tesoro
			if(jugador->get(i)->getTesoros()->contarElementos() >= 1){
				bool mueveTesoro = consola->tomaDecision("Desea mover un tesoro?");
				if(mueveTesoro){
					int tesoroAMover = consola->mostrarTesoros(jugadores->getJugador(i));
					Vector<int> * direccion = consola->elegirDireccion();
					jugador->get(i)->getTablero()->validarMovimiento(jugador->get(i)->getTesoros()->obtener(tesoroAMover)->getPosicion(),direccion);

					//VOY POR ACA
				}
			}
			else{
				jugadores->eliminarJugador(i);
				cantidadJugadores--;
			}

			//las cartas no hacen nada, falto implementarlas
			Vector<Lista<Carta*>*>* cartas = new Vector<Lista<Carta*>*>(cantidadJugadores);
			jugador->get(i)->robarCarta();
			cartas->set(i,jugador->get(i)->getCartas());
			bool juegaCarta = consola->tomaDecision("Desea jugar una carta?");
			if (juegaCarta){
				//hay que validar que la opcion del usuario no se pase de las opciones que hay de cartas
				int posicionCarta = consola->seleccionarCarta(cartas->get(i));
				jugador->get(i)->jugarCarta(posicionCarta);
				cout<<"Se juega la carta y sigue el turno"<<endl;
			}

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
			//espias

		}
	}
	//consola->despedida();

	delete bmp;
	delete tableroGeneral;
	delete jugador;
	delete jugadores;
	delete consola;
	return 0;
}



