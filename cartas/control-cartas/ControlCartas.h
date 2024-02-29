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

class ControlCartas {
public:
    Carta *cartas[CANTIDAD];
    Carta *cartasAleatorias[CANTIDAD];
    Cola cola1;
    Cola cola2;

    Pila pila1;
    Pila pila2;
    Pila pila3;
    Pila pila4;

    ListaDoble lista1;
    ListaDoble lista2;
    ListaDoble lista3;
    ListaDoble lista4;
    ListaDoble lista5;
    ListaDoble lista6;
    ListaDoble lista7;

    void generarCartas();

    void generarCartasAleatorias(Utiles utiles);

    void addCardsToCola();

    void addCartasToListas();

    void printListas();

    void printColas();

    void printPilas();

};


#endif //CARTAS_CONTROLCARTAS_H
