#ifndef NODO_H_
#define NODO_H_

#include <cstddef>

template<class T> class Nodo {

private:

    T dato;
    Nodo<T>* siguiente;

public:

    /*
     * pre: recibe un dato de tipo T
     * post: el Nodo resulta inicializado con el dato dado
     *       y sin un Nodo siguiente.
     */
    Nodo(T dato) {

        this->dato = dato;
        this->siguiente = NULL;
    }

    /*
     * pre: -
     * post: devuelve el valor del dato.
     */
    T obtenerDato() {

        return this->dato;
    }

    /*
     * pre: -
     * post: cambia el valor del dato.
     */
    void cambiarDato(T nuevoDato) {

        this->dato = nuevoDato;
    }

    /*
     * pre: -
     * post: devuelve el siguiente Nodo.
     */
    Nodo<T>* obtenerSiguiente() {

        return this->siguiente;
    }

    /*
     * pre: recibe un puntero a nodo
     * post: cambia el siguiente Nodo por nuevoSiguiente.
     */
    void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

        this->siguiente = nuevoSiguiente;
    }
};

#endif /* NODO_H_ */
