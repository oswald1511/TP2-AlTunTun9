#ifndef TESOROMINA_H_
#define TESOROMINA_H_
#include "Vector.h"

class TesoroMina {
private:
	Vector<int> * posicion;
public:
	TesoroMina(Vector<int> *posicion);
	virtual ~TesoroMina();
	void stePosicion(Vector<int>* posicion);
};

#endif /* TESOROMINA_H_ */
