#include "Consola.h"

Consola::Consola(){}

Consola::~Consola(){}

Vector<int>* Consola::pedirTamanioTablero(){

	unsigned int x, y, z;
	Vector<int>* dimensiones = new Vector<int>(3);

	std:: cout << "ingrese el tamaño del tablero, numero por numero" << std::endl;
	std::cin >> x;
	dimensiones->set(1,x);
	std::cin >> y;
	dimensiones->set(1,y);
	std::cin >> z;
	dimensiones->set(1,z);


	return dimensiones;
}

	Vector<int>* Consola::pedirPosicion(){
    
		Vector<int>* posicion = new Vector<int>(3);
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
			return posicion;
	}


	int Consola::pedirCantidadJugadores(){

		int cantidadJugadores;
		std::cout << "ingrese la cantdad de jugadores:" << std::endl;
		std::cin >> cantidadJugadores;

		return cantidadJugadores;
	}


	int Consola::pedirCantidadTesoros(){

		int cantidadTesoros;
				std::cout << "ingrese la cantdad de tesoros:" << std::endl;
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
			" odisea cibernética!" << std::endl;


}

void Consola::imprimirTablero(){

	//me fatla definir mas cosas para saber como hacer esto
}
