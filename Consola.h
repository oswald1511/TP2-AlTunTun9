#ifndef CONSOLA_H_
#define CONSOLA_H_
#include <iostream>
#include "Vector.h"

class Consola {
public:
	Consola();
	virtual ~Consola();

	/*
	 * pre: -
	 * post: devuelve un vector con las medidas del tablero
	 */
	Vector<int>* pedirTamanioTablero();

	/*
	 * pre: -
	 * post: devuelve un vector posicion segun los datos ingresados por consola
	 */
	Vector<int>* pedirPosicion();

	/*
	 * pre: -
	 * post: devuelve la cantidad de jugadores que el usuario ingrese
	 */
	int pedirCantidadJugadores();

	/*
	 * pre: -
	 * post: devuelve la cantidad de tesoros que el usuario ingrese
	 */
	int pedirCantidadTesoros();

	/*
		 * pre: -
		 * post: deja la terminal de consolo en blanco
		 */
	void limpiarPantalla();

};

#endif /* CONSOLA_H_ */
