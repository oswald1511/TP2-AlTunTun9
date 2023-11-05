#include "Jugador.h"
#include "Consola.h"
#include "Tesoro.h"

Jugador::Jugador(int cantidadTesoros){
	this->tesoros = new Lista<Tesoro *>();
	for(int i = 0; i < cantidadTesoros; i++){
		this->tesoros->agregar(new Tesoro());
	}
	this->cartas = new Lista<Carta *>();
}

Jugador::~Jugador() {
	for(unsigned int i = 1; i <= this->tesoros->contarElementos(); i++){
		delete this->tesoros->obtener(i);
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

