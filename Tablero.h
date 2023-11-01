#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casillero.h"
#include "Vector.h"

class Tablero {
private:
	Lista<Lista<Lista<Casillero *>*>*>* tablero;
	int x;
	int y;
	int z;

public:
	Tablero(int x, int y, int z);
	virtual ~Tablero();
	Casillero * getCasillero(Vector<int> * posicion);
};

#endif /* TABLERO_H_ */
