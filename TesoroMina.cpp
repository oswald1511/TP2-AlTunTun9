#include "TesoroMina.h"
#include "Vector.h"

TesoroMina::TesoroMina(Vector<int> *posicion){

	this->posicion = new Vector<int>(3);
	this->posicion->set(1, posicion->get(1));
	this->posicion->set(2, posicion->get(2));
	this->posicion->set(3, posicion->get(3));
}

TesoroMina::~TesoroMina() {
	// TODO Auto-generated destructor stub
}

