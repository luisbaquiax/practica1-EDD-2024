//
// Created by Luis on 23/02/2024.
//
#include <iostream>
#include "Cola.h"
#include "../carta/Carta.h"

void Cola::push(Carta *&carta) {
    Carta *nuevo = carta;
    if (isEmpity()) {
        first = nuevo;
        end = nuevo;
    } else {
        end->siguiente = nuevo;
        end = nuevo;
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

bool Cola::isEmpity() const {
    return first == nullptr;
}