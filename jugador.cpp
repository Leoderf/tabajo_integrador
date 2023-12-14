#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "Header.h"



Jugador::Jugador() {

    
	vida = 3;
	posX = 38;  //40
	posY = 13;  //14
	puntaje = 0;
    action = 0;
    
}


//movimiento del jugador por medio de gotoxy
bool Jugador::move() {
    gotoxy(5, 0);
    cout << action;
    limpiaPosicionJugador();
    if (action == 1)     //right
    {
        posX = posX + 1;
    }
    if (action == 2)         //left
    {
        posX = posX - 1;
    }
    if (action == 3)         //down
    {
        posY = posY + 1;
    }
    if (action == 4)         //up
    {
        posY = posY - 1;
    }
    gotoxy(8, 0);
    cout << posX;
    gotoxy(12, 0);
    cout << posY;
    gotoxy(20, 0);
    cout << puntaje;

    draw();
    Sleep(50);
	return true;
}
//Funcion para borrar la posicion anterior del jugador
void Jugador::limpiaPosicionJugador() {
    gotoxy(posX, posY);
    cout << " ";

}
//Funcion para dibujar la nueva posicion del jugador
void Jugador::draw() {
    gotoxy(posX, posY);
    cout << "(";
}
//Aplico los inputs/entradas de las teclas al movimiento
void Jugador::getJugadorAction()
{
    newPosX = posX;
    newPosY = posY;
    action = 0;

    if (GetAsyncKeyState(VK_RIGHT))
    {
        newPosX = posX + 1;
        action = 1;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        newPosX = posX - 1;
        action = 2;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        newPosY = posY + 1;
        action = 3;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        newPosY = posY - 1;
        action = 4;
    }

    gotoxy(0, 0);
    cout << action;
    
}
//Funciones para detectar las coliciones
int Jugador::getNewPosX() {
    return newPosX;
}
int Jugador::getNewPosY() {
    return newPosY;
}
int Jugador::getPosX() {
    return posX;
}
int Jugador::getPosY() {
    return posY;
}
//puntaje del jugador
void Jugador::setPlayerPoints(int puntos) {
    
    puntaje = puntos;
}

int Jugador::getPlayerPoints() {

    return puntaje;
}
//La funcion de comer
void Jugador::eatFood() {

    puntaje = puntaje + 5; 


}
