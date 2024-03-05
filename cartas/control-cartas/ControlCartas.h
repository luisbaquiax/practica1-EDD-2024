//
// Created by Luis on 25/02/2024.
//

#ifndef CARTAS_CONTROLCARTAS_H
#define CARTAS_CONTROLCARTAS_H

#include "../carta/Carta.h"
#include "../utiles/Utiles.h"
#include "../cola/Cola.h"
#include "../pila/Pila.h"
#include "../lista/ListaDoble.h"
#include <string>

class ControlCartas {
public:
    Carta *cartas[CANTIDAD];
    Carta *cartasAleatorias[CANTIDAD];
    Cola cola1;
    Cola cola2;

    Pila pilas[4];


    ListaDoble listas[7];

    std::string tablero[FILAS][COLUMNAS];

    void generarCartas();

    void generarCartasAleatorias(Utiles utiles);

    void addCardsToCola();

    void addCartasToListas();

    void llenarTablero();

    void printListas(int columna, ListaDoble lista);

    void printColas(Cola cola);

    void printPilas(Pila pila);

    void printTablero();

    void printAllList();

    void moveCardToAzWhitCola();
    void moveCardToList(int &columna);


};


#endif //CARTAS_CONTROLCARTAS_H
