#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;
        mapcell cell [20][60];
        void draw();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        void drawAgujero();///Arlethe Esthepany Mendoza Guzmán 9959-21–1160
        void drawMounstro();///Leticia Eugenia sontay chanchavac 9491-21-9664
        void menuinicial();///José Rodrigo Pérez Cojon 9959-21-4557
        void drawInstrucc();///Carlos David Rojas Coronado 9959-21-504
        void drawCreditos();///José Rodrigo Pérez Cojon 9959-21-4557
        void losemonst();///Edwin Adony Montejo Martínez 9491-21-3898
        void historia();///Edwin Adony Montejo Martínez 9491-21-3898
        void siguientenivel();///Carlos David Rojas Coronado 9959-21-504
        virtual ~gamemap();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile();
        void loadniv2();
        void createMapToFile();
        void createniv2();
        int cont=0;
};

#endif // GAMEMAP_H
