//
// Created by Luis on 04/03/2024.
//

#ifndef CARTAS_MOVIMIENTO_H
#define CARTAS_MOVIMIENTO_H

#include "../carta/Carta.h"

class Movimiento {
public:
    int tipo;
    int listaOrigen;
    int listaDestino;
    int numeroCola;
    Carta *carta;
    Movimiento *anterior;
    Movimiento *siguiente;
    void setCarta(Carta *&carta) {
        this->carta = carta;
    };

    void setTipo(int tipo) {
        this->tipo = tipo;
    };

    void setListOrigen(int listOrigin) {
        this->listaOrigen = listOrigin;
    };

    void setListDestino(int listDestino) {
        this->listaDestino = listDestino;
    };

    void setNumeroCola(int cola) {
        this->numeroCola = cola;
    };
};


#endif //CARTAS_MOVIMIENTO_H
