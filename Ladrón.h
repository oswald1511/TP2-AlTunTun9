#ifndef LADRON_H
#define LADRON_H

#include "Jugadores.h" // Asegúrate de incluir los encabezados necesarios

class Ladron {
public:
    Ladron();

    // Función para robar una carta al azar de otro jugador
    void robarCartaAlOtroJugador(Jugadores& jugadores, unsigned int jugadorActual, unsigned int otroJugador);
};

#endif
