#include "Jugadores.h"

Jugadores::Jugadores(int cantidadJugadores, int cantidadTesoros) {
	this->cantidadJugadores = cantidadJugadores;
	this->jugadores = new Lista<Jugador *>();
	for(int i = 0; i < cantidadJugadores; i++){
		this->jugadores->agregar(new Jugador(cantidadTesoros));
	}
}

Jugadores::~Jugadores() {
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		delete this->jugadores->obtenerCursor();
	}
	delete this->jugadores;
}

void Jugadores::inicializarTesoros(Tablero* tablero){
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		Jugador * jugador = this->jugadores->obtenerCursor();
		Lista<Tesoro*> * tesoros = jugador->getTesoros();
		tesoros->iniciarCursor();
		while(tesoros->avanzarCursor()){
			Vector<int>* posicion = tablero->getPosicionAleatoria();
			tesoros->obtenerCursor()->setPosicion(posicion);
			tablero->setCasillero(posicion, 'T');
		}
	}
}

void Jugadores::eliminarJugador(){

}


