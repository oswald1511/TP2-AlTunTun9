
#include "Consola.h"
#include "Tablero.h"

using namespace std;

int main(){

	Consola *consola = new Consola();
	Tablero *tablero = new Tablero(consola->pedirTamanioTablero());
	//consola->bienvenida();

	Vector<int>* posicion = consola->pedirPosicion();
	cout << "El casillero seleccionado tiene la ficha: ";
	cout << tablero->getCasillero(posicion)->getFicha() << endl;

	delete posicion;
	delete tablero;
	delete consola;
	return 0;
}



