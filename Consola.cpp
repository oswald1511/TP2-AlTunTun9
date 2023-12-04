#include "Consola.h"

Consola::Consola(){
	this->dimensionesTablero = NULL;
}

Consola::~Consola(){
	delete this->dimensionesTablero;
}

void Consola::validarPosicion(Vector<int>* posicion){
	for(int i = 1; i <= 3; i++){
		if(posicion->get(i) > this->dimensionesTablero->get(i)){
			throw std::string("La posicion excede los limites del tablero");
		}
	}
}

Vector<int>* Consola::pedirTamanioTablero(){
	int x, y, z;
	Vector<int>* dimensiones = new Vector<int>(3);
	std:: cout << "Ingrese el largo del tablero (X): ";
	std::cin >> x;
	dimensiones->set(1,abs(x));
	std:: cout << "Ingrese el ancho del tablero (Y): ";
	std::cin >> y;
	dimensiones->set(2,abs(y));
	std:: cout << "Ingrese el alto del tablero (Z): ";
	std::cin >> z;
	dimensiones->set(3,abs(z));
	this->dimensionesTablero = dimensiones;
	return dimensiones;
}

Vector<int>* Consola::pedirPosicion(){
	bool ok = false;
	Vector<int>* posicion = new Vector<int>(3);
	while(!ok){
		int x, y, z;
		std::cout << "Ingrese posicion X: ";
		std::cin >> x;
		std::cout << "Ingrese posicion Y: ";
		std::cin >> y;
		std::cout << "Ingrese posicion Z: ";
		std::cin >> z;
		posicion->set(1, x);
		posicion->set(2, y);
		posicion->set(3, z);
		try{
			this->validarPosicion(posicion);
			ok = true;
		}catch(std::string& error){
			std::cout << error << std::endl;
			std::cout << "Ingrese otra posicion" << std::endl;
		}
	}
	return posicion;
}

void Consola::imprimirPosicion(Vector<int>* posicion){
	std::cout << "Posicion: ";
	for(int i = 1; i <= 3; i++){
		std::cout << posicion->get(i) << " ";
	}
	std::cout << "\n";
}


int Consola::pedirCantidadJugadores(){

	int cantidadJugadores;
	std::cout << "Ingrese la cantidad de jugadores: ";
	std::cin >> cantidadJugadores;

	return cantidadJugadores;
}


int Consola::pedirCantidadTesoros(){
	int cantidadTesoros;
	std::cout << "Ingrese la cantidad de tesoros: ";
	std::cin >> cantidadTesoros;
	return cantidadTesoros;
}


void Consola::limpiarPantalla(){
	for(int i=0; i<=30; i++){
		std::cout << "\n" << std::endl;
	}
}

void Consola::bienvenida(){
	std::cout << "¡Bienvenidos a Tesoro Binario 2.0!\n\n\n"
			"Estamos encantados de darles la bienvenida a esta emocionante"
			" y evolucionada aventura cibernética. En Tesoro Binario 2.0,"
			" se embarcarán en una búsqueda digital"
			" llena de desafíos, enigmas y tesoros ocultos en el vasto"
			" mundo de la tecnología.\n\n"
			"Aquí, la habilidad para descifrar códigos y la astucia"
			" para resolver acertijos serán"
			" sus mejores aliados. Prepárense para adentrarse en un"
			" universo virtual lleno de "
			"maravillas y peligros, donde cada decisión que tomen"
			" los llevará más cerca del codiciado"
			" tesoro binario.\n\nDesde las profundidades del código"
			" binario hasta los misterios de"
			" la inteligencia artificial, este juego les ofrecerá"
			" una experiencia única en la que"
			" su ingenio y destreza serán puestos a prueba."
			" ¿Tienen lo que se necesita para "
			"desentrañar los secretos de Tesoro Binario 2.0?"
			"\n\n¡Que la búsqueda comience y que encuentren"
			" los tesoros digitales que tanto anhelan! ¡Buena suerte y"
			" disfruten de esta emocionante"
			" odisea cibernética!\n" << std::endl;
}

/*
void Consola::imprimirTablero(Tablero* tablero) {
    Lista<Lista<Lista<Casillero *>*>*>* casilleros = tablero->getTablero();

    for (int z = 0; z < casilleros->contarElementos(); ++z) {
        std::cout << "Capa " << z + 1 << ":" << std::endl;

        Lista<Lista<Casillero*>*>* capa = casilleros->obtener(z);

        for (int y = 0; y < capa->contarElementos(); ++y) {
            Lista<Casillero*>* fila = capa->obtener(y);

            for (unsigned int x = 0; x <= fila->contarElementos(); x++) {
                Casillero* casillero = fila->obtener(x);
                char ficha = casillero->getFicha();
                std::cout << ficha << " ";
            }

            std::cout << "\n";
        }

        std::cout << "\n";
    }
}
*/


