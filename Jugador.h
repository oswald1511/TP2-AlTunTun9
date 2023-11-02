#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>
#include "Lista.h"
#include "Tesoro.h"
#include "Carta.h"
#include "Vector.h"

using namespace std;


class Jugador {
private:
	Lista<Tesoro*> * tesoros;
	Lista<Carta*> * cartas;

	/*
	 * pre: recibe un valor
	 * post: valida que este entre 1 y longitud, si no tira error
	 */
	void validarIndice(unsigned int indice);

public:
	/*
		 * pre: recibe la cantidad de tesoros indicada por el usuario
		 * post: crea la lista de tesoros y de cartas
		 */
		Jugador(int cantidadTesoros);

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
		void jugarCarta(std::string nombreCarta);
};

#endif /* JUGADOR_H_ */
