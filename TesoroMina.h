#ifndef TESOROMINA_H_
#define TESOROMINA_H_

class TesoroMina {
private:
	Vector<int> * posicion;
public:
	TesoroMina(int x, int y, int z);
	virtual ~TesoroMina();
	void stePosicion(Vector<int>* posicion);
};

#endif /* TESOROMINA_H_ */
