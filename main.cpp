#include "Consola.h"
#include "Jugadores.h"
#include "ExportarBmp.h"
#include "Constantes.h"
#include "TableroMaster.h"

using namespace std;

int main(){
	srand(time(NULL));


	Consola* consola = new Consola();
	//consola->bienvenida();
	Vector<int>* dimensionesTablero = consola->pedirTamanioTablero();
	int cantidadJugadores = consola->pedirCantidadJugadores();
	int cantidadTesoros = consola->pedirCantidadTesoros();

	//verificar que en la creacion de los tesoros no se pongan 2 tesoros en el mismo lugar
	Jugadores* jugadores = new Jugadores(dimensionesTablero, cantidadJugadores, cantidadTesoros);
	TableroMaster* tableroGeneral = new TableroMaster(dimensionesTablero, jugadores);

	//creacion de los .bmp
	ExportarBmp* bmp= new ExportarBmp(cantidadJugadores, dimensionesTablero);

	//para probar a ver donde estan los tesoros(esta mal, los planos los imprime en el orden zyx, no en el xyz)
	//consola->imprimirTablero(tableroGeneral->getTablero());
	Vector <Jugador*> *jugador = new Vector<Jugador*>(cantidadJugadores);
	for (int i =1; i<= cantidadJugadores; i++){

		jugador->set(i,jugadores->getJugador(i));
		for(unsigned int j=1; j <= jugador->get(i)->getTesoros()->contarElementos(); j++){
			bmp->moverTesoro(jugador->get(i)->getTesoros()->obtener(j)->getPosicion(),jugador->get(i)->getTesoros()->obtener(j)->getPosicion(),i);
		}
	}

	while(cantidadJugadores > 1){

		for (int i =1; i<= cantidadJugadores; i++){
			cout << "JUGADOR " << jugador->get(i)->getNumeroJugador() << endl;

			//jugar carta
			//el jugador puede robar cartas y elegir si usarlas, pero no tienen utilidad
			Vector<Lista<Carta*>*>* cartas = new Vector<Lista<Carta*>*>(cantidadJugadores);
			jugador->get(i)->robarCarta();
			cartas->set(i,jugador->get(i)->getCartas());
			bool juegaCarta = consola->tomaDecision("Desea jugar una carta?");
			if (juegaCarta){
				//hay que validar que la opcion del usuario no se pase de las opciones que hay de cartas
				int posicionCarta = consola->seleccionarCarta(cartas->get(i));
				jugador->get(i)->jugarCarta(posicionCarta);
				cout<<"Se juega la carta y sigue el turno"<<endl;
			}

			//tesoros mina
			if(jugador->get(i)->quedanTesorosMina()){
				bool usaTesoroMina = consola->tomaDecision("Desea colocar un tesoro mina?");
				if(usaTesoroMina){
					TesoroMina* tesoroMina;
					tesoroMina = jugador->get(i)->getTesoroMinaDisponible();
					Vector<int>* posicion = consola->pedirPosicion();

					//primero chequear si hay fichas de otros jugadores
					Casillero* casilleroOcupado = tableroGeneral->chequearPosicion(jugador->get(i)->getNumeroJugador(), posicion);
					if(casilleroOcupado){
						int jugadorAtacado = casilleroOcupado->getJugador();
						if(casilleroOcupado->getFicha() == TESORO){
							cout << "El tesoro mina encontro un tesoro del jugador ";
						} else if (casilleroOcupado->getFicha() == ESPIA){
							cout << "El tesoro mina encontro un espia del jugador ";
						} else if (casilleroOcupado->getFicha() == TESORO_MINA){
							cout << "El tesoro mina encontro un tesoro mina del jugador ";
						}
						cout << jugadorAtacado << "!" << endl;
						cout << "Sera eliminado y se inactiva la casilla" << endl;

						//tengo que saber el indice del tesoro a remover
						int numeroDeTesoroEliminado = jugador->get(jugadorAtacado)->getTablero()->buscarIndiceDeTesoro(jugador->get(jugadorAtacado)->getTesoros(),posicion);
						jugador->get(jugadorAtacado)->getTesoros()->remover(numeroDeTesoroEliminado);
						tableroGeneral->deshabilitarCasillero(posicion);
						bmp->ponerEnBlanco(posicion,i);
						bmp->ponerEnBlanco(posicion,jugadorAtacado);
					}else{
						tesoroMina->setPosicion(posicion);
						bmp->ponerTesoroMina(posicion, i);
						jugador->get(i)->getTablero()->setCasillero(posicion, TESORO_MINA, jugador->get(i)->getNumeroJugador());
					}
					tableroGeneral->actualizarTablero();

					delete posicion;
				}
			}

			//poner espia
			bool poneEspia = consola->tomaDecision("Desea poner un espia?");
				if(poneEspia){
					Vector<int>* posicion = consola->pedirPosicion();

					//primero chequear si hay fichas de otros jugadores
					Casillero* casilleroOcupado = tableroGeneral->chequearPosicion(jugador->get(i)->getNumeroJugador(), posicion);
					if(casilleroOcupado){
						int jugadorAtacado = casilleroOcupado->getJugador();
						if(casilleroOcupado->getFicha() == TESORO){
							cout << "El espia encontro un tesoro del jugador ";
						} else if (casilleroOcupado->getFicha() == ESPIA){
							cout << "El espia encontro un espia del jugador ";
						} else if (casilleroOcupado->getFicha() == TESORO_MINA){
							cout << "El espia encontro un tesoro mina del juagdor ";
						}
						cout << jugadorAtacado << "!" << endl;
						cout << "Sera eliminado y se inactiva la casilla" << endl;
						//tengo que saber el indice del tesoro a remover
						int numeroDeTesoroEliminado = jugador->get(jugadorAtacado)->getTablero()->buscarIndiceDeTesoro(jugador->get(jugadorAtacado)->getTesoros(),posicion);
						jugador->get(jugadorAtacado)->getTesoros()->remover(numeroDeTesoroEliminado);
						tableroGeneral->deshabilitarCasillero(posicion);
						bmp->ponerEnBlanco(posicion,i);
						bmp->ponerEnBlanco(posicion,jugadorAtacado);
					}else{
						jugador->get(i)->ponerEspia(posicion);
						bmp->ponerEspia(posicion,i);
						jugador->get(i)->getTablero()->setCasillero(posicion, ESPIA, jugador->get(i)->getNumeroJugador());
					}
					tableroGeneral->actualizarTablero();

				}

			//mover tesoro
			if(jugador->get(i)->getTesoros()->contarElementos() >= 1){
				bool mueveTesoro = consola->tomaDecision("Desea mover un tesoro?");
				if(mueveTesoro){
					int tesoroAMover = consola->mostrarTesoros(jugadores->getJugador(i));
					Vector<int>* posicionActual = new Vector<int>(3);
					posicionActual->igualar(posicionActual, jugador->get(i)->getTesoros()->obtener(tesoroAMover)->getPosicion());
					Vector<int> * direccion = consola->elegirDireccion();
					Vector<int> * posicionNueva = jugador->get(i)->getTablero()->validarMovimiento(jugador->get(i)->getTesoros()->obtener(tesoroAMover)->getPosicion(),direccion);
					//primero chequear si hay fichas de otros jugadores
					Casillero* casilleroOcupado = tableroGeneral->chequearPosicion(jugador->get(i)->getNumeroJugador(), posicionNueva);
					if(casilleroOcupado){
						int jugadorAtacado = casilleroOcupado->getJugador();
						if(casilleroOcupado->getFicha() == TESORO){
							cout << "El tesoro encontro un tesoro del jugador ";
						} else if (casilleroOcupado->getFicha() == ESPIA){
							cout << "El tesoro entro a la casilla con un espia del jugador ";
						} else if (casilleroOcupado->getFicha() == TESORO_MINA){
							cout << "El tesoro encontro un tesoro mina del jugador ";
						}
						cout << jugadorAtacado << "!" << endl;
						cout << "Sera eliminado y se inactiva la casilla" << endl;
					}
					else{
						jugador->get(i)->getTesoros()->obtener(tesoroAMover)->setPosicion(posicionNueva);
						bmp->moverTesoro(posicionActual ,posicionNueva, i);
						jugador->get(i)->getTablero()->setCasillero(posicionActual, VACIO, jugador->get(i)->getNumeroJugador());
						jugador->get(i)->getTablero()->setCasillero(posicionNueva, TESORO, jugador->get(i)->getNumeroJugador());
					}

				}
			}
			else{
				jugadores->eliminarJugador(i);
				cantidadJugadores--;
			}
			tableroGeneral->actualizarTablero();
			delete cartas;
		}

	}
	consola->ganador(jugadores->getJugadores()->obtener(1)->getNumeroJugador());
	//consola->despedida();


	delete bmp;
	delete tableroGeneral;
	delete jugador;
	delete jugadores;
	delete consola;
	return 0;

}




