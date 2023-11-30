#ifndef CARTA_H_
#define CARTA_H_

#include <cstdlib>
#include <string>
#include "Jugadores.h"
#include "Jugador.h"
#include "Tesoro.h"
#include "Vector.h"


enum nombreCarta {BLINDAJE, RADAR, PARTIR, LADRON, SNIPER, ROBAR};


class Carta {
private:
	nombreCarta tipoCarta;

public:

	/*
	 * pre: -
	 * post: crea una carta de tipo aleatorio
	*/
	Carta();

	/*
	 * pre:
	 * post: crea una carta segun el tipo indicado
	 */
	Carta(nombreCarta tipoCarta);

	/*
	 * pre:
	 * post:
	 */
	virtual ~Carta();

	/*
	 * pre: -
	 * post: se juega la carta segun el tipo de carta que sea
	 */
	void jugarCarta();

	/*
	 * pre: -
	 * post: devuelve el tipo de carta
	 */
	std::string getNombreCarta();

	/*
	 * pre:
	 * pos:
	 */
	void jugarCartaBlindaje();

	/*
	 * pre:
	 * pos:
	 */
	void jugarCartaRadar();

	/*
	 * pre:
	 * pos:
	 */
	void jugarCartaPartirTesoro(Jugador* jugadorActual, Vector<int>* posicionNueva);

	/*
	 * pre:
	 * pos:
	 */
	void jugarCartaSniper(Jugador* jugadorActual, Jugadores* jugadores);

	/*
	 * pre:
	 * pos:
	 */
	void jugarCartaLadron();

	/*
	 * pre:
	 * pos:
	 */
	void jugarCartaPerderTurno();


};


#endif /* CARTA_H_ */
