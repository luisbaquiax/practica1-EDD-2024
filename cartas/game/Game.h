//
// Created by Luis on 29/02/2024.
//

#ifndef CARTAS_GAME_H
#define CARTAS_GAME_H

#include "../control-cartas/ControlCartas.h"
#include "../movimiento/Movimiento.h"
#include "../movimiento/ListMovment.h"

class Game {
public:
    ControlCartas c;

    ListMovment listMovment;
    void jugar();

    void verCarta();

    void printGame();

    void menu();

    void moverCarta();

    void moveSelect(int origen, int destino);

    void moveCardToAZs();

    void moveCardFromColaToList();

    void moveCardSeletedToAZs(int columna);

    void moverCartas();

    void moverCartas(int fila, int columna, int destino);

    void playMoveCards(int fila, int columna, int destino);

    bool youWin();

    void advanceMovement();

    void returnMovement();

    void viewNextCard();

    void viewPrevious();
};


#endif //CARTAS_GAME_H
