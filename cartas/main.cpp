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

    return 0;
}
