
#include "Consola.h"
#include "Jugadores.h"

using namespace std;

int main(){
	srand(time(NULL));
	Consola* consola = new Consola();
	Vector<int>* dimensionesTablero = consola->pedirTamanioTablero();
	int cantidadJugadores = consola->pedirCantidadJugadores();
	int cantidadTesoros = consola->pedirCantidadTesoros();
	//consola->bienvenida();
	Jugadores* jugadores = new Jugadores(dimensionesTablero, cantidadJugadores, cantidadTesoros);

	//ejemplo para ver si se agarra bien las cartas
	/*
	for(int i = 1; i <= 3; i++){
		Jugador* jugador = jugadores->getJugador(i);
		for(int j = 0; j < 3; j++){
			jugador->robarCarta();
		}
		Lista<Carta*>* cartas = jugador->getCartas();
		cout << "Jugador " << i << ":" << endl;
		consola->mostrarCartas(cartas);
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
		consola->mostrarCartas(cartas1);
	}


	delete jugadores;
	delete consola;
	return 0;
}



