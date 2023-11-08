#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "Vector.h"

class Casillero {
private:
	char ficha;
	Vector<int> * posicion;
	int turnosDeshabilitado;

public:

	/*
	 * pre: recibe el vector de la posicion en la que se encontrara el casillero
	 * post: crea el casillero en la posicion indicada
	 */
	Casillero(Vector<int> * posicion);

	/*
	 * pre: -
	 * post: elimina el casillero creado
	 */
	virtual ~Casillero();

	/*
	 * pre: -
	 * post: devuelve la posicion del casillero
	 */
	Vector<int> * getPosicion();

	/*
	 * pre: -
	 * post: deshabilita la casilla por X turnos
	 */
	void deshabilitar(int turnos);

	/*
	 * pre: -
	 * post: habilita la casilla
	 */
	void habilitar();

	/*
	 * pre: recibe el char ficha a setear
	 * post: estalece el valor de la ficha
	 */
	void setFicha(char ficha);

	/*
	 * pre: -
	 * post: devuelve el valor de la ficha
	 */
	char getFicha();
};

#endif /* CASILLERO_H_ */
