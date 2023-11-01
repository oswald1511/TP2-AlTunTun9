#include "Tablero.h"

Tablero::Tablero(Vector<int>* dimensiones) {
	this->dimensiones = dimensiones;
	this->tablero = new Lista<Lista<Lista<Casillero *>*>*>();
	for(int i=1; i <= this->dimensiones->get(1); i++) {
		Lista<Lista<Casillero *>*> * fila = new Lista<Lista<Casillero *>*>();
		for(int j=1; j <= this->dimensiones->get(2); j++) {
			Lista<Casillero *>* columna = new Lista<Casillero *>;
			for(int k=1; k <= this->dimensiones->get(3); k++) {
				Vector<int>* posicion = new Vector<int>(3);
				posicion->set(1, i);
				posicion->set(2, j);
				posicion->set(3, k);
				Casillero* casillero = new Casillero(posicion);
				columna->agregar(casillero);
				fila->agregar(columna);
			}
		}
		this->tablero->agregar(fila);
	}
}

Tablero::~Tablero() {
	this->tablero->iniciarCursor();
	while(this->tablero->avanzarCursor()){
		Lista<Lista<Casillero *>*>* fila = this->tablero->obtenerCursor();
		fila->iniciarCursor();
		while(fila->avanzarCursor()){
			Lista<Casillero *> * columna = fila->obtenerCursor();
			columna->iniciarCursor();
			while(columna->avanzarCursor()){
				delete columna->obtenerCursor();
			}
			delete columna;
		}
		delete fila;
	}
	delete this->tablero;
}

Casillero * Tablero::getCasillero(Vector<int> * posicion){
	return this->tablero->obtener(posicion->get(1))->obtener(posicion->get(2))->obtener(posicion->get(3));
}

char Tablero::getFicha(Vector<int> * posicion){
	Casillero* casillero = this->getCasillero(posicion);
	return casillero->getFicha();
}

void Tablero::setCasillero(Vector<int> * posicion, char ficha){
	this->getCasillero(posicion)->setFicha(ficha);
}

