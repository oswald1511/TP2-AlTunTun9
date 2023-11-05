#ifndef TABLERO_H_
#define TABLERO_H_
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
	 * pre: recibe la posicion dentro de los limites del tablero y la ficha a establecer
	 * post: establece la ficha en el casillero en la posicion indicada
	 */
	void setCasillero(Vector<int> * posicion, char ficha);

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

};

#endif /* TABLERO_H_ */
