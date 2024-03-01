//
// Created by Luis on 23/02/2024.
//
#include <iostream>
#include "Cola.h"
#include "../carta/Carta.h"

void Cola::push(Carta *&carta) {
    Carta *nuevo = new Carta(carta->color, carta->simbolo, carta->valorString, carta->valor, carta->id,
                             carta->bolteada);
    //Carta *nuevo = carta;
    if (isEmpity()) {
        first = nuevo;
        end = nuevo;
    } else {
        end->siguiente = nuevo;
        end = nuevo;
        //nueva linea
        end->siguiente = nullptr;
    }
}

Carta *Cola::pop() {
    if (!isEmpity()) {
        Carta *temp = first;
        first = temp->siguiente;
        return temp;
    } else {
        return nullptr;
    }
}

void Cola::printData() {
    Carta *temp = first;
    while (temp != nullptr) {
        std::cout << " " << temp->toString() << std::endl;
        temp = temp->siguiente;
    }
}

void Cola::vaciarCola() {
    while (!isEmpity()) {
        pop();
    }
    first = nullptr;
    end = nullptr;
}

bool Cola::isEmpity() const {
    return first == nullptr;
}

Carta *Cola::getEnd() {
    return end;
}