

#include <iostream>
#include <stdio.h>  
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "Header.h"

using namespace std;


int punteroIzq = 0;
int punteroDer = 119;
int punteroJugador = 24;
bool GameOver = false;
int limit = 13;
int puntos = 0;
int opcion;

void gotoxy(int x, int y) {
    HANDLE hcon;
    COORD dwPos = { x, y };

    hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{

    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}



int getX() {
    int x, y;
    HANDLE hcon;
    COORD dwPos = { 0, 0 };

    hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    dwPos = GetConsoleCursorPosition(hcon);

    return dwPos.X;

}

int getY() {
    int x, y;
    HANDLE hcon;
    COORD dwPos = { 0, 0 };

    hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    dwPos = GetConsoleCursorPosition(hcon);

    return dwPos.Y;

}



int main()
{
    cout << "bienvenido a mi version de pacman" << endl;
    cout << "presione 1 para jugar 2 para salir" << endl;
    cin >> opcion;
    system("cls");
    if (opcion == 1)
    {
        
        mundo elMundo = mundo();
        elMundo.draw();

        Jugador player1 = Jugador();

        player1.draw();

        Comida laComida = Comida();

        Fantasma ghost1 = Fantasma();

        ghost1.draw();

        int checkMove;

        while (!GetAsyncKeyState(VK_ESCAPE) /*and GameOver == false*/) {

            // cout << ruta << endl;
            player1.getJugadorAction();
            // checkCrash();

            checkMove = elMundo.IsCollition(player1.getNewPosX(), player1.getNewPosY());
            if (checkMove == 2)  // Colision con comida
            {
                player1.move();
                //  player1.draw();
               //   player1.eatFood(laComida);
                player1.eatFood();
                elMundo.removeFood(player1.getPosX(), player1.getPosY());
            }

            else if (checkMove == 0) // No hay colision
            {
                player1.move();
                //   player1.draw();
            }

            ghost1.getAction();

            checkMove = elMundo.IsCollition2(ghost1.getNewPosX(), ghost1.getNewPosY());
            gotoxy(45, 0);
            cout << checkMove;
          
           

            // modifyRoute();
             //drawRoute();
            // puntos++;

            // auxX = getX();
             //auxY = getY();
            // if (auxY > 29) { gotoxy(0, auxY - 29); }
            // else {
            //     gotoxy(0, 0);

            // }

             //cout << "puntos: " << puntos;
             //gotoxy(auxX, auxY);

        }
    }
    else if (opcion == 2)
    {
        exit(0);
    }
    

    

    //   gotoxy(119, 29);

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
