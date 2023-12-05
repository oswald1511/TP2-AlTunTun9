#include "Jugadores.h"

Jugadores::Jugadores(Vector<int>* dimensionesTablero, int cantidadJugadores, int cantidadTesoros) {
	this->cantidadJugadores = cantidadJugadores;
	this->jugadores = new Lista<Jugador *>();
	for(int i = 1; i <= cantidadJugadores; i++){
		this->jugadores->agregar(new Jugador(dimensionesTablero, cantidadTesoros, i));

	}
	Tablero* tablero = new Tablero(this->getJugador(1)->getTablero()->getDimensiones());
	validarCantidadDeTesoros(cantidadTesoros, dimensionesTablero);
	this->inicializarTesoros(tablero);
	delete tablero;
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
		jugador->inicializarTesoros(tablero);
	}
}

int Jugadores::getCantidadJugadores(){
	return this->cantidadJugadores;
}

Jugador* Jugadores::getJugador(unsigned int numeroJugador){
	return this->jugadores->obtener(numeroJugador);
}

void Jugadores::eliminarJugador(int jugador){
	jugadores->obtener(jugador)->~Jugador();
	jugadores->remover(jugador);
	this->cantidadJugadores--;

}

Lista<Jugador*>* Jugadores::getJugadores(){
	return this->jugadores;
}

void Jugadores::validarCantidadDeTesoros(int cantidadTesoros, Vector<int>* dimensiones){

	if((dimensiones->get(1)*dimensiones->get(2)*dimensiones->get(3)) < cantidadTesoros*this->cantidadJugadores){
		throw "La cantidad de tesoros dada es mayor a la cantidad de casilleros disponibles.";
	}
}

