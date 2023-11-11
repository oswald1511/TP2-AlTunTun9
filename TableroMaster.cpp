#include "TableroMaster.h"
#include "Tablero.h"

TableroMaster::TableroMaster(Vector<int>* dimensiones, Jugadores* jugadores) {
	this->tablero = new Tablero(dimensiones);
	this->jugadores = jugadores->getJuagdores();
	this->actualizarTablero();
}

TableroMaster::~TableroMaster() {
	delete this->tablero;
}

Tablero* TableroMaster::getTablero(){
	return this->tablero;
}

Casillero* TableroMaster::chequearPosicion (int jugadorActual, Vector<int>* posicion){
	Casillero* casilleroOcupado = NULL;
	Casillero* casillero = this->tablero->getCasillero(posicion);
	if(casillero->getJugador() != jugadorActual && casillero->getFicha() != VACIO){
		casilleroOcupado = casillero;
	}
	return casilleroOcupado;
}

void TableroMaster::actualizarTablero(){
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		Jugador* jugador = this->jugadores->obtenerCursor();
		Tablero* tablero = jugador->getTablero();
		Lista<Lista<Lista<Casillero *>*>*>* casilleros = tablero->getTablero();
		casilleros->iniciarCursor();
		while(casilleros->avanzarCursor()){
			Lista<Lista<Casillero*>*>* fila = casilleros->obtenerCursor();
			fila->iniciarCursor();
			while(fila->avanzarCursor()){
				Lista<Casillero*>* columna = fila->obtenerCursor();
				columna->iniciarCursor();
				while(columna->avanzarCursor()){
					Casillero* casillero = columna->obtenerCursor();
					if(casillero->getFicha() != VACIO){
						this->tablero->setCasillero(casillero);
					}
				}
			}
		}
	}
}

void TableroMaster::setCasillero(Casillero* casillero){
	this->tablero->setCasillero(casillero);
}

void TableroMaster::deshabilitarCasillero(Vector<int>* posicion){
	this->tablero->getCasillero(posicion)->deshabilitar(PODER_MINA);
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		this->jugadores->obtenerCursor()->getTablero()->getCasillero(posicion)->deshabilitar(PODER_MINA);
	}
}

