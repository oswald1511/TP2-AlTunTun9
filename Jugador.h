#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include "Lista.h"
#include "Tesoro.h"
#include "Carta.h"
#include "Vector.h"
#include "Tablero.h"
#include "Constantes.h"

class Jugador {
private:

	Lista<Tesoro *> * tesoros;
	Lista<Carta *> * cartas;
	Tablero* tablero;
	unsigned int cantidadMaximaCartas;

public:

	/*
	 * pre: recibe la cantidad de tesoros indicada por el usuario
	 * post: crea la lista de tesoros y de cartas
	 */
	Jugador(Vector<int>* dimensionesTablero, int cantidadTesoros);

	/*
	 * pre: -
	 * post: elimina la memoria dinamica utilizada
	 */
	virtual ~Jugador();

	/*
	 * pre: recibe una posicion dentro de los limites del tablero
	 * post: coloca el espia verificando si la casilla esta habilitada y si hay tesoros contrarios
	 */
	void ponerEspia(Vector<int> * posicion);

	/*
	 * pre: recibe posiciones dentro del tablero
	 * post: verifica que las posiciones sean validas y mueve el tesoro a la nueva posicion indicada
	 */
	void moverTesoro(Vector<int> * posicionActual, Vector<int> * posicionNueva);

	/*
	 * pre: -
	 * post: el jugador roba una carta aleatoria del mazo
	 */
	void robarCarta();

	/*
	 * pre: el jugador selecciona que carta jugar de su mazo de cartas
	 * post: se juega la carta segun el tipo que sea
	 */
	void jugarCarta(nombreCarta nombreCarta);

	/*
	 * pre: -
	 * post: coloca los tesoros de cada jugador en posiciones aleatorias del tablero
	 */
	void inicializarTesoros();

	/*
	 * pre: -
	 * post: devuelve la lista de tesoros
	 */
	Lista<Tesoro*> * getTesoros();

	/*
	 * pre: -
	 * post: devuelve la lista de cartas
	 */
	Lista<Carta*> * getCartas();

	/*
	 * pre: -
	 * post: devuelve el tablero del jugador
	 */
	Tablero * getTablero();
};

#endif /* JUGADOR_H_ */
