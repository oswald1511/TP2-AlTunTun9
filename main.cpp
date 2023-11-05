
#include "Consola.h"
#include "Tablero.h"
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

	//ejemplo de imprimir el tablero del jugador 1
	consola->imprimirTablero(jugadores->getJugador(1)->getTablero());


	/*
	Vector<int>* posicion = consola->pedirPosicion();
	cout << "El casillero seleccionado tiene la ficha: ";
	cout << tablero->getCasillero(posicion)->getFicha() << endl;
	delete posicion;
	 */


	delete jugadores;
	delete consola;
	return 0;
}



