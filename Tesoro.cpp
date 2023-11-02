#include "Tesoro.h"

Tesoro::Tesoro(){
	this->posicion = new Vector<int>(3);
	for(int i = 0; i < 3; i++){
		this->posicion->set(i, 0);
	}
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
