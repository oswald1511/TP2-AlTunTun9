#ifndef CONSOLA_H_
#define CONSOLA_H_

#include <iostream>
#include <string>
#include "Vector.h"

class Consola {

private:
	Vector<int>* dimensionesTablero;

	/*
	* pre: recibe el vector posicion
	* post: valida que la posicion ingresada se encuentre dentro de las dimensiones del tablero
	*/
	void validarPosicion(Vector<int>* posicion);

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

	/*
	 * pre:-
	 * pos:le da la bienvenida a los usuarios al juego
	 */
	void bienvenida();

	/*
	 * pre:que exista el tablero
	 * pos:imprime el tablero seleccionado por la consola
	 */
	void imprimirTablero();

	/*
	 * pre:que el jugador tenga cartas
	 * pos:muestra por pantalla todas las cartas que tenga el jugador
	 */
	void mostrarCartas();

};

#endif /* CONSOLA_H_ */
