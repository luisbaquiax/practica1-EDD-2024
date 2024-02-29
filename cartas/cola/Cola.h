//
// Created by Luis on 23/02/2024.
//

#ifndef HANOIGAME_COLA_H
#define HANOIGAME_COLA_H

#include "../carta/Carta.h"
#include <string>

class Cola {
private:
    Carta *first;
    Carta *end;
public:
    Cola() : first(nullptr), end(nullptr) {};

    void push(Carta *&carta);

    Carta *pop();

    bool isEmpity() const;

    void printData();
};


#endif //HANOIGAME_COLA_H
