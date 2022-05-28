#include <iostream>
#include <windows.h>

#include "player.h"
#include "mapcell.h"
#include "gamemap.h"

using namespace std;

int main()
{
//    system("color F0");
        ///EDWIN ADONY MONTEJO MARTÍNEZ 9491-21-3898
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022

 /*   wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 119, 60};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
 */
    gamemap map;
    player hero;
    map.drawPortada();

    map.draw();
    while(map.isGameOver==false)
    {
    //  cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
        //Dibujamos el mapa
        map.draw();
      }
      //map.draw();

    }

    return 0;
}
