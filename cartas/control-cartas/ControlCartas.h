//
// Created by Luis on 25/02/2024.
//

#ifndef CARTAS_CONTROLCARTAS_H
#define CARTAS_CONTROLCARTAS_H

#include "../carta/Carta.h"
#include "../utiles/Utiles.h"
#include "../cola/Cola.h"
#include "../lista/ListaDoble.h"

class ControlCartas {
public:
    Carta *cartas[CANTIDAD];
    Carta *cartasAleatorias[CANTIDAD];
    Cola cola1;
    Cola cola2;
    ListaDoble *lista1;
    ListaDoble *lista2;
    ListaDoble *lista3;
    ListaDoble *lista4;
    ListaDoble *lista5;
    ListaDoble *lista6;
    ListaDoble *lista7;

    void generarCartas();

    void generarCartasAleatorias(Utiles utiles);

    void addCardsToCola();

    void addCartasToListas();

};


#endif //CARTAS_CONTROLCARTAS_H
