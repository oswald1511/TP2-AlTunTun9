#ifndef CARTA_H_
#define CARTA_H_

#include <string>

enum nombreCarta {BLINDAJE, RADAR, PARTIR, CARTA4, CARTA5, CARTA6};

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
	Carta(std::string tipoCarta);

	/*
	 * pre:
	 * post:
	 */
	virtual ~Carta();

	/*
	 * pre: -
	 * post: se juega la carta segun el tipo de carta que sea
	 */
	void jugarCarta(std::string tipoCarta);
};


#endif /* CARTA_H_ */
