
#include "Consola.h"
#include "Tablero.h"
#include "Jugadores.h"

using namespace std;

int main(){
	srand(time(NULL));
	Consola* consola = new Consola();
	Tablero* tablero = new Tablero(consola->pedirTamanioTablero());
	//consola->bienvenida();
	Jugadores* jugadores = new Jugadores(consola->pedirCantidadJugadores(), consola->pedirCantidadTesoros());
	jugadores->inicializarTesoros(tablero);
	consola->imprimirTablero(tablero);


	/*
	Vector<int>* posicion = consola->pedirPosicion();
	cout << "El casillero seleccionado tiene la ficha: ";
	cout << tablero->getCasillero(posicion)->getFicha() << endl;
	delete posicion;
	 */


	delete jugadores;
	delete tablero;
	delete consola;
	return 0;
}



