#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "Jugador.h"
#include "Lista.h"
#include "Tablero.h"

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
	 * pre: recibe el tda tablero para pedir posiciones aleatorias
	 * post: coloca los tesoros de cada jugador en posiciones aleatorias del tablero
	 */
	void inicializarTesoros(Tablero* tablero);

	/*
	 * pre:
	 * post: elimina un jugador cuando se queda sin tesoros
	 */
	void eliminarJugador();
};

#endif /* JUGADORES_H_ */
