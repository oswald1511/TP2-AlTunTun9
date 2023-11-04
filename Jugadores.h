#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "Jugador.h"
#include "Lista.h"

class Jugadores {
private:
	Lista<Jugador*> * jugadores;
	int cantidadJugadores;


public:

	/*
	 * pre: recibe cantidad de jugadores
	 * post: crea la lista e inicializa los valores
	 */
	Jugadores(int cantidadJugadores, int cantidadTesoros);

	/*
	 * pre: recibe cantidad de jugadores
	 * post: elimina la memoria utilizada
	 */
	virtual ~Jugadores();

	/*
	 * pre:
	 * post: elimina un jugador cuando se queda sin tesoros
	 */
	void eliminarJugador();
};

#endif /* JUGADORES_H_ */
