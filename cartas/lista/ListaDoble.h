//
// Created by Luis on 28/02/2024.
//

#ifndef CARTAS_LISTADOBLE_H
#define CARTAS_LISTADOBLE_H

#include "../carta/Carta.h"

class ListaDoble {

private:
    Carta *initial;
    Carta *end;
public:
    ListaDoble() : size(0), initial(nullptr), end(nullptr) {}

    int size;

    void addFinal(Carta *&card);

    Carta *quitByID(int id);

    Carta *getByIndex(int index);


    Carta *getEnd() {
        return end;
    };

    void printList();

    bool isEmpity();

    Carta *getInitial() {
        return initial;
    };

    Carta *quitEnd();

};


#endif //CARTAS_LISTADOBLE_H
