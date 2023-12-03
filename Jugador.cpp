#include "Jugador.h"

Jugador::Jugador(Vector<int>* dimensionesTablero, int cantidadTesoros, int numeroJugador){
	this->tesoros = new Lista<Tesoro *>();
	for(int i = 0; i < cantidadTesoros ; i++){
		this->tesoros->agregar(new Tesoro());
	}
	this->cartas = new Lista<Carta *>();
	this->espias = new Lista<Vector<int>*>();
	this->cantidadMaximaCartas = CANTIDAD_MAXIMA_CARTAS;
	this->tablero = new Tablero(dimensionesTablero);
	this->tesorosMina = new Lista<TesoroMina*>();
	for(int i = 0; i < CANTIDAD_TESOROS_MINA ; i++){
			this->tesorosMina->agregar(new TesoroMina());
	}
	this->numeroJugador = numeroJugador;
}

Jugador::~Jugador() {
	this->tesoros->iniciarCursor();
	while(this->tesoros->avanzarCursor()){
		delete this->tesoros->obtenerCursor();
	}
	this->cartas->iniciarCursor();
	while(this->cartas->avanzarCursor()){
		delete this->cartas->obtenerCursor();
	}
	this->tesorosMina->iniciarCursor();
	while(this->tesorosMina->avanzarCursor()){
		delete this->tesorosMina->obtenerCursor();
	}
	delete this->tesoros;
	delete this->tesorosMina;
	delete this->cartas;
	delete this->tablero;
}

int Jugador::getNumeroJugador(){
	return this->numeroJugador;
}

void Jugador::ponerEspia(Vector<int> * posicion){
	this->espias->agregar(posicion);
}

Vector<int>* Jugador::getEspia(int numeroDeEspia){
	return this->espias->obtener(numeroDeEspia);
}

void Jugador::moverTesoro(Vector<int> * posicionActual, Vector<int> * posicionNueva){

}

void Jugador::robarCarta(){
	if(this->cartas->contarElementos() == this->cantidadMaximaCartas){
		throw std::string("El jugador no puede robar mas cartas");
	}
	this->cartas->agregar(new Carta());
}

void Jugador::jugarCarta(int posicion){
	//por ahora solo la elimino de la lista para probar el flujo
	Carta* carta = this->cartas->obtener(posicion);
	carta->jugarCarta();
	delete carta;
	this->cartas->remover(posicion);
}

void Jugador::inicializarTesoros(){
	this->tesoros->iniciarCursor();
	while(tesoros->avanzarCursor()){
		Vector<int>* posicion = this->tablero->getPosicionAleatoria();
		tesoros->obtenerCursor()->setPosicion(posicion);
		this->tablero->setCasillero(posicion, TESORO, this->numeroJugador);
	}
}

Lista<Tesoro*> * Jugador::getTesoros(){
	return this->tesoros;
}

Lista<Carta*> * Jugador::getCartas(){
	return this->cartas;
}

Tablero* Jugador::getTablero(){
	return this->tablero;
}

Lista<TesoroMina*> * Jugador::getTesorosMina(){
	return this->tesorosMina;
}

bool Jugador::quedanTesorosMina(){
	bool quedanTesorosMina = false;
	this->tesorosMina->iniciarCursor();
	while(this->tesorosMina->avanzarCursor() && !quedanTesorosMina){
		TesoroMina* tesoroMina = this->tesorosMina->obtenerCursor();
		if(!tesoroMina->getPosicion()){
			quedanTesorosMina = true;
		}
	}
	return quedanTesorosMina;
}

TesoroMina* Jugador::getTesoroMinaDisponible(){
	bool fin = false;
	TesoroMina* tesoroMina;
	this->tesorosMina->iniciarCursor();
	while(this->tesorosMina->avanzarCursor() && !fin){
		tesoroMina = this->tesorosMina->obtenerCursor();
		if(!tesoroMina->getPosicion()){
			fin = true;
		}
	}
	return tesoroMina;
}

