
#include "Carta.h"

Carta::Carta(){
	// Establece un tipo de carta aleatorio
	this->tipoCarta = static_cast<nombreCarta>(rand() % 6);
}

Carta::Carta(nombreCarta tipoCarta){
	this->tipoCarta = tipoCarta;
}

Carta::~Carta(){
}

nombreCarta Carta::getTipoCarta() {
    return this->tipoCarta;
}

void Carta::jugarCartaLadron(Jugador* jugadorActual, Jugadores* jugadores) {
    int cantidadJugadores = jugadores->obtenerCantidadTotalDeJugadores();
    if (cantidadJugadores > 1) {
        int jugadorAleatorio;
        do {
            jugadorAleatorio = rand() % cantidadJugadores;
        } while (jugadorAleatorio == jugadorActual->getNumeroJugador());

        Jugador* otroJugador = jugadores->obtenerJugadorPorNumero(jugadorAleatorio);

        if (otroJugador != nullptr && otroJugador->getCartas()->contarElementos() > 0) {
            Carta* cartaRobada = otroJugador->getCartas()->obtenerElementoAleatorio();
            jugadorActual->getCartas()->agregar(cartaRobada);
            otroJugador->getCartas()->eliminar(cartaRobada);
        }
    }
}

void Carta::jugarCartaSniper(Jugador* jugadorActual) {
    // Acción de la carta Sniper
    if (rand() % 20 == 0) { // Probabilidad de 5% (1 en 20)
        // Obtén la lista de tesoros del jugador actual.
        Lista<Tesoro*>* tesoros = jugadorActual->getTesoros();

        if (tesoros->contarElementos() > 0) {
            // Elige un tesoro al azar para eliminar.
            int indiceAleatorio = rand() % tesoros->contarElementos();
            Tesoro* tesoroAEliminar = tesoros->obtenerElementoEnPosicion(indiceAleatorio);

            // Elimina el tesoro del jugador.
            jugadorActual->getTablero()->removerTesoro(tesoroAEliminar);
            tesoros->eliminar(tesoroAEliminar);
        }
    }
}

std::string Carta::getNombreCarta(){
	std::string nombreCarta;
	switch(this->tipoCarta){
	case BLINDAJE:
		nombreCarta = "Blindaje";
		break;
	case RADAR:
		nombreCarta = "Radar";
		break;
	case PARTIR:
		nombreCarta = "Partir";
		break;
	case SNIPER:
		nombreCarta = "Sniper";
		break;
	case LADRON:
		nombreCarta = "Ladrón";
		break;
	case CARTA6:
		nombreCarta = "Carta6";
		break;
	default:
		break;
	}
	return nombreCarta;
}
}

