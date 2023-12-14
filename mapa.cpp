
#include "Header.h"
#include <iostream>
#include <stdio.h> 


using namespace std;

  

mundo::mundo() {

   

   }
//Dibujo el mapa
void mundo::draw() {
    
 
    for (int i = 0; i <= 29; i++)
    {
        cout << mapa[i];
        
       
    }
   
}
//borra la comida despues de que el jugador la coma
void mundo::removeFood(int X, int Y) {
    mapa[Y][X] = ' ';
}
//las funciones que se encargan de las coliciones para los fantasmas y el jugador
int mundo::IsCollition(int X, int Y) {

    char entidad;
    entidad = mapa[Y][X];
    if (entidad == '@') return 1;
    if (entidad == '*') 
        return 2;

    return 0;
}

int mundo::IsCollition2(int RosX, int RosY) {
    char entidad;
    entidad = mapa[RosX][RosY];
    if (entidad == '@') return 1;
    if (entidad == '*') return 2;

    return 0;
}
