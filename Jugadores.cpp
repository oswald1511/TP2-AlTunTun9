#include "Jugadores.h"

Jugadores::Jugadores(Vector<int>* dimensionesTablero, int cantidadJugadores, int cantidadTesoros) {
	this->cantidadJugadores = cantidadJugadores;
	this->jugadores = new Lista<Jugador *>();
	for(int i = 0; i < cantidadJugadores; i++){
		this->jugadores->agregar(new Jugador(dimensionesTablero, cantidadTesoros));
	}
	this->inicializarTesoros();
}

Jugadores::~Jugadores() {
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		delete this->jugadores->obtenerCursor();
	}
	delete this->jugadores;
}

void Jugadores::inicializarTesoros(){
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		Jugador * jugador = this->jugadores->obtenerCursor();
		jugador->inicializarTesoros();
	}
}

Jugador* Jugadores::getJugador(unsigned int numeroJugador){
	return this->jugadores->obtener(numeroJugador);
}

void Jugadores::eliminarJugador(){

}


