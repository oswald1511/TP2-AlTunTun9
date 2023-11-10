#include "Consola.h"
#include "Jugadores.h"
//#include "ExportarBmp.h"
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
	//ExportarBmp* bmp= new ExportarBmp(cantidadJugadores, dimensionesTablero);

	//consola->bienvenida();
	Jugadores* jugadores = new Jugadores(dimensionesTablero, cantidadJugadores, cantidadTesoros);
	TableroMaster* tableroGeneral = new TableroMaster(dimensionesTablero, jugadores);
	consola->imprimirTablero(tableroGeneral->getTablero());

	//ejemplo para ver si se agarra bien las cartas
	/*
	for(int i = 1; i <= 3; i++){
		Jugador* jugador = jugadores->getJugador(i);
		for(int j = 0; j < 3; j++){
			jugador->robarCarta();
		}
	//	Lista<Carta*>* cartas = jugador->getCartas();
	//	cout << "Jugador " << i << ":" << endl;
		//consola->mostrarCartas(cartas);
	}
	*/

	//ejemplo de imprimir el tablero del jugador 1
	//consola->imprimirTablero(jugador1->getTablero());




	/*
	Vector<int>* posicion = consola->pedirPosicion();
	delete posicion;
	*/

	{
		//prueba turno
		Jugador* jugador1 = jugadores->getJugador(1);
		jugador1->robarCarta();
		jugador1->robarCarta();
		jugador1->robarCarta();
		Lista<Carta*>* cartas1 = jugador1->getCartas();
		//consola->mostrarCartas(cartas1);
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
				cout<<jugador1->getNumeroJugador()<<endl;
				Casillero* casilleroOcupado = tableroGeneral->chequearPosicion(jugador1->getNumeroJugador(), posicion);
				if(casilleroOcupado){
					if(casilleroOcupado->getFicha() == TESORO){
						cout << "El tesoro mina encontro un tesoro! Sera eliminado" << endl;
					}
				}
				tesoroMina->setPosicion(posicion);
				jugador1->getTablero()->setCasillero(posicion, TESORO_MINA, jugador1->getNumeroJugador());
				consola->imprimirTablero(jugador1->getTablero());
				delete posicion;
			}
		}
	}

	delete tableroGeneral;
	delete jugadores;
	delete consola;
	return 0;
}



