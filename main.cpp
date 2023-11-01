#include <iostream>
#include "Consola.h"

int main(){

	Consola *consola = new Consola();
	//consola->bienvenida();
	consola->pedirTamanioTablero();
	consola->pedirPosicion();


	delete consola;
	return 0;
}



