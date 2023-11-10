#ifndef TESOROMINA_H_
#define TESOROMINA_H_
#include <cstdlib>
#include "Vector.h"

class TesoroMina {
private:
	Vector<int> * posicion;
public:

	/*
	 * pre: -
	 * post: crea el tesoro mina sin posicion
	 */
	TesoroMina();

	/*
	 * pre: -
	 * post: elimina el puntero a vector posicion
	 */
	virtual ~TesoroMina();

	/*
	 * pre: recibe vector posicion
	 * post: establece la posicion del tesoro mina
	 */
	void setPosicion(Vector<int>* posicion);

	/*
	 * pre:
	 * post: devuelve la posicion del tesoro mina
	 */
	Vector<int>* getPosicion();



};

#endif /* TESOROMINA_H_ */
