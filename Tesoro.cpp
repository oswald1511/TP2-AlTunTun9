#include "Tesoro.h"

Tesoro::Tesoro(){
	this->posicion = NULL;
}

Tesoro::Tesoro(Vector<int> * posicion){
	this->posicion = posicion;
}

Tesoro::~Tesoro() {
	delete this->posicion;
}

Vector<int> * Tesoro::getPosicion(){
	return this->posicion;
}

void Tesoro::setPosicion(Vector<int> * posicion){
	this->posicion = posicion;
}
