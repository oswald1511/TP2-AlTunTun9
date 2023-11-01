#ifndef TESORO_H_
#define TESORO_H_

#include "Vector.h"

class Tesoro {
private:
	Vector<int> * posicion;
public:
	Tesoro(int x, int y, int z);
	virtual ~Tesoro();
	Vector<int> * getPosicion();
	void setPosicion(Vector<int> * posicion);
};

#endif /* TESORO_H_ */
