/*
 * TableroMaster.cpp
 *
 *  Created on: 10/11/2023
 *      Author: algo2
 */

#include "TableroMaster.h"

TableroMaster::TableroMaster(Vector<int>* dimensiones, Jugadores* jugadores) {
	this->tablero = new Tablero(dimensiones);
	this->jugadores = jugadores->getJuagdores();
	this->actualizarTesoros();

}

TableroMaster::~TableroMaster() {
	delete this->tablero;
	delete this->jugadores;
}

Tablero* TableroMaster::getTablero(){
	return this->tablero;
}

//no anda bien este todavia
Casillero* TableroMaster::chequearPosicion (int jugadorActual, Vector<int>* posicion){
	Casillero* casilleroOcupado = NULL;
	this->jugadores->iniciarCursor();
	bool fin = false;
	while(this->jugadores->avanzarCursor() && !fin){
		Jugador* jugador = this->jugadores->obtenerCursor();
		if(jugador->getNumeroJugador() != jugadorActual){
			if(jugador->getTablero()->getFicha(posicion) != VACIO){
				casilleroOcupado = jugador->getTablero()->getCasillero(posicion);
				fin = true;
				this->jugadores->iniciarCursor();
			}
		}
	}
	return casilleroOcupado;
}

void TableroMaster::actualizarTesoros (){
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		Jugador* jugador = this->jugadores->obtenerCursor();
		Lista<Tesoro*>* tesoros = jugador->getTesoros();
		tesoros->iniciarCursor();
		while(tesoros->avanzarCursor()){
			Vector<int>* posicion = tesoros->obtenerCursor()->getPosicion();
			this->tablero->setCasillero(posicion, TESORO, jugador->getNumeroJugador());
		}
	}
}


void TableroMaster::setCasillero(Casillero* casillero){
	this->tablero->setCasillero(casillero->getPosicion(), casillero->getFicha(), casillero->getJugador());
}

