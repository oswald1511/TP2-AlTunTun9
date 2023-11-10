#include "TesoroMina.h"


TesoroMina::TesoroMina(){
	this->posicion = NULL;
}

TesoroMina::~TesoroMina() {
	delete this->posicion;
}

void TesoroMina::setPosicion(Vector<int> *posicion){
	this->posicion = new Vector<int>(3);
	this->posicion->set(1, posicion->get(1));
	this->posicion->set(2, posicion->get(2));
	this->posicion->set(3, posicion->get(3));
}

Vector<int>* TesoroMina::getPosicion(){
	return this->posicion;
}
