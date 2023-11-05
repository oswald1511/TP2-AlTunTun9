#include "Jugador.h"
#include "Consola.h"
#include "Tesoro.h"

Jugador::Jugador(int cantidadTesoros){
	this->tesoros = new Lista<Tesoro *>();
	for(int i = 0; i < cantidadTesoros ; i++){
		this->tesoros->agregar(new Tesoro());
	}
	this->cartas = new Lista<Carta *>();
}

Jugador::~Jugador() {
	this->tesoros->iniciarCursor();
	while(this->tesoros->avanzarCursor()){
		delete this->tesoros->obtenerCursor();
	}
	delete this->tesoros;
	delete this->cartas;
}

void Jugador::ponerEspia(Vector<int> * posicion){

}

void Jugador::moverTesoro(Vector<int> * posicionActual, Vector<int> * posicionNueva){

}

void Jugador::robarCarta(){

}

void Jugador::jugarCarta(std::string nombreCarta){

}

Lista<Tesoro*> * Jugador::getTesoros(){
	return this->tesoros;
}

