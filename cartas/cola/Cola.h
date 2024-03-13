//
// Created by Luis on 23/02/2024.
//

#ifndef HANOIGAME_COLA_H
#define HANOIGAME_COLA_H

#include "../carta/Carta.h"
#include <string>

class Cola {
public:
    Carta *first;
    Carta *end;

    Cola() : first(nullptr), end(nullptr) {};

    void push(Carta *&carta);

    void pushFirst(Carta *&carta);

    Carta *pop();

    Carta *popEnd();

    bool isEmpity() const;

    void printData();

    Carta *getEnd();

    void vaciarCola();
};


#endif //HANOIGAME_COLA_H
