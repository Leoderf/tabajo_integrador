

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
bool GameOver ;
int limit = 13;
int puntos = 0;

//la funcion gotoxy
void gotoxy(int x, int y) {
    HANDLE hcon;
    COORD dwPos = { x, y };

    hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}





int main()
{ //Menu de inicio
    char opcion = ' ';
    while (opcion != '2')
    {
        opcion = ' ';
        GameOver = false;
        

        system("cls");
        cout << "bienvenido a mi version de pacman" << endl;
        gotoxy(23, 12);  cout << "--------------------------------------\n";
        gotoxy(23, 13);  cout << "-                                    -\n";
        gotoxy(23, 14);  cout << "-        \"BRACKET MAN\"               -\n";
        gotoxy(23, 15);  cout << "-                                    -\n";
        gotoxy(23, 16);  cout << "-        1) - Jugar                  -\n";
        gotoxy(23, 17);  cout << "-        2) - Salir                  -\n";
        gotoxy(23, 18);  cout << "--------------------------------------\n";

        do {
            opcion = _getch();

        } while (opcion != '1' and opcion != '2');// Detecta la tecla sin necesidad de escribirla y dar al enter

        system("cls");
        if (opcion == '1')
        {
            //Creo los objetos
            mundo elMundo = mundo();
            elMundo.draw();

            Jugador player1 = Jugador();

            player1.draw();

            Comida laComida = Comida();

            Fantasma ghost1 = Fantasma();

            ghost1.draw();

            Fantasma ghost2 = Fantasma(30, 3);

            ghost2.draw();


            int checkMove;

            //Ejecucion del juego
            while (!GetAsyncKeyState(VK_ESCAPE) and GameOver == false) {


                player1.getJugadorAction();

                //Deteccion de colision del jugador
                checkMove = elMundo.IsCollition(player1.getNewPosX(), player1.getNewPosY());
                if (checkMove == 2)  // Colision con comida
                {
                    player1.move();

                    player1.eatFood();
                    elMundo.removeFood(player1.getPosX(), player1.getPosY());
                }

                else if (checkMove == 0) // No hay colision
                {
                    player1.move();

                }


                ghost1.getAction(player1);





                //verifica si el fantasma puede moverse
                checkMove = elMundo.IsCollition(ghost1.getNewPosX(), ghost1.getNewPosY());




                if (checkMove == 0) // No hay colision
                {
                    ghost1.colidedTo(NONE);
                    ghost1.move();


                }
                if (checkMove == 2)// Si hay colision
                {

                    ghost1.colidedTo(COMIDA);
                    ghost1.move();
                }

                ///------------- fantasma 2
                ghost2.getAction(player1);

                //chequeo de colicion con la comida del fantasma
                checkMove = elMundo.IsCollition(ghost2.getNewPosX(), ghost2.getNewPosY());

                if (checkMove == 0) // No hay colision
                {
                    ghost2.move();

                }
                if (checkMove == 2)
                {
                    if (ghost2.getPosX() != ghost2.getNewPosX()) {

                        ghost2.setPosX(ghost2.getNewPosX() + 1);
                    }
                    else if (ghost2.getPosY() != ghost2.getNewPosY()) {

                        ghost2.setPosY(ghost2.getNewPosY() + 1);
                    }
                    else ghost2.move();
                }


                //chequeo de fin de juego
                if ((ghost1.getPosX() == player1.getPosX() and ghost1.getPosY() == player1.getPosY())
                    or
                    (ghost2.getPosX() == player1.getPosX() and ghost2.getPosY() == player1.getPosY())
                    )
                {
                    gotoxy(23, 12);  cout << "-------------------------------\n";
                    gotoxy(23, 13);  cout << "-                             -\n";
                    gotoxy(23, 14);  cout << "-        GAME   OVER          -\n";
                    gotoxy(23, 15);  cout << "-                             -\n";
                    gotoxy(23, 16);  cout << "-------------------------------\n";

                    GameOver = true;
                    Sleep(5000);
                }

                //Chequeo de comer la comida
                if ((player1.getPosX() == laComida.getPosX() and player1.getPosY() == laComida.getPosX()))
                {
                    player1.eatFood();
                }

                //Impresion de puntaje en pantalla
                gotoxy(80, 5);
                cout << "Puntaje:" << player1.getPlayerPoints();

                //Chequeo de victoria
                if (player1.getPlayerPoints() >= 40)
                {
                    gotoxy(23, 12);  cout << "-------------------------------\n";
                    gotoxy(23, 13);  cout << "-                             -\n";
                    gotoxy(23, 14);  cout << "-          YOU   WIN          -\n";
                    gotoxy(23, 15);  cout << "-                             -\n";
                    gotoxy(23, 16);  cout << "-------------------------------\n";

                    GameOver = true;
                    Sleep(5000);
                }

            }
    
        }
     //   else if (opcion == '2')
     //   {
     //       exit(0);

     //   }


    }
    

    Sleep(5000);
    system("cls");
    exit(0);
 }


