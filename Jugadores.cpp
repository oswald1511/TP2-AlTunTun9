#include "Jugadores.h"

Jugadores::Jugadores(Vector<int>* dimensionesTablero, int cantidadJugadores, int cantidadTesoros) {
	this->cantidadJugadores = cantidadJugadores;
	this->jugadores = new Lista<Jugador *>();
	for(int i = 1; i <= cantidadJugadores; i++){
		this->jugadores->agregar(new Jugador(dimensionesTablero, cantidadTesoros, i));
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

int Jugadores::getCantidadJugadores(){
	return this->cantidadJugadores;
}

Jugador* Jugadores::getJugador(unsigned int numeroJugador){
	return this->jugadores->obtener(numeroJugador);
}

void Jugadores::eliminarJugador(){

}

Lista<Jugador*>* Jugadores::getJuagdores(){
	return this->jugadores;
}


