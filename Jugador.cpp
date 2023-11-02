#include "Jugador.h"
#include "Consola.h"
#include "Tesoro.h"

void Jugador::validarIndice(unsigned int indice){

	if(indice < 1){
		throw "El indice debe ser igual o mayor a 1";
	}
	if(indice > 5 ){
		throw "El indice debe ser igual o menor a longitud";
	}
}

Jugador::Jugador(int cantidadTesoros){

	this->tesoros = new Lista<Tesoro *>();
	for(int i = 0; i < cantidadTesoros; i++){
		this->tesoros->agregar(new Tesoro());
	}
	this->cartas = new Lista<Carta *>();
}


Jugador::~Jugador() {
	for(int i = 1; i <= this->tesoros->contarElementos(); i++){
		delete this->tesoros->obtener(i);
	}
	delete this->tesoros;
	delete this->cartas;
}




void ponerEspia(Vector<int> * posicion){

}


void moverTesoro(Vector<int> * posicionActual, Vector<int> * posicionNueva){

}


void robarCarta(){

}

void jugarCarta(string nombreCarta){

}
