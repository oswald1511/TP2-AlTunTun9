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
	Jugadores(Vector<int>* dimensionesTablero, int cantidadJugadores, int cantidadTesoros);

	/*
	 * pre: recibe cantidad de jugadores
	 * post: elimina la memoria utilizada
	 */
	virtual ~Jugadores();

	/*
	 * pre: -
	 * post: coloca los tesoros de cada jugador en posiciones aleatorias del tablero
	 */
	void inicializarTesoros(Tablero* tablero);

	/*
	 * pre: -
	 * post: devuelve la cantidad de jugadores
	 */
	int getCantidadJugadores();

	/*
	 * pre: recibe el numero de jugador solicitado
	 * post: devuelve el jugador del numero indicado
	 */
	Jugador* getJugador(unsigned int numeroJugador);

	/*
	 * pre:
	 * post: elimina un jugador
	 */
	void eliminarJugador(int jugador);

	/*
	 * pre:-
	 * post: devuelve la lista de jugadores
	 */
	Lista<Jugador*>* getJugadores();

	/*
	 * pre:-
	 * post: tira error si dice una cantidad de tesoros mayor a la cantidad de casillas en el tablero
	 */
	void validarCantidadDeTesoros(int cantidadTesoros, Vector<int>* dimensiones);
};

#endif /* JUGADORES_H_ */
