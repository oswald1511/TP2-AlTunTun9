#include "Casillero.h"

Casillero::Casillero(Vector<int> * posicion) {
	this->posicion = posicion;
	this->ficha = '-';
}

Casillero::~Casillero() {
	delete this->posicion;
}

Vector<int> * Casillero::getPosicion(){
	return this->posicion;
}

//hay que ver como hacer para que este deshabilitada por 5 turnos y despues se habilite
void Casillero::deshabilitar(){
	this->ficha = 'X';
}

//y esta seria invocada por deshabilitar cuando toque volverla a habilitar.
//hay que ver que hace o si no hace falta capaz con setFicha estamos
void Casillero::habilitar(){
}

void Casillero::setFicha(char ficha){
	this->ficha = ficha;
}

char Casillero::getFicha(){
	return this->ficha;
}

