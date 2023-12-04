#ifndef CONSOLA_H_
#define CONSOLA_H_

#include <iostream>
#include <string>
#include <math.h>
#include "Vector.h"
#include "Tablero.h"
#include "Lista.h"
#include "Carta.h"
#include "Jugador.h"

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

	/* esta es para probar nomas
	 * pre: -
	 * post: imprime una posicion por pantalla
	 */
	void imprimirPosicion(Vector<int>* posicion);

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
	void imprimirTablero(Tablero* tablero);

	/*
	 * pre:que el jugador tenga cartas
	 * pos:muestra por pantalla todas las cartas que tenga el jugador
	 */
	void mostrarCartas(Lista<Carta*> * cartas);

	/*
	 * pre:
	 * pos:devuelve las dimensiones
	 */
	Vector<int>* getDimensiones();

	/*
	 * pre: recibe la pregunta que hay que hacerle al usuario (preguntas por si o no)
	 * pos: devuelve true si dice que si y false si dice que no
	 */
	bool tomaDecision(std::string consulta);

	/*
	 * pre: recibe la lista de cartas del jugador
	 * pos: devuelve la posicion de la lista en la que se encuentra la carta elegida
	 */
	int seleccionarCarta(Lista<Carta*> * cartas);

	/*
	 * pre:
	 * pos: da un mensaje de despedida al usuario
	 */
	void despedida();

	/*
	 * pre:recibe la lista de jugadores y el jugador
	 *
	 */
	int mostrarTesoros(Jugador* jugador);

	Vector<int>* elegirDireccion();

	void ganador(int jugador);

};

#endif /* CONSOLA_H_ */
