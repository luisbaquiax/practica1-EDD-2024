//
// Created by Luis on 23/02/2024.
//

#include <iostream>
#include "Pila.h"
#include "../carta/Carta.h"

void Pila::push(Carta *carta) {
    Carta *nuevo =carta;
    nuevo->siguiente = tope;
    tope = nuevo;
}

Carta *Pila::pop() {
    if (!esVacia()) {
        Carta *temp = tope;
        tope = tope->siguiente;
        temp->siguiente = nullptr;
        return temp;
    }
}

bool Pila::esVacia() const {
    return tope == nullptr;
}

Carta *Pila::getTope() {
    return tope;
}

void Pila::verDatos() {
    Carta *temp = tope;
    while (temp != nullptr) {
        std::cout << "Valor: " << temp->getPrint() << std::endl;
        temp = temp->siguiente;
    }
}