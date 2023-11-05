
#include "Consola.h"
#include "Jugadores.h"

using namespace std;

int main(){
	srand(time(NULL));
	Consola* consola = new Consola();
	Vector<int>* dimensionesTablero = consola->pedirTamanioTablero();
	int cantidadJugadores = consola->pedirCantidadJugadores();
	int cantidadTesoros = consola->pedirCantidadTesoros();
	//consola->bienvenida();
	Jugadores* jugadores = new Jugadores(dimensionesTablero, cantidadJugadores, cantidadTesoros);

	//ejemplo para ver si se agarra bien las cartas
	for(int i = 1; i <= 5; i++){
		Jugador* jugador = jugadores->getJugador(i);
		for(int j = 0; j < 3; j++){
			jugador->robarCarta();
		}
		jugador->getCartas()->iniciarCursor();
		cout << "Cartas jugador " << i << ": ";
		while(jugador->getCartas()->avanzarCursor()){
			cout << jugador->getCartas()->obtenerCursor()->getNombreCarta() << " ";
		}
		cout << "\n";
	}

	//ejemplo de imprimir el tablero del jugador 1
	//consola->imprimirTablero(jugador1->getTablero());




	/*
	Vector<int>* posicion = consola->pedirPosicion();
	cout << "El casillero seleccionado tiene la ficha: ";
	cout << tablero->getCasillero(posicion)->getFicha() << endl;
	delete posicion;
	 */


	delete jugadores;
	delete consola;
	return 0;
}



