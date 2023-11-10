/*
 * TableroMaster.h
 *
 *  Created on: 10/11/2023
 *      Author: algo2
 */

#ifndef TABLEROMASTER_H_
#define TABLEROMASTER_H_

#include <iostream>
#include "Tablero.h"
#include "Jugador.h"
#include "Jugadores.h"
#include "Vector.h"

class TableroMaster {
private:
	Tablero* tablero;
	Lista<Jugador*>* jugadores;

public:

	/*
	 * pre: recibe el vector dimensiones de tablero y los jugadores de la partida actual
	 * post: crea el tablero con las dimensiones indicadas
	 */
	TableroMaster(Vector<int>* dimensiones, Jugadores* jugadores);

	/*
	 * pre: -
	 * post: elimina toda la memoria utilizada
	 */
	virtual ~TableroMaster();

	/*
	 * pre: -
	 * post: devuelve el tablero master
	 */
	Tablero* getTablero ();

	/*
	 * pre: -
	 * post: actualiza el tablero con todos los tesoros
	 */
	void actualizarTesoros ();

	/*
	 * pre: recibe el numero de jugador actual y la posicion a chequear
	 * post: devuelve el casillero del jugador que esta ocupando esa posicion
	 */
	Casillero* chequearPosicion (int jugadorActual, Vector<int>* posicion);

	/*
	 * pre: recibe un casillero existente
	 * post: establece el casillero en la posicion del casillero
	 */
	void setCasillero(Casillero* casillero);

	/*
	 * pre: recibe la posicion a deshabilitar
	 * post: deshabilita el casillero por cierta cantidad de turnos
	 */
	void deshabilitarCasillero(Vector<int>* posicion);

	/*
	 * pre: -
	 * post: actualiza el tablero con los casilleros de todos los jugadores
	 */
	void actualizarTablero();
};

#endif /* TABLEROMASTER_H_ */
