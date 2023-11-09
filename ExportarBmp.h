#ifndef EXPORTARBMP_H_
#define EXPORTARBMP_H_
#include "Vector.h"
#include "bitmap_image.hpp"


class ExportarBmp {

private:
	Vector<Vector<bitmap_image>*>* tableros;
	Vector<Vector<std::string>*>* nombreDelArchivo;
	Vector<int> *dimensiones;
	bitmap_image tesoro;
	bitmap_image espia;
	bitmap_image tesoroMina;
	bitmap_image blindaje;
	bitmap_image blanco;

public:

	/*
	 * pre:
	 * pos:inicializa los atributos
	 */
	ExportarBmp(int cantidadDeJugadores, Vector<int> *dimensiones);

	/*
	 * pre:
	 * pos:crea un tablero en blanco segun las dimensiones dadas
	 */
	bitmap_image crearTablero();

	/*
	 * pre:que el numero de jugador y el nivel esten dentro de rango
	 * pos:devuelve un string con al nombre para el archivo del tablero
	 */
	std::string formarNombreCompleto(int numeroDeJugador, int nivel);

	/*
	 * pre:-
	 * pos:elimina la memoria dinamica utilizada
	 */
	virtual ~ExportarBmp();

	/*
	 * pre:
	 * pos:pone imagen de espia en el casillero
	 */
	void ponerEspia(Vector<int>* posicion, int jugador);

	/*
	 * pre:
	 * pos:pone imagen de tesoro en el casillero nuevo, y deja vacio el casillero anterior
	 */
	void moverTesoro(Vector<int>* posicionActual, Vector<int>* posicionNueva, int jugador);

	/*
	 * pre:
	 * pos:pone imagen de tesoro mina en el casillero
	 */
	void ponerTesoroMina(Vector<int>* posicion, int jugador);

	/*
	 * pre:
	 * pos:pone imagen de blinaje en el casillero
	 */
	void ponerBlindaje(Vector<int>* posicion, int jugador);

	/*
	 * pre:
	 * pos:pone el casillero vacio
	 */
	void ponerEnBlanco(Vector<int>* posicion, int jugador);
};

#endif /* EXPORTARBMP_H_ */
