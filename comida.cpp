#include "Header.h"
//Creo la clase comida
Comida::Comida() {

	punto = 1;
	
}

int Comida::getPuntos()
{
	return punto;


}
int Comida::getPosX() {
	return posX;
}
int Comida::getPosY() {
	return posY;
}