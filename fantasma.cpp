#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include<cstdlib>
#include "Header.h"



Fantasma::Fantasma() {

    vida = 1;
    RosX = 37;
    RosY = 16;
    puntaje = 0;
    action = 0;
    step = 1;
    //newPosX < 129 > 0;
    //newPosY < 29 > 0;
    newRosX = RosX;
    newRosY = RosY;
} 

Fantasma::Fantasma(int X,int Y) {

    vida = 1;
    RosX = X;
    RosY = Y;
    puntaje = 0;
    action = 0;
    step = 1;

    newRosX = RosX;
    newRosY = RosY;
}

//Movimiento de los fantasmas por gotoxy
bool Fantasma::move() {

    gotoxy(50, 0);
    cout << "fact:" << action;
    limpiaPosicion();
    if (action == 1)     //right
    {
        RosX = RosX + step;
    }
    if (action == 2)         //left
    {
        RosX = RosX - step;
    }
    if (action == 3)         //down
    {
        RosY = RosY + step;
    }
    if (action == 4)         //up
    {
        RosY = RosY - step;
    }

    
    draw();
   // Sleep(50);
    return true;
}
//limpia la posicion del fantasma
void Fantasma::limpiaPosicion() {
    gotoxy(RosX, RosY); 
    cout << " ";

}

//Dibuja el nuevo fantasma
void Fantasma::draw() {
    gotoxy(RosX, RosY);
    cout << "<";
}
//Aca por medio de gotoxy hago que el fantasma intente acercarce al jugador todo lo posible 
void Fantasma::getAction(Jugador player)
{
    newRosX = RosX;
    newRosY = RosY;
    //int action = 0;

    srand((unsigned)time(NULL));

 
    int option = 1 + (rand() % 4);
    if (option == 1)  // achicamos distancia en X
    {
        if (player.getPosX() < RosX) { action = 2; }
        if (player.getPosX() > RosX) { action = 1; }
    }
    else if (option == 2) // achicamos distancia en Y
    {
        if (player.getPosY() < RosY) { action = 4; }
        if (player.getPosY() > RosY) { action = 3; }
    }
    else {
        action = 1 + (rand() % 4);
    }

    if (action == 1 && RosX + 1 < 129)      // agrandar en X
    {
        newRosX = RosX + 1;
    }
    else if (action == 2 && RosX - 1 >= 0)  // achicar en X
    {
        newRosX = RosX - 1;   
    }
    else if (action == 3 && RosY + 1 < 29) // agrandar en Y
    {
        newRosY = RosY + 1;
    }
    else if (action == 4 && RosY - 1 >= 0) // achicar en Y
    {
        newRosY = RosY - 1;
    }
    gotoxy(60, 0);
    cout << "fact:" << action << "-" << newRosX << "-" << newRosY;

}
//funciones para detectar coliciones
int Fantasma::getNewPosX() {
    return newRosX;
}
int Fantasma::getNewPosY() {
    return newRosY;
}
int Fantasma::getPosX() {
    return RosX;
}
int Fantasma::getPosY() {
    return RosY;
}
void Fantasma::setPosX(int X) {

    RosX = X;
    return;
}
void Fantasma::setPosY(int Y) {

    RosY = Y;
    return;
}

void Fantasma::colidedTo(int object) {

    if (object == COMIDA)
        step = 2;
    else
        step = 1;
}
