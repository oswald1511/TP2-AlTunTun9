
#include "Carta.h"

Carta::Carta(){
	//ver como hacer para que establezca un tipo de carta aleatorio
	this->tipoCarta = 0; //pongo asi para que no tire error ahora
}

Carta::Carta(std::string tipoCarta){
	this->tipoCarta = tipoCarta;
}

Carta::~Carta(){
}

void Carta::jugarCarta(std::string tipoCarta){
	//con switch(this->tipoCarta) estableccer lo que hace en este metodo cada una
}

