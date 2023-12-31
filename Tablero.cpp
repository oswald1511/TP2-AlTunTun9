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
			}
			fila->agregar(columna);
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

Lista<Lista<Lista<Casillero *>*>*>* Tablero::getTablero(){
	return this->tablero;
}

Casillero * Tablero::getCasillero(Vector<int> * posicion){
	return this->tablero->obtener(posicion->get(1))->obtener(posicion->get(2))->obtener(posicion->get(3));
}

char Tablero::getFicha(Vector<int> * posicion){
	Casillero* casillero = this->getCasillero(posicion);
	return casillero->getFicha();
}

void Tablero::setCasillero(Vector<int> * posicion, char ficha, int numeroJugador){
	this->getCasillero(posicion)->setFicha(ficha);
	this->getCasillero(posicion)->setJugador(numeroJugador);
}

void Tablero::setCasillero(Casillero* casillero){
	Vector<int>* posicion = casillero->getPosicion();
	char ficha = casillero->getFicha();
	int numeroJugador = casillero->getJugador();
	this->setCasillero(posicion, ficha, numeroJugador);
}

Vector<int>* Tablero::getPosicionAleatoria(){
	Vector<int>* posicion = new Vector<int>(3);
	for(int i=1; i <= 3; i++){
		int random = rand() % (this->dimensiones->get(i));
		posicion->set(i, random + 1);
	}
	return posicion;
}

Vector<int> * Tablero::validarMovimiento(Vector<int>* posicion, Vector<int>* direccion){

	// Validar el movimiento dentro del tablero
	if (posicion->get(1) + direccion->get(1) > 0 && posicion->get(1) + direccion->get(1) <= this->dimensiones->get(1) &&
	posicion->get(2) + direccion->get(2) > 0 && posicion->get(2) + direccion->get(2) <= this->dimensiones->get(2) &&
	posicion->get(3) + direccion->get(3) > 0 && posicion->get(3) + direccion->get(3) <= this->dimensiones->get(3)) {

	    posicion->set(1,posicion->get(1)+direccion->get(1));
	    posicion->set(2,posicion->get(2)+direccion->get(2));
	    posicion->set(3,posicion->get(3)+direccion->get(3));
	}
	else{
		throw "Movimiento no válido.";
	}
	return posicion;
}

int Tablero::buscarIndiceDeTesoro(Lista<Tesoro*>* tesoros,Vector<int>* posicion){

	int indice;
	for(unsigned int i = 1; i <= tesoros->contarElementos(); i++){

		if(posicion->esIgual(tesoros->obtener(i)->getPosicion(),posicion)){
			indice = i;
		}
	}
	return indice;
}

Vector<int>* Tablero::getDimensiones(){

	return this->dimensiones;
}

