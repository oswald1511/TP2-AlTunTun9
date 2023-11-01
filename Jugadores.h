#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "Jugador.h"
#include "Lista.h"

class Jugadores {
private:
	Lista<Jugador*> * Jugador;
	int cantidadJugadores;
public:
	Jugadores(int cantidadJugadores);
	virtual ~Jugadores();
	void eliminarJugador();
};

#endif /* JUGADORES_H_ */
