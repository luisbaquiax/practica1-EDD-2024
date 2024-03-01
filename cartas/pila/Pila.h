//
// Created by Luis on 23/02/2024.
//

#ifndef HANOIGAME_PILA_H
#define HANOIGAME_PILA_H

#include "../carta/Carta.h"
#include <string>


class Pila {
private:
    Carta *tope;
public:
    Pila() : tope(nullptr) {};

    void push(Carta *&carta);

    Carta *pop();

    bool esVacia() const;

    void verDatos();

    Carta *getTope();
};


#endif //HANOIGAME_PILA_H
