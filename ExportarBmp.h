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
	 * pos:
	 */
	void ponerEspia(Vector<int>* posicion, int jugador);

	/*
	 * pre:
	 * pos:
	 */
	void moverTesoro(Vector<int>* posicionActual, Vector<int>* posicionNueva, int jugador);

	/*
	 * pre:
	 * pos:
	 */
	void ponerTesoroMina(Vector<int>* posicion, int jugador);

	/*
	 * pre:
	 * pos:
	 */
	void ponerBlindaje(Vector<int>* posicion, int jugador);

	/*
	 * pre:
	 * pos:
	 */
	void ponerEnBlanco(Vector<int>* posicion, int jugador);
};

#endif /* EXPORTARBMP_H_ */
