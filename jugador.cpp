#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "Header.h"

//void gotoxy(int x, int y) {
  // HANDLE hcon;
   // COORD dwPos = { x, y };

   // hcon = GetStdHandle(STD_OUTPUT_HANDLE);

   // dwPos.X = x;
   // dwPos.Y = y;
    //SetConsoleCursorPosition(hcon, dwPos);
//}

Jugador::Jugador() {

	vida = 3;
	posX = 40;
	posY = 14;
	puntaje = 0;
    action = 0;
}



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

void Jugador::limpiaPosicionJugador() {
    gotoxy(posX, posY);
    cout << " ";

}

void Jugador::draw() {
    gotoxy(posX, posY);
    cout << "(";
}

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

void Jugador::setPlayerPoints(int puntos) {
    
    puntaje = puntos;
}

int Jugador::getPlayerPoints() {

    return puntaje;
}

void Jugador::eatFood() {

    puntaje = puntaje + 5; //laComida.getPuntos();

}

//COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
//{
   // CONSOLE_SCREEN_BUFFER_INFO cbsi;
   // if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
   // {
   //     return cbsi.dwCursorPosition;
   // }
    //else
   // {
        // The function failed. Call GetLastError() for details.
       // COORD invalid = { 0, 0 };
       // return invalid;
    //}
//}
