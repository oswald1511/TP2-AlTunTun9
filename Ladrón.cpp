#include "Ladron.h"
#include <cstdlib> // Para funciones de generación de números aleatorios

Ladron::Ladron() {
    // Constructor del "Ladron" si es necesario
}

// Implementación de la función para robar una carta al azar de otro jugador
void Ladron::robarCartaAlOtroJugador(Jugadores& jugadores, unsigned int jugadorActual, unsigned int otroJugador) {
    if (jugadorActual >= jugadores.obtenerCantidadJugadores() || otroJugador >= jugadores.obtenerCantidadJugadores()) {
        cout << "Jugador no válido." << endl;
        return;
    }

    Jugador* jugadorQueRoba = jugadores.obtenerJugador(jugadorActual);
    Jugador* otroJugadorObj = jugadores.obtenerJugador(otroJugador);

    if (otroJugadorObj->obtenerMano().empty()) {
        cout << "El otro jugador no tiene cartas para robar." << endl;
        return;
    }

    // Elige una carta aleatoria del otro jugador
    unsigned int indiceCartaRobada = rand() % otroJugadorObj->obtenerMano().size();

    // Roba la carta y la agrega a la mano del jugador
    jugadorQueRoba->agregarCarta(otroJugadorObj->obtenerMano()[indiceCartaRobada]);

    // Elimina la carta robada de la mano del otro jugador
    otroJugadorObj->eliminarCarta(indiceCartaRobada);

    cout << "Jugador " << jugadorActual << " robó una carta al jugador " << otroJugador << "." << endl;
}






