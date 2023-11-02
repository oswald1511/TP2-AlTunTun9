#ifndef TESORO_H_
#define TESORO_H_

#include <cstddef>
#include "Vector.h"

class Tesoro {
private:
	Vector<int> * posicion;

public:

	/*
	 * pre: -
	 * post: crea un tesoro sin posicion
	 */
	Tesoro();

	/*
	 * pre: -
	 * post: crea un tesoro en una posicion indicada
	 */
	Tesoro(Vector<int> * posicion);

	/*
	 * pre: -
	 * post: emilina toda la memoria dinamica utilizada
	 */
	virtual ~Tesoro();

	/*
	 * pre: -
	 * post: devuelve la posicion del tesoro
	 */
	Vector<int> * getPosicion();

	/*
	 * pre: recibe una posicion valida
	 * post: establece la posicion del tesoro
	 */
	void setPosicion(Vector<int> * posicion);
};

#endif /* TESORO_H_ */
