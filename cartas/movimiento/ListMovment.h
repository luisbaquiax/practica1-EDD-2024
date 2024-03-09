//
// Created by Luis on 07/03/2024.
//

#ifndef CARTAS_LISTMOVMENT_H
#define CARTAS_LISTMOVMENT_H

#include "Movimiento.h"

class ListMovment {
public:
    Movimiento *initial;
    Movimiento *end;

    ListMovment() : size(0), initial(nullptr), end(nullptr) {}

    int size;

    void addFinal(Movimiento *&movimiento);

    Movimiento *quitByID(int id);

    Movimiento *getByIndex(int index);


    Movimiento *getEnd() {
        return end;
    };

    void printList();

    bool isEmpity();

    Movimiento *getInitial() {
        return initial;
    };

    Movimiento *quitEnd();
};


#endif //CARTAS_LISTMOVMENT_H
