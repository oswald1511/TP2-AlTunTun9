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
	 * pre:-
	 * pos:crea el objeto jugador con la cantidad de tesoros pedida
	 */
	Jugador(int cantidadTesoros);

	/*
	 * pre:que exista
	 * pos:-
	 */
	virtual ~Jugador();

	/*
	 * pre:que la posicion este dentro del tablero
	 * pos:pone un espia en la posicion dada
	 */
	void ponerEspia(Vector<int> * posicion);

	/*
	 * pre:que a donde se mueva al tesoro sea una posicion valida
	 * pos:mueve el tesoro a la posicion nueva
	 */
	void moverTesoro(Vector<int> * posicionActual, Vector<int> * posicionNueva);

	/*
	 * pre:que el jugador no tenga la cantidad maxima de cartas
	 * pos:le da una carta
	 */
	void robarCarta();

	/*
	 * pre:que tenga cartas el jugador
	 * pos:juega la carta seleccionada
	 */
	void jugarCarta(string nombreCarta);
};

#endif /* JUGADOR_H_ */
