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

void Jugadores::eliminarJugador(){

}


