#ifndef VECTOR_H_
#define VECTOR_H_
#include <stddef.h>

template<class T> class Vector{
private:
	T * valores;
	unsigned int longitud;

	/*
	 * pre: recibe un valor
	 * post: valida que este entre 1 y longitud, si no tira error
	 */
	void validarIndice(unsigned int indice);

public:
	/*
	 * pre: recibe longitud mayor a 0
	 * post: crea el vector y guarda el valor de la longitud, e inicializa los valores del vector en 0
	 */
	Vector(unsigned int longitud);

	/*
	 * pre: -
	 * post: borra toda la memoria dinamica utilizada
	 */
	virtual ~Vector();
	/*
	 * pre: recibe indice entre 1 y la longitud
	 * post: guarda el dato recibido en la posicion indicada
	 */
	void set(int indice, T valor);

	/*
	 * pre: recibe un indice entre 1 y la longitud
	 * post: devuelve el dato en el indice indicado
	 */
	T get(int indice);

	/*
	 * pre: -
	 * post: devuelve la longitud del vector
	 */
	int getLongitud();

	void igual(Vector<int>* valor1, Vector<int>* valor2);
};

template <class T> void Vector<T>::validarIndice(unsigned int indice){
		if(indice < 1){
			throw "El indice debe ser igual o mayor a 1";
		}
		if(indice > this->longitud){
			throw "El indice debe ser igual o menor a longitud";
		}
	}

template <class T> Vector<T>::Vector(unsigned int longitud){
	if(longitud <= 0){
		throw "La longitud debe ser mayor a 0";
	}
	this->longitud = longitud;
	this->valores = new T[this->longitud];
	for(unsigned int i = 0; i < this->longitud; i++){
			this->valores[i] = T();
	}
}

template <class T> Vector<T>:: ~Vector(){
	delete [] this->valores;
	}

template <class T> void Vector<T>::set(int indice, T valor){
	validarIndice(indice);
	this->valores[indice-1] = valor;
}

template <class T> T Vector<T>:: get(int indice){
	validarIndice(indice);
	return this->valores[indice-1];
}

template <class T> int Vector<T>:: getLongitud(){
	return this->longitud;
}

template <class T> void Vector<T>:: igual(Vector<int>* valor1, Vector<int>* valor2){

	valor1->set(1,valor2->get(1));
	valor1->set(2,valor2->get(2));
	valor1->set(3,valor2->get(3));
}

#endif /* VECTOR_H_ */
