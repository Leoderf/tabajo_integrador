#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include<cstdlib>
#include "Header.h"

//void gotoxyy(int x, int y) {
   // HANDLE hcon;
   // COORD dwPos = { x, y };

   // hcon = GetStdHandle(STD_OUTPUT_HANDLE);

   // dwPos.X = x;
   // dwPos.Y = y;
  //  SetConsoleCursorPosition(hcon, dwPos);
//}

Fantasma::Fantasma() {

    vida = 1;
    RosX = 37;
    RosY = 16;
    puntaje = 0;
    action = 0;

    newPosX < 129 > 0;
    newPosY < 29 > 0;

} 


bool Fantasma::move() {

    gotoxy(50, 0);
    cout << action;
    limpiaPosicion();
    if (action == 1)     //right
    {
        newRosX = RosX + 1;
    }
    if (action == 2)         //left
    {
        newRosX = RosX - 1;
    }
    if (action == 3)         //down
    {
        newRosY = RosY + 1;
    }
    if (action == 4)         //up
    {
        newRosY = RosY - 1;
    }

    // Actualiza RosX y RosY con los nuevos valores
    RosX = newRosX;
    RosY = newRosY;

    draw();
    Sleep(50);
    return true;
}

void Fantasma::limpiaPosicion() {
    gotoxy(RosX, RosY); 
    cout << " ";

}


void Fantasma::draw() {
    gotoxy(RosX, RosY);
    cout << "<";
}

//void getCloserTo(Jugador playey) 
//{
   // if (getPosX() < player.getPosX()) {
    //    setRosX() = getRosX() + 1
    //}
   // if (getPosX() > player.getPosX()) {
   //     setRosX() = getRosX() - 1
  //  }
//}
void Fantasma::getAction()
{
    newPosX = RosX;
    newPosY = RosY;
    //int action = 0;

    srand((unsigned)time(NULL));

    // Get a random number
     action = 1 + (rand() % 4);

    
   

    //if (action == 1)
   // {
    //    newPosX = posX + 1;
    //    action = 0;
    //}
   // if (action == 2)
   // {
    //    newPosX = posX - 1;
   //     action = 0;
    //}
    //if (action == 3)
   // {
    //    newPosY = posY + 1;
     //   action = 0;
    //}
   // if (action == 4)
   // {
    //   newPosY = posY - 1;
     //   action = 0;
    //}
    if (action == 1 && RosX + 1 < 129)
    {
        newPosX = RosX + 1;
    }
    else if (action == 2 && RosX - 1 >= 0)
    {
        newPosX = RosX - 1;
    }
    else if (action == 3 && RosY + 1 < 29)
    {
       newPosY = RosY + 1;
    }
    else if (action == 4 && RosY - 1 >= 0)
    {
        newPosY = RosY - 1;
    }
    gotoxy(40, 0);
    cout << action;

}
int Fantasma::getNewPosX() {
    return newPosX;
}
int Fantasma::getNewPosY() {
    return newPosY;
}
int Fantasma::getPosX() {
    return RosX;
}
int Fantasma::getPosY() {
    return RosY;
}

//COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
//{
  //  CONSOLE_SCREEN_BUFFER_INFO cbsi;
 //   if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
  //  {
  //      return cbsi.dwCursorPosition;
  //  }
  //  else
  //  {
        // The function failed. Call GetLastError() for details.
   //     COORD invalid = { 0, 0 };
   //     return invalid;
   // }
//}