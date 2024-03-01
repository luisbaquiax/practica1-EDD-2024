//
// Created by Luis on 25/02/2024.
//

#include "ControlCartas.h"
#include "iostream"
#include <string>
#include <stdlib.h>

/**
 * Genera todas las 52 cartas
 */
void ControlCartas::generarCartas() {

    int valor = 1;
    std::string valorString = "";

    for (int i = 0; i < CANTIDAD; ++i) {
        if (valor == 14) {
            valor = 1;
        }
        cartas[i] = new Carta("", "", valorString, valor, (i + 1), false);

        if (valor == 11) {
            valorString = "J";
            cartas[i]->valorString = valorString;
        } else if (valor == 12) {
            valorString = "Q";
            cartas[i]->valorString = valorString;
        } else if (valor == 13) {
            valorString = "K";
            cartas[i]->valorString = valorString;
        } else {
            cartas[i]->valorString = std::to_string(valor);
        }
        valor++;
    }
    printf("\n");
    for (int i = 0; i < 13; ++i) {
        cartas[i]->color = ROJO;
        cartas[i]->simbolo = CORAZON_ROJO;
        if (cartas[i]->valor == 1) {
            cartas[i]->simbolo = AZ_CORAZON;
        }
    }
    valor = 1;
    valorString = "";
    for (int i = 13; i < 27; ++i) {
        cartas[i]->color = ROJO;
        cartas[i]->simbolo = DIAMANT_ROJO;
        if (cartas[i]->valor == 1) {
            cartas[i]->simbolo = AZ_DIAM;
        }
    }
    valor = 1;
    valorString = "";
    for (int i = 26; i < 39; ++i) {
        cartas[i]->color = NEGRO;
        cartas[i]->simbolo = TREBOL_NEGRO;
        if (cartas[i]->valor == 1) {
            cartas[i]->simbolo = AZ_TREBOL;
        }
    }
    valor = 1;
    valorString = "";
    for (int i = 39; i < 52; ++i) {
        cartas[i]->color = NEGRO;
        cartas[i]->simbolo = ESPADA_NEGRO;
        if (cartas[i]->valor == 1) {
            cartas[i]->simbolo = AZ_ESPADA;
        }
    }
    printf("cartas\n");
    for (int i = 0; i < CANTIDAD; ++i) {
        if (cartas[i]->valor == 1) {
            cartas[i]->valorString = "A";
        }
        std::cout << cartas[i]->toString() << std::endl;
    }

}

/**
 * Genera cartas aleatorias
 * @param utiles
 */
void ControlCartas::generarCartasAleatorias(Utiles utiles) {
    utiles.setNumbersRandom();
    printf("cartas aleatorias\n");
    for (int i = 0; i < CANTIDAD; ++i) {
        cartasAleatorias[i] = new Carta(cartas[utiles.numbersRandom[i]]->color,
                                        cartas[utiles.numbersRandom[i]]->simbolo,
                                        cartas[utiles.numbersRandom[i]]->valorString,
                                        cartas[utiles.numbersRandom[i]]->valor,
                                        cartas[utiles.numbersRandom[i]]->id,
                                        cartas[utiles.numbersRandom[i]]->bolteada);
        std::cout << (i + 1) << " " << cartasAleatorias[i]->toString() << std::endl;
    }
}

void ControlCartas::addCardsToCola() {
    //se agrega las 24 cartas aleatorias en la cola 1
    for (int i = 0; i < N_CARDS_COLA; i++) {
        cola1.push(*&cartasAleatorias[i]);
    }
    //printf("datos cola\n");
    //cola1.printData();
}

void ControlCartas::addCartasToListas() {
    printf("agregando a la lista\n");
    listas[0].addFinal(*&cartasAleatorias[24]);

    listas[1].addFinal(*&cartasAleatorias[25]);
    listas[1].addFinal(*&cartasAleatorias[26]);

    listas[2].addFinal(*&cartasAleatorias[27]);
    listas[2].addFinal(*&cartasAleatorias[28]);
    listas[2].addFinal(*&cartasAleatorias[29]);

    listas[3].addFinal(*&cartasAleatorias[30]);
    listas[3].addFinal(*&cartasAleatorias[31]);
    listas[3].addFinal(*&cartasAleatorias[32]);
    listas[3].addFinal(*&cartasAleatorias[33]);

    listas[4].addFinal(*&cartasAleatorias[34]);
    listas[4].addFinal(*&cartasAleatorias[35]);
    listas[4].addFinal(*&cartasAleatorias[36]);
    listas[4].addFinal(*&cartasAleatorias[37]);
    listas[4].addFinal(*&cartasAleatorias[38]);

    listas[5].addFinal(*&cartasAleatorias[39]);
    listas[5].addFinal(*&cartasAleatorias[40]);
    listas[5].addFinal(*&cartasAleatorias[41]);
    listas[5].addFinal(*&cartasAleatorias[42]);
    listas[5].addFinal(*&cartasAleatorias[43]);

    listas[6].addFinal(*&cartasAleatorias[44]);
    listas[6].addFinal(*&cartasAleatorias[45]);
    listas[6].addFinal(*&cartasAleatorias[46]);
    listas[6].addFinal(*&cartasAleatorias[47]);
    listas[6].addFinal(*&cartasAleatorias[48]);
    listas[6].addFinal(*&cartasAleatorias[49]);
    listas[6].addFinal(*&cartasAleatorias[50]);
    listas[6].addFinal(*&cartasAleatorias[51]);


    //lista1.printList();
}

void ControlCartas::printColas(Cola cola) {
    printf(">>>>>>>  Cartas a ver  >>>>>>> \n");
    if (!cola2.isEmpity()) {
        std::cout << SIM_BOLTEADA << ESPACIO << cola2.getEnd()->getPrint() << std::endl;
    } else {
        std::cout << SIM_BOLTEADA << ESPACIO << NADA << std::endl;
    }
    printf("\n");
}

void ControlCartas::printPilas(Pila pila) {
    printf(">>>>>>>  AZ's  >>>>>>> \n");
    std::cout << " " + AZ_CORAZON + " " + ESPACIO + "  " + AZ_DIAM + " " + ESPACIO + "  " + AZ_TREBOL + " " + ESPACIO +
                 "  " + AZ_ESPADA << ESPACIO
              << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (!pilas[i].esVacia()) {
            std::cout << pilas[i].getTope()->getPrint() << ESPACIO;
        } else {
            std::cout << NADA << ESPACIO;
        }
    }
    printf("\n");
}

void ControlCartas::printListas(std::string tablero[FILAS][COLUMNAS], int columna, ListaDoble lista) {
    int i = 0;
    Carta *temp = lista.initial;
    lista.end->bolteada = true;

    while (temp != nullptr) {
        if (!temp->bolteada) {
            tablero[i][columna] = SIM_BOLTEADA;
        } else {
            tablero[i][columna] = temp->getPrint();
        }
        temp = temp->siguiente;
        i++;
    }

}


void ControlCartas::llenarTablero() {
    printf("llenadno tablero\n");
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            tablero[i][j] = ESPACIO;
        }
    }
}

void ControlCartas::printTablero() {
    printf("Filas-Columnas\n ");
    for (int i = 0; i < COLUMNAS; ++i) {
        printf(" %d    ", (i));
    }
    printf("\n");
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            if (j == 0 && tablero[i][6] != ESPACIO) {
                printf("%d ", i);
            }
            printf("%s  ", tablero[i][j].c_str());
        }
        printf("\n");
    }
}