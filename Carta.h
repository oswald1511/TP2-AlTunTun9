#ifndef CARTA_H_
#define CARTA_H_

#include <cstdlib>
#include <string>

enum nombreCarta {BLINDAJE, RADAR, PARTIR, CARTA4, LADRÓN, CARTA6};

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
	void jugarCarta(nombreCarta tipoCarta);

	/*
	 * pre: -
	 * post: devuelve el tipo de carta
	 */
	std::string getNombreCarta();


};


#endif /* CARTA_H_ */
