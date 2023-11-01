#ifndef CARTA_H_
#define CARTA_H_

#include <iostream>
using namespace std;

enum nombreCarta {BLINDAJE, RADAR, PARTIR, CARTA4, CARTA5, CARTA6};

class Carta {
private:
	nombreCarta tipoCarta;
public:
	Carta(string tipoCarta);
	virtual ~Carta();
	void jugarCarta(string tipoCarta);
};

#endif /* CARTA_H_ */
