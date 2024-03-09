//
// Created by Luis on 07/03/2024.
//

#include "ListMovment.h"
#include <iostream>

void ListMovment::addFinal(Movimiento *&movimiento) {
    Movimiento *nuevo = movimiento;
    //Carta *nuevo = card;
    if (isEmpity()) {
        initial = nuevo;
        end = nuevo;
        size++;
    } else {
        Movimiento *temp = initial;
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

Movimiento *ListMovment::quitByID(int id) {
    return nullptr;
}

/**
 * Obtiene un movimiento en una posicion especifica de la lista
 * @param index
 * @return
 */
Movimiento *ListMovment::getByIndex(int index) {
    Movimiento *temp = initial;
    for (int i = 0; i < size; ++i) {
        if (index == i) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

Movimiento *ListMovment::quitEnd() {
    Movimiento *tem = nullptr;
    if (!isEmpity()) {
        if (size == 1) {
            tem = end;
            //delete end;
            initial = nullptr;
            end = nullptr;
            size = 0;
        } else {
            size--;
            tem = end;
            end = end->anterior;
            //delete end->siguiente;
            end->siguiente = nullptr;
        }
    }
    return tem;
}

/**
 * Retorna true si la lista está vacía, o false cuando tiene al menos un elemento.
 * @return
 */
bool ListMovment::isEmpity() {
    return initial == nullptr;
}

void ListMovment::printList() {
    Movimiento *temp = initial;
    int i = 0;
    printf("size %d\n", size);
    /*while (i < size) {
        std::cout << "Carta: " + temp->getPrint() << std::endl;
        temp = temp->siguiente;
        i++;
    }*/
    while (temp != nullptr) {
        std::cout << &"Mov: "[temp->tipo] << std::endl;
        temp = temp->siguiente;
    }
}