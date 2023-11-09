
#include "Carta.h"

Carta::Carta(){
	//establece un tipo de carta aleatorio
	this->tipoCarta = static_cast<nombreCarta>(rand() % 6);
}

Carta::Carta(nombreCarta tipoCarta){
	this->tipoCarta = tipoCarta;
}

Carta::~Carta(){
}

void Carta::jugarCarta(){
	//con switch(this->tipoCarta) estableccer lo que hace en este metodo cada una
}

std::string Carta::getNombreCarta(){
	std::string nombreCarta;
	switch(this->tipoCarta){
	case(BLINDAJE):
		nombreCarta = "Blindaje";
		break;
	case(RADAR):
		nombreCarta = "Radar";
		break;
	case(PARTIR):
		nombreCarta = "Partir";
		break;
	case(LADRON):
		nombreCarta = "Ladron";
		break;
	case(SNIPER):
		nombreCarta = "Sniper";
		break;
	case(ROBAR):
		nombreCarta = "Robar";
		break;
	default:
		break;
	}
	return nombreCarta;
}

