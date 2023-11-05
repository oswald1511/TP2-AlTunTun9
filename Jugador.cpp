#include "Jugador.h"

Jugador::Jugador(Vector<int>* dimensionesTablero, int cantidadTesoros){
	this->tesoros = new Lista<Tesoro *>();
	for(int i = 0; i < cantidadTesoros ; i++){
		this->tesoros->agregar(new Tesoro());
	}
	this->cartas = new Lista<Carta *>();
	this->cantidadMaximaCartas = CANTIDAD_MAXIMA_CARTAS;
	this->tablero = new Tablero(dimensionesTablero);
}

Jugador::~Jugador() {
	this->tesoros->iniciarCursor();
	while(this->tesoros->avanzarCursor()){
		delete this->tesoros->obtenerCursor();
	}
	this->cartas->iniciarCursor();
	while(this->cartas->avanzarCursor()){
		delete this->cartas->obtenerCursor();
	}
	delete this->tesoros;
	delete this->cartas;
	delete this->tablero;
}

void Jugador::ponerEspia(Vector<int> * posicion){

}

void Jugador::moverTesoro(Vector<int> * posicionActual, Vector<int> * posicionNueva){

}

void Jugador::robarCarta(){
	if(this->cartas->contarElementos() == this->cantidadMaximaCartas){
		throw "El jugador no puede robar mas cartas";
	}
	this->cartas->agregar(new Carta());
}

void Jugador::jugarCarta(nombreCarta nombreCarta){

}

void Jugador::inicializarTesoros(){
	this->tesoros->iniciarCursor();
	while(tesoros->avanzarCursor()){
		Vector<int>* posicion = this->tablero->getPosicionAleatoria();
		tesoros->obtenerCursor()->setPosicion(posicion);
		this->tablero->setCasillero(posicion, 'T');
	}
}

Lista<Tesoro*> * Jugador::getTesoros(){
	return this->tesoros;
}

Lista<Carta*> * Jugador::getCartas(){
	return this->cartas;
}

Tablero* Jugador::getTablero(){
	return this->tablero;
}

