#include "ExportarBmp.h"

ExportarBmp::ExportarBmp(int cantidadDeJugadores,Vector<int> *dimensiones){


	this->dimensiones = dimensiones;
	this->tableros= new Vector<Vector<bitmap_image>*>(cantidadDeJugadores);
	this->nombreDelArchivo= new Vector<Vector<std::string>*>(cantidadDeJugadores);
	for (int i = 1; i <= cantidadDeJugadores; i++) {
	        this->tableros->set(i,new Vector<bitmap_image>(dimensiones->get(3)));
	        this->nombreDelArchivo->set(i,new Vector<std::string>(dimensiones->get(3)));
	    }


	//le pongo tableros vacios a cada nivel de cada jugador y le asigno el nombre correspondiente
	bitmap_image tablero;
	tablero = this->crearTablero();
	for (int i = 1; i <= cantidadDeJugadores; i++) {
		for (int j = 1; j <= this->dimensiones->get(3); j++){
			this->tableros->get(i)->set(j, tablero);
			this->nombreDelArchivo->get(i)->set(j,formarNombreCompleto(i,j));
			this->tableros->get(i)->get(j).save_image(this->nombreDelArchivo->get(i)->get(j));
		}
	}
	//inicializo los atributos con los archivos de los .bmp
	bitmap_image tesoroCopy("tesoro.bmp");
	this->tesoro=tesoroCopy;
	bitmap_image blindajeCopy("blindaje.bmp");
	this->blindaje=blindajeCopy;
	bitmap_image espiaCopy("espia.bmp");
	this->espia=espiaCopy;
	bitmap_image tesoroMinaCopy("tesoroMina.bmp");
	this->tesoroMina=tesoroMinaCopy;
	bitmap_image blancoCopy("blanco.bmp");
	this->blanco=blancoCopy;

}

bitmap_image ExportarBmp::crearTablero(){

	//crea el tablero con cada casillero de un tamaño de 50 por 50 pixeles
	bitmap_image tableroCopy((this->dimensiones->get(1)*50),(this->dimensiones->get(2)*50));
	//pone el fondo del tablero en blanco
	tableroCopy.set_all_channels(255, 255, 255);
	image_drawer draw(tableroCopy);
	draw.pen_width(2);
	draw.pen_color(0, 0, 0);

	for(int i=0; i<this->dimensiones->get(1)*50; i++){
		if((i%50)== 0){
			draw.vertical_line_segment(0,this->dimensiones->get(2)*50,i);
		}
	}
	for(int i=0; i<this->dimensiones->get(2)*50; i++){
		if((i%50)== 0){
			draw.horiztonal_line_segment(0,this->dimensiones->get(1)*50,i);
		}
	}
	return tableroCopy;
}

std::string ExportarBmp::formarNombreCompleto(int numeroDeJugador, int nivel){
	std::string nombreCompleto;
	std::string jugador = "jugador";
	std::string altura= ",altura";
	std::string bmp= ".bmp";
	nombreCompleto = jugador + std::to_string(numeroDeJugador) + altura + std::to_string(nivel) + bmp;
	return nombreCompleto;
}

ExportarBmp::~ExportarBmp() {
	for (int i = 0; i < this->tableros->getLongitud(); i++) {
			delete[] tableros->get(i);
	}
}

void ExportarBmp::ponerEnBlanco(Vector<int>* posicion, int jugador){

	this->tableros->get(jugador)->get(posicion->get(3))
			.copy_from(this->blanco,((posicion->get(1)*50)-48),((posicion->get(2)*50)-48));
	this->tableros->get(jugador)->get(posicion->get(3)).save_image(this->nombreDelArchivo->get(jugador)->get(posicion->get(3)));
}


void ExportarBmp::ponerEspia(Vector<int>* posicion, int jugador){

	this->tableros->get(jugador)->get(posicion->get(3))
				.copy_from(this->espia,((posicion->get(1)*50)-48),((posicion->get(2)*50)-48));
	this->tableros->get(jugador)->get(posicion->get(3)).save_image(this->nombreDelArchivo->get(jugador)->get(3));

}

void ExportarBmp::moverTesoro(Vector<int>* posicionActual, Vector<int>* posicionNueva, int jugador){

	this->tableros->get(jugador)->get(posicionActual->get(3))
				.copy_from(this->blanco,((posicionActual->get(1)*50)-48),((posicionActual->get(2)*50)-48));
	this->tableros->get(jugador)->get(posicionNueva->get(3))
				.copy_from(this->tesoro,((posicionNueva->get(1)*50)-48),((posicionNueva->get(2)*50)-48));
	this->tableros->get(jugador)->get(posicionActual->get(3)).save_image(this->nombreDelArchivo->get(jugador)->get(posicionActual->get(3)));

}

void ExportarBmp::ponerTesoroMina(Vector<int>* posicion, int jugador){

	this->tableros->get(jugador)->get(posicion->get(3))
				.copy_from(this->tesoroMina,((posicion->get(1)*50)-48),((posicion->get(2)*50)-48));
	this->tableros->get(jugador)->get(posicion->get(3)).save_image(this->nombreDelArchivo->get(jugador)->get(posicion->get(3)));

}

void ExportarBmp::ponerBlindaje(Vector<int>* posicion, int jugador){

	this->tableros->get(jugador)->get(posicion->get(3))
				.copy_from(this->blindaje,((posicion->get(1)*50)-48),((posicion->get(2)*50)-48));
	this->tableros->get(jugador)->get(posicion->get(3)).save_image(this->nombreDelArchivo->get(jugador)->get(posicion->get(3)));

}


