#include "gamemap.h"
#include <iostream>
#include <fstream>
#include <conio.h>
//Implementacion de toda la funcionabilidad del mapa del juego

using namespace std;
gamemap::gamemap()
{
    //ctor
    playerCell = NULL;
    loadMapFromFile();
  //  loadniv2();
    isGameOver = false;
}
void gamemap::draw(){
    //system("cls");
    cout << "\n \n Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir \n " << endl;
    ifstream myFile("map.txt");
    if(myFile.is_open())
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                // Utilizar las celulas cuando se dibuja el mapa
                cout << cell [i][j].id;
            }
            cout << endl;
        }
    }
    else{
        cout << "Error FATAL: el archivo del mapa no pudo ser cargado" << endl;
    }

}
bool gamemap::setPlayerCell(int playerX, int playerY)
{
    bool x=0;
    string intent;
    if (cell[playerX][playerY].isBlockedCell() == false)
    {
        switch (cell[playerX][playerY].id ){
        case ('$'):

            drawVictoria();
            isGameOver = true;
            exit (0);
            return true;

        case('#'):
            int reset;
            drawAgujero();
            cout << "HAS PERDIDO!! :("<<endl;
            exit(0);
            return false;
        case('*'):
            cont = cont + 1;
            drawMounstro();
            if (cont<2){
                isGameOver = false;
                cout << "\t \t TE HAS ENCONTRADO AL P23, HUYE!!!! E INTENTA NO VOLVER A TOPARTELO \n\n\n\n\n";
                getch();
                getch();
                return false;
            }
            else {
                cout << "\t \t \t te has encontrado con el P23 dos veces :( \n\n";
                getch();
                getch ();
                losemonst();
                exit (0);
            }
        case('2'):
            siguientenivel();
            isGameOver = false;
            return false;

        default:
            if (playerCell != NULL)
            {
               /// Cambio permitira quitar los ceros en el camino del jugador, al traslador un cero a un char se convierte en espacio
                //playerCell->id='0';
                playerCell->id=0;
            }
            ///cout << "Las coordenadas del jugador estan en: " << playerX << "," << playerY << endl;
            ///Cambio de coordenadas para corregiro problema de los movimientos del jugador en el eje X
            //playerCell = &cell[playerY][playerX];
            playerCell = &cell[playerX][playerY];
            ///Simbolo del jugador en el mapa
            playerCell->id=219; //ascii 169
        }
        return true;
    }
    else
    {
        return false;
    }

}
void gamemap::loadMapFromFile()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("map.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            //cout << line << endl;
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0' )
                {
                    cell[row][p].id = 0;
                } else
                {
                    cell[row][p].id = line[p];
                }
                // Cambio para quitar ceros y colocar espacios en blanco en el mapa
                // cell[row][p].id = line[p];
            }
            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cout << "Desea crearlo? " << endl;
        cin >> userInput;
        if (userInput='s')
        {
            createMapToFile();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}

void gamemap::loadniv2()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("niv2.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            //cout << line << endl;
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0' )
                {
                    cell[row][p].id = 0;
                } else
                {
                    cell[row][p].id = line[p];
                }
                // Cambio para quitar ceros y colocar espacios en blanco en el mapa
                // cell[row][p].id = line[p];
            }
            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cout << "Desea crearlo? " << endl;
        cin >> userInput;
        if (userInput='s')
        {
            createniv2();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}


void gamemap::createMapToFile()
{
    ofstream myFile("map.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (i == 0 || i == 19)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 59)
                    {
                        myFile << "1";
                    } else
                    {
                        myFile << "0";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}


void gamemap::createniv2(){
    ofstream myFile("niv2.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (i == 0 || i == 19)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 59)
                    {
                        myFile << "1";
                    } else
                    {
                        myFile << "0";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}



void gamemap::drawPortada()
{
    string line;
    char userInput = ' ';
    ifstream myFile("portada.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        menuinicial();
        //system ("cls");
    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }
}


void gamemap::drawVictoria()
{
    system ("cls");
    string line;
    char userInput = ' ';
    ifstream myFile("premio.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        getchar();
        getchar();
        //n >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

void gamemap::drawAgujero()
{
   // system ("cls");
    string line;
    char userInput = ' ';
    ifstream myFile("agujero.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        //stem ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

void gamemap::drawMounstro()
{
  //  int flag;
    string line;
    char userInput = ' ';
    ifstream myFile("mounstro.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        getchar();
        getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

void gamemap::menuinicial()
{
    char userInput = ' ';
    bool x=0;
    while (x==0){
         cin >> userInput;
        switch(userInput){
        case '1':
                x=1;
                break;
        case '2':
                x=0;
                drawInstrucc();
                break;
        case '3':
                x=0;
                historia();
                break;
        case '4':
                x=0;
                drawCreditos();
                break;
        case '5':
                exit(0);
        default:
            cout << "\n\n\n\n ingrese un valor porfavor \n\n\n";
            x=0;
        }
        break;
    }
    if (x==0){
            drawPortada();
    }
}

void gamemap::drawInstrucc()
{
    //system ("cls");
    string line;
    char userInput = ' ';
    ifstream myFile("instrucciones.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
    getchar();
    getchar();
    //system ("cls");
    //drawPortada();
}

void gamemap::drawCreditos()
{
    //system ("cls");
    string line;
    char userInput = ' ';
    ifstream myFile("creditos.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
    getchar();
    getchar();
    //system ("cls");
//    clrscr();
    //drawPortada();
}

void gamemap :: siguientenivel(){
    string line;
    char userInput = ' ';
    ifstream myFile("siguienteniv.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
    getchar();
    getchar();
    loadniv2();
//    segundomapa();
    cout<<" SIGUE TU PUEDES!!!"<< endl;
    draw();

}


void gamemap :: losemonst(){
  //  int flag;
    string line;
    char userInput = ' ';
    ifstream myFile("lose.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
  //      getchar();
    //    getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

void gamemap :: historia (){
    string line;
    char userInput = ' ';
    ifstream myFile("CAP1.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
            getchar();
            getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
//    string line;
    //char userInput = ' ';
    ifstream File("CAP2.txt");
    if(File.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(File, line))
        {
            cout << line << endl;
        }
        File.close();
            getchar();
            getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
  //  string line;
    //char userInput = ' ';
    ifstream my("CAP3.txt");
    if(my.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(my, line))
        {
            cout << line << endl;
        }
        my.close();
            getchar();
            getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}


gamemap::~gamemap()
{
    //dtor
}
