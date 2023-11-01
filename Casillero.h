#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "Vector.h"

class Casillero {
private:
	char ficha;
	Vector<int> * posicion;
public:
	Casillero(int x, int y, int z);
	virtual ~Casillero();
	Vector<int> * getPosicion();
	void deshabilitar();
	void habilitar();
	void setficha(char ficha);
	char getFicha();
};

#endif /* CASILLERO_H_ */
