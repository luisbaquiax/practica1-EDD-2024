//
// Created by Luis on 28/02/2024.
//

#include "ListaDoble.h"
#include <iostream>

/**
 * Agrega datos al final de la lista
 * @param card
 */
void ListaDoble::addFinal(Carta *&card) {
    Carta *nuevo = new Carta(card->color, card->simbolo, card->valorString, card->valor, card->id, card->bolteada);
    //Carta *nuevo = card;
    if (isEmpity()) {
        initial = nuevo;
        end = nuevo;
        size++;
    } else {
        Carta *temp = initial;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        /*temp->siguiente = nuevo;
        temp->anterior = temp->anterior;*/
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
        end = nuevo;
        //actualizamos el siguiente del nuevo.
        end->siguiente = nullptr;
        size++;
    }
}

Carta *ListaDoble::quitByID(int id) {
    return nullptr;
}

/**
 * Obtiene una carta en una posicion especifica de la lista
 * @param index
 * @return
 */
Carta *ListaDoble::getByIndex(int index) {
    Carta *temp = initial;
    for (int i = 0; i < size; ++i) {
        if (index == i) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

Carta *ListaDoble::quitEnd() {
    Carta *tem = nullptr;
    if (!isEmpity()) {
        if (size == 1) {
            tem = end;
            //delete end;
            initial = nullptr;
            end = nullptr;
            size = 0;
        } else {
            tem = end;
            end = end->anterior;
            end->siguiente = nullptr;
            size--;
        }
    }
    return tem;
}

bool ListaDoble::isEmpity() {
    return initial == nullptr;
}

void ListaDoble::printList() {
    Carta *temp = initial;
    int i = 0;
    printf("size %d\n", size);
    while (i < size) {
        std::cout << "Carta: " + temp->getPrint() << std::endl;
        temp = temp->siguiente;
        i++;
    }
    /*while (temp != nullptr) {
        std::cout << "Carta: " + temp->toString() << std::endl;
        temp = temp->siguiente;
    }*/
}