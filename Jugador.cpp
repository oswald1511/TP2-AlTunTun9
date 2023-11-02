#include "Jugador.h"

void Jugador::validarIndice(unsigned int indice){

	if(indice < 1){
		throw "El indice debe ser igual o mayor a 1";
	}
	if(indice > ){
		throw "El indice debe ser igual o menor a longitud";
	}
}
	/*
	 * pre:-
	 * pos:crea el objeto jugador con la cantidad de tesoros pedida
	 */
Jugador::Jugador(int cantidadTesoros){


}

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
