#include "Casillero.h"

Casillero::Casillero(Vector<int> *posicion) {
    this->posicion = posicion;
    this->ficha = '-';
    this->turnosDeshabilitado = 0; // Inicializa el contador de turnos deshabilitado en 0
}

Casillero::~Casillero() {
    delete this->posicion;
}

Vector<int> *Casillero::getPosicion() {
    return this->posicion;
}

void Casillero::deshabilitar( int turnos) {
    this->ficha = 'X';
    this->turnosDeshabilitado = turnos ; // Deshabilita el casillero por un número de turnos 
}

void Casillero::habilitar() {
    if (this->ficha == 'X' && this->turnosDeshabilitado > 0) {
        this->turnosDeshabilitado--;

        if (this->turnosDeshabilitado == 0) {
            this->ficha = '-';
        }
    }
}

void Casillero::setFicha(char ficha) {
    this->ficha = ficha;
}

char Casillero::getFicha() {
    return this->ficha;
}


