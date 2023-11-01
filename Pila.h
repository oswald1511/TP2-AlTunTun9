#ifndef PILA_H_
#define PILA_H_

#ifndef SRC_PILA_H_
#define SRC_PILA_H_

#include <cstddef>
#include "Nodo.h"

template<class T> class Pila {
	private:
	// Primer elemento de la pila
	Nodo<T>* primero;

	public:
	// Constructor
	// PRE:  ninguna
	// POST: construye una pila vacía
	//       - primero apunta a nulo
	Pila(){
		this->primero = NULL;
	}

	// Destructor
	// PRE:  pila creada
	// POST: Libera todos los recursos de la pila
	~Pila(){
		while (!(this->pilaVacia())){
			this->borrarDato();
		}
	}

	// ¿La pila es vacía?
	// PRE:  pila creada
	// POST: devuelve verdadero si la pila es vacía
	//       falso de lo contrario
    bool pilaVacia(){
    	return (this->primero == NULL);
    }

    // Agregar un elemento a la pila
    // PRE:  pila creada
    // POST: agrega un dato (dentro de un nodo) al principio
    void agregar(T dato){
    	Nodo<T>* nuevo = new Nodo<T>(dato);
    	nuevo->cambiarSiguiente(this->primero);
    	this->primero = nuevo;
    }

    // Obtener el dato que está en la cima
    // PRE:  - pila creada y no vacía
    // POST: devuelve el dato que está en la cima
    T getDato(){
    	return this->primero->obtenerDato();
    }

    // Borrado del nodo que está en la cima
    // PRE:  - pila creada y no vacía
    // POST: libera el nodo que está en la cima
    void borrarDato(){
    	Nodo<T>* aux = this->primero;
    	this->primero = aux->obtenerSiguiente();
    	delete aux;
    }
};


#endif /* PILA_H_ */
