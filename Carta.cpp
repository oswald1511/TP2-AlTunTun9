
#include "Carta.h"

Carta::Carta(){
	//establece un tipo de carta aleatorio
	this->tipoCarta = static_cast<nombreCarta>(rand() % 6);
}

Carta::Carta(nombreCarta tipoCarta){
	this->tipoCarta = tipoCarta;
}

Carta::~Carta(){
}

void Carta::jugarCarta(Jugador * jugador){

	switch(this->tipoCarta){
		case(BLINDAJE):

			break;
		case(RADAR):

			break;
		case(PARTIR):

			break;
		case(LADRON):

			break;
		case(SNIPER):

			break;
		case(ROBAR):

			break;
		default:
			break;
		}
}

void Carta::jugarCartaSniper(Jugador* jugadorActual, Jugadores* jugadores) {
    int cantidadJugadores = jugadores->cantidadJugadores;
    
    if (cantidadJugadores > 1) {
        int jugadorAleatorio;
        do {
            jugadorAleatorio = rand() % cantidadJugadores;
        } while (jugadorAleatorio == jugadorActual->getNumeroJugador());

        Jugador* otroJugador = jugadores->getJugador(jugadorAleatorio);

        if (otroJugador != nullptr) {
            // Obtén la lista de tesoros del otro jugador.
            Lista<Tesoro*>* tesoros = otroJugador->getTesoros();

            if (tesoros->contarElementos() > 0) {
                // Elige al azar un tesoro del otro jugador para eliminar.
                int indiceAleatorio = rand() % tesoros->contarElementos();
                Tesoro* tesoroAEliminar = tesoros->obtener(indiceAleatorio);

                // Elimina el tesoro del otro jugador.
                otroJugador->getTablero()->removerTesoro(tesoroAEliminar);
                tesoros->eliminar(tesoroAEliminar);
            }
        }
    }
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

void Carta::jugarCartaPartirTesoro(Jugador* jugadorActual, Vector<int>* posicionNueva){

	Tesoro * tesoroPartido = new Tesoro(posicionNueva);
	jugadorActual->getTesoros()->agregar(tesoroPartido);
	delete tesoroPartido;

}

void Carta::jugarCartaBlindaje(){


}

void Carta::jugarCartaPerderTurno(){


}

void Carta::jugarCartaRadar(){


}

std::string Carta::getNombreCarta(){
	std::string nombreCarta;
	switch(this->tipoCarta){
	case(BLINDAJE):
		nombreCarta = "Blindaje";
		break;
	case(RADAR):
		nombreCarta = "Radar";
		break;
	case(PARTIR):
		nombreCarta = "Partir";
		break;
	case(LADRON):
		nombreCarta = "Ladron";
		break;
	case(SNIPER):
		nombreCarta = "Sniper";
		break;
	case(ROBAR):
		nombreCarta = "Robar";
		break;
	default:
		break;
	}
	return nombreCarta;
}


