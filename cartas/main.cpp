#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "carta/Carta.h"
#include "utiles/Utiles.h"
#include "lista/ListaDoble.h"
#include <iostream>

#include "control-cartas/ControlCartas.h"
#include "game/Game.h"

int main() {
    srand(time(0));

    printf("hola\n");
    Game game;
    game.jugar();
    game.menu();

    /*ControlCartas c;
    Utiles utiles{};
    c.generarCartas();
    c.generarCartasAleatorias(utiles);
    c.addCardsToCola();
    c.addCartasToListas();

    c.llenarTablero();
    c.printListas(c.tablero,0, c.lista1);
    c.printListas(c.tablero,1, c.lista2);
    c.printListas(c.tablero,2, c.lista3);
    c.printListas(c.tablero,3, c.lista4);
    c.printListas(c.tablero,4, c.lista5);
    c.printListas(c.tablero,5, c.lista6);
    c.printListas(c.tablero,6, c.lista7);
    c.printTablero();*/
    return 0;
}
