#ifndef MAZO_H_
#define MAZO_H_

#include <Pila.h>
#include <Carta.h>

class Mazo {
private:
	Pila<Carta*> * mazo;
public:
	Mazo(int cantidadCartas);
	virtual ~Mazo();
	void sacarCarta();
};

#endif /* MAZO_H_ */
