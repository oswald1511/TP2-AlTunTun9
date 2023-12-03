#ifndef TABLERO_H_
#define TABLERO_H_
#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include "Casillero.h"
#include "Vector.h"

class Tablero {
private:
	Lista<Lista<Lista<Casillero *>*>*>* tablero;
	Vector<int>* dimensiones;

public:

	/*
	 * pre: recibe el vector dimensiones de tablero
	 * post: crea el tablero (lista de lista de lista de casilleros) con las dimensiones indicadas
	 */
	Tablero(Vector<int>* dimensiones);

	/*
	 * pre: -
	 * post: elimina toda la memoria de las listas creadas y finalmente el tablero entero
	 */
	virtual ~Tablero();

	/*
	 * pre: -
	 * post: devuelve la lista de lista de lista de casilleros
	 */
	Lista<Lista<Lista<Casillero *>*>*>* getTablero();

	/*
	 * pre: recibe el vector posicion dentro de los limites del tablero
	 * post: devuelve el puntero a casillero en la posicion indicada
	 */
	Casillero * getCasillero(Vector<int> * posicion);

	/*
	 * pre: recibe la posicion dentro de los limites del tablero, la ficha a establecer y el numero de jugador al que le pertenece
	 * post: establece la ficha en el casillero en la posicion indicada y a que jugador pertenece
	 */
	void setCasillero(Vector<int> * posicion, char ficha, int numeroJugador);

	/*
	 * pre: recibe el puntero a casillero
	 * post: establece el casillero
	 */
	void setCasillero(Casillero* casillero);

	/*
	 * pre: recibe la posicion dentro de los limites del tablero
	 * post: devuelve la ficha en el casillero de la posicion indicada
	 */
	char getFicha(Vector<int> * posicion);

	/*
	 * pre: -
	 * post: devuelve un vector posicion aleatoria dentro de los limites del tablero
	 */
	Vector<int>* getPosicionAleatoria();

	Vector<int> * validarMovimiento(Vector<int>* posicion, Vector<int>* direccion);

};

#endif /* TABLERO_H_ */
