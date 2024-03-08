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

Carta *Cola::popEnd() {
    /*Carta *tem = first;
    while (tem->siguiente!= nullptr){
        tem = tem->siguiente;
    }
    Carta *auxi = tem;
    end = tem;
    end->siguiente= nullptr;
    return auxi;*/
    if (first == end) {
        // Si solo hay un elemento en la cola
        Carta* temp = first;
        first = nullptr;
        end = nullptr;
        Carta *carta = temp;
        delete temp;
        return carta;
    } else {
        Carta* temp = first;
        while (temp->siguiente != end) {
            temp = temp->siguiente;
        }

        // Eliminamos el último elemento
        Carta* ultimo = end;
        end = temp;
        end->siguiente = nullptr;

        return ultimo;
    }
}

void Cola::printData() {
    Carta *temp = first;
    printf("datos-cola\n");
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