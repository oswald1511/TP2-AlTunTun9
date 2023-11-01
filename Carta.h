#ifndef CARTA_H_
#define CARTA_H_

#include <iostream>
using namespace std;

enum nombreCarta {BLINDAJE, RADAR, PARTIR, CARTA4, CARTA5, CARTA6};

class Carta {
private:
	nombreCarta tipoCarta;
public:

	/*
	 * pre:
	 * pos:crea una objeto tipo carta
	 */
	Carta(string tipoCarta);

	/*
	 * pre:que exista
	 * pos:
	 */
	virtual ~Carta();

	/*
	 * pre:que exista la carta
	 * pos:le da al jugador una carta
	 */
	void jugarCarta(string tipoCarta);
};

#endif /* CARTA_H_ */
