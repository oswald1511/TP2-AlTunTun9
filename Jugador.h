#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Lista.h"
#include "Tesoro.h"
#include "Carta.h"

class Jugador {
private:
	Lista<Tesoro*> * tesoros;
	Lista<Carta*> * cartas;
public:
	Jugador(int cantidadTesoros);
	virtual ~Jugador();
	void ponerEspia(Vector<int> * posicion);
	void moverTesoro(Vector<int> * posicionActual, Vector<int> * posicionNueva);
	void robarCarta();
	void jugarCarta(string nombreCarta);
};

#endif /* JUGADOR_H_ */
