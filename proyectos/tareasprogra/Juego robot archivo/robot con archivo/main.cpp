#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void SaveFile(string Nombre, char map[10][10])
{
    ofstream FileMap("gamedat.txt");
    if(FileMap.is_open())
    {
        FileMap << Nombre << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
               FileMap << map[i][j];
            }
            FileMap << endl;
        }
    }
    FileMap.close();
    }
void drawMap(int posX,int posY,char map[10][10]){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(posX==j && posY==i)
        {
            cout<<"R";
        }
      else
      {
            cout<<map[i][j];
      }
    }
    cout<<endl;
  }
}
string OpenFile(char map[10][10])
{
    ifstream FileMap("gamedat.txt");
    string line;
    string name="No encontre nombre";
    int renglon = 0;
    int row = 0;

    if(FileMap.is_open())
    {
        while(getline(FileMap, line))
        {
            if(renglon == 0)
                name = line;
            else
            {
                for(int i = 0; i < 5; i++)
                {
                        map[row][i] = line[i];
                }
                row++;
            }
            renglon++;
        }

        FileMap.close();
    }
    else
    {
        cout << "Error. No se pudo abrir el archivo." << endl;
    }
    return name;
    }
int main(){


    int posX=3;
    int posY=3;
    char map[10][10]={{'1','1','1','1','1','1','1','1','1','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','1','1','1','1','1','1','1','1','1'}};

 char teclado;
  bool gameOver= false;
  char Input = ' ';
  string NamePlayer = "";
  NamePlayer = OpenFile(map);
  drawMap(posX,posY,map);
  while(!gameOver)
  {
    cout << "Esta listo(a)" << endl;
    cout << "Suerte en el juego, los controles son estos." <<endl;
    cout << "Controles Teclas --> w(arriba), a(izquierda), d(derecha) y s(abajo)" << endl;
    cout << "Controles Teclas --> p(Salida)" << endl;
    cin >> teclado;
    switch (teclado)
    {
    case 'a':
        if(posX > 0)
        {
            posX-=1;
        }
        break;
    case 'w':
        if(posY < 10)
        {
            posY+=1;
        }
        break;
    case 's':
        if (posY!=9)
        {
            posY+=1;
        }
        break;
    case 'p':
        gameOver=true;
    default:
        break;
    }
    drawMap(posX, posY, map);
}
return 0;
}