Vector<int> * Consola::getDimensiones(){
	return this->dimensionesTablero;
}

void Consola::mostrarCartas(Lista<Carta*> * cartas){
	cartas->iniciarCursor();
	std::cout << "Tiene las siguientes cartas: " << std::endl;
	int i = 1;
	while(cartas->avanzarCursor()){
		std::cout << i << ") " << cartas->obtenerCursor()->getNombreCarta() << "\n";
		i++;
	}

}

bool Consola::tomaDecision(std::string consulta){
	char respuesta;
	bool decision;
	std::cout << consulta << "(s/n): ";
	std::cin >> respuesta;
	if(respuesta == 's'){
		decision = true;
	} else {
		decision = false;
	}
	return decision;
}

int Consola::seleccionarCarta(Lista<Carta*> * cartas){
	this->mostrarCartas(cartas);
	char entrada;
	std::cout << "Segun la lista seleccione el numero de la carta que desea utilizar: ";
	std::cin >> entrada;
	int posicion = entrada - 48;
	std::cout << "Selecciono la opcion: " << cartas->obtener(posicion)->getNombreCarta() << std::endl;
	return posicion;
}

void Consola::despedida(){

	std::cout << "Con líneas de código como compañeras y algoritmos como desafíos,"
			" llegamos al final de esta odisea digital. Gracias por sumergirte en el"
			" mundo que creé con cada función y bucle. Que este código siga"
			" ejecutándose en tu memoria como una experiencia inolvidable. "
			"¡Hasta la próxima compilación de diversión! 👾💾 ¡Adiós, jugador, y que"
			" tu camino esté siempre libre de errores!" << std::endl;
}

int Consola::mostrarTesoros(Jugador* jugador){

	std::cout << "Sus tesoros son:" << std::endl;
	jugador->getTesoros()->iniciarCursor();
	int i = 1;
	while(jugador->getTesoros()->avanzarCursor()){
		std::cout << "Tesoro " << i << std::endl;
		Tesoro* tesoro = jugador->getTesoros()->obtenerCursor();
		std::cout << tesoro->getPosicion()->get(1)<<","<<tesoro->getPosicion()->get(2)<<","<<tesoro->getPosicion()->get(3)<< std::endl;;
		i++;
	}
	std::cout << "Elija el numero de tesoro que quiere mover:";
	int numeroTesoro;
	std::cin >> numeroTesoro;
	return numeroTesoro;

}

Vector<int> * Consola::elegirDireccion(){

	char eleccion;
	Vector<int>* direccion = new Vector<int>(3);
	std::cout << "Ingrese la dirección (U, D, L, R, F, B) para mover la ficha: ";
	std::cin >> eleccion;

	switch (eleccion) {
	        case 'U':
	        case 'u':
	        	direccion->set(1,0);
	        	direccion->set(2,0);
	        	direccion->set(3,-1);  // Mover hacia arriba
	            break;
	        case 'D':
	        case 'd':
	        	direccion->set(1,0);
	        	direccion->set(2,0);
	        	direccion->set(3,1);  // Mover hacia abajo
	            break;
	        case 'L':
	        case 'l':
	        	direccion->set(1,-1);  // Mover hacia la izquierda
		        direccion->set(2,0);
		        direccion->set(3,0);
	            break;
	        case 'R':
	        case 'r':
	        	direccion->set(1,1);  // Mover hacia la derecha
		        direccion->set(2,0);
		        direccion->set(3,0);
	            break;
	        case 'F':
	        case 'f':
	        	direccion->set(1,0);
	        	direccion->set(2,-1);  // Mover hacia adelante
		        direccion->set(3,0);
	            break;
	        case 'B':
	        case 'b':
	        	direccion->set(1,0);
	        	direccion->set(2,1);  // Mover hacia atrás
		        direccion->set(3,0);
	            break;
	        default:
	            std::cout << "Dirección no válida." << std::endl;

	    }
	return direccion;
}

void Consola::ganador(int jugador){
	std::cout << "Felicidades jugador " << jugador << "!\nHaz ganado el juego!" << std::endl;
}
