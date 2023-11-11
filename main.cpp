#include "Consola.h"
#include "Jugadores.h"
#include "ExportarBmp.h"
#include "Constantes.h"
#include "TableroMaster.h"

using namespace std;

int main(){
	srand(time(NULL));
	Consola* consola = new Consola();
	Vector<int>* dimensionesTablero = consola->pedirTamanioTablero();
	int cantidadJugadores = consola->pedirCantidadJugadores();
	int cantidadTesoros = consola->pedirCantidadTesoros();

	//creacion de los .bmp
	ExportarBmp* bmp= new ExportarBmp(cantidadJugadores, dimensionesTablero);
	consola->bienvenida();

	Jugadores* jugadores = new Jugadores(dimensionesTablero, cantidadJugadores, cantidadTesoros);
	TableroMaster* tableroGeneral = new TableroMaster(dimensionesTablero, jugadores);

	//para probar a ver donde estan los tesoros
	//consola->imprimirTablero(tableroGeneral->getTablero());

	while(cantidadJugadores < 1){

		for (int i =1; i<= cantidadJugadores; i++){
			Vector <Jugador*> *jugador;
			jugador->set(i,jugadores->getJugador(i));
			jugador->get(i)->robarCarta();
		}
	}
	{
		//prueba turno
		Jugador* jugador1 = jugadores->getJugador(1);

		//aca roba muchas para simular que ya tiene un mazo, pero si no agarra una sola en el turno
		jugador1->robarCarta();
		jugador1->robarCarta();
		jugador1->robarCarta();

		Lista<Carta*>* cartas1 = jugador1->getCartas();
		bool juegaCarta = consola->tomaDecision("Desea jugar una carta?");
		if (juegaCarta){
			int posicionCarta = consola->seleccionarCarta(cartas1);
			jugador1->jugarCarta(posicionCarta);
		}
		cout<<"Se juega la carta y sigue el turno"<<endl;

		//para chequear que se haya borrado la carta
		//consola->mostrarCartas(cartas1);

		//TESOROS MINA
		if(jugador1->quedanTesorosMina()){
			bool usaTesoroMina = consola->tomaDecision("Desea colocar un tesoro mina?");
			if(usaTesoroMina){
				TesoroMina* tesoroMina;
				tesoroMina = jugador1->getTesoroMinaDisponible();
				Vector<int>* posicion = consola->pedirPosicion();
				//primero chequear si hay fichas de otros jugadores
				Casillero* casilleroOcupado = tableroGeneral->chequearPosicion(jugador1->getNumeroJugador(), posicion);
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
				} else {
					tesoroMina->setPosicion(posicion);
					jugador1->getTablero()->setCasillero(posicion, TESORO_MINA, jugador1->getNumeroJugador());
				}
				tableroGeneral->actualizarTablero();
				//para probar a ver si se deshabilito la casilla
				consola->imprimirTablero(tableroGeneral->getTablero());
				delete posicion;
			}
		}
	}

	delete tableroGeneral;
	delete jugadores;
	delete consola;
	return 0;
}



