//
// Created by Luis on 29/02/2024.
//

#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void Game::jugar() {
    Utiles utiles{};
    c.generarCartas();
    c.generarCartasAleatorias(utiles);

    c.addCardsToCola();
    //c.cola1.printData();

    c.addCartasToListas();
    c.llenarTablero();
    c.printAllList();
    printGame();

}

void Game::verCarta() {
    if (!c.cola1.isEmpity()) {
        Carta *temp = c.cola1.pop();
        //Carta *nuevo = new Carta(temp->color, temp->simbolo, temp->valorString, temp->valor, temp->id,
        //                       temp->bolteada);
        c.cola2.push(temp);
    } else {
        if (!c.cola2.isEmpity()) {
            //preguntar si se quiere reiniciar las colas
            int opcion = 0;
            printf("Reniciar cartas:\n");
            printf("1. Si\n");
            printf("2. No\n");
            scanf("%d", &opcion);
            if (opcion == 1) {
                while (!c.cola2.isEmpity()) {
                    Carta *temp = c.cola2.pop();
                    //Carta *nuevo = new Carta(temp->color, temp->simbolo, temp->valorString, temp->valor, temp->id,
                    //                        temp->bolteada);
                    c.cola1.push(temp);
                };
                c.cola2.vaciarCola();
            } else if (opcion == 2) {
                //omitimos
            } else {
                printf("Opcion invalida");
            }
        } else {
            printf("\nYa no hay cartas para mostrar\n");
        }
    }
}

void Game::printGame() {
    printf("*************************************************\n");
    c.printColas(c.cola1);

    c.printPilas(c.pilas[0]);
    c.llenarTablero();
    c.printAllList();
    c.printTablero();
}

void Game::moverCarta() {
    int columnaOrigen;
    int columnaDestino;

    printf("Seleccione columna origen y destino (ejemplo: 0 0):");
    scanf("%d %d", &columnaOrigen, &columnaDestino);
    if (columnaOrigen >= 0 && columnaDestino <= 6) {
        if (columnaOrigen != columnaDestino) {
            moveSelect(columnaOrigen, columnaDestino);
        } else {
            printf("Fila y columna deben ser diferentes.\n");
        }
    } else {
        printf("Fila y columna invalidos.\n");
    }
}

void Game::moveSelect(int origen, int destino) {
    if (c.listas[destino].isEmpity()) {
        if (c.listas[origen].end->valor == 13) {
            Carta *card = c.listas[origen].quitEnd();
            card->bolteada = true;
            c.listas[destino].addFinal(card);
            if (c.listas[origen].end != nullptr) {
                c.listas[origen].end->bolteada = true;
            }
            return;
        }
    }
    if (c.listas[origen].end->color != c.listas[destino].end->color) {
        if ((c.listas[origen].end->valor < c.listas[destino].end->valor) &&
            (c.listas[destino].end->valor - c.listas[origen].end->valor == 1)) {
            if (!c.listas[origen].isEmpity()) {
                Carta *temp = c.listas[origen].quitEnd();
                temp->bolteada = true;
                c.listas[destino].addFinal(temp);
                if (c.listas[origen].end != nullptr) {
                    c.listas[origen].end->bolteada = true;
                }
            }
        } else {
            printf("No se puede mover la carta.\n");
        }
    } else {
        printf("Se debe intercalar los colores.\n");
    }
}

void Game::moveCardToAZs() {
    int columna;
    printf("Ingrese el numero de columna para mover la carta hacia las AZ's:");
    scanf("%d", &columna);
    moveCardSeletedToAZs(columna);
}

void Game::moveCardSeletedToAZs(int columna) {
    if (!c.listas[columna].isEmpity()) {
        Carta *ultimo = c.listas[columna].quitEnd();
        Carta *card = new Carta(ultimo->color, ultimo->simbolo, ultimo->valorString, ultimo->valor, ultimo->id,
                                ultimo->bolteada);
        /*std::cout << "ultimo " + card->getPrint() << std::endl;
        std::cout << "card " + card->getPrint() << std::endl;*/
        c.listas[columna].printList();
        if (card->valor == 1) {
            if (card->simbolo == AZ_CORAZON) {
                c.pilas[0].push(card);
            } else if (card->simbolo == AZ_DIAM) {
                c.pilas[1].push(card);
            } else if (card->simbolo == AZ_TREBOL) {
                c.pilas[2].push(card);
            } else if (card->simbolo == AZ_ESPADA) {
                c.pilas[3].push(card);
            }
        } else {
            if (card->simbolo == CORAZON_ROJO) {
                if (!c.pilas[0].esVacia()) {
                    if (c.pilas[0].getTope()->valor < card->valor
                        && (card->valor - c.pilas[0].getTope()->valor == 1)) {
                        c.pilas[0].push(card);
                    } else {
                        printf("No se puede mover debido al orden ascendente de las cartas");
                    }
                }
            } else if (card->simbolo == DIAMANT_ROJO) {
                if (!c.pilas[1].esVacia()) {
                    if (c.pilas[1].getTope()->valor < card->valor
                        && (card->valor - c.pilas[1].getTope()->valor == 1)) {
                        c.pilas[1].push(card);
                    } else {
                        printf("No se puede mover debido al orden ascendente de las cartas");
                    }
                }
            } else if (card->simbolo == TREBOL_NEGRO) {
                if (!c.pilas[2].esVacia()) {
                    if (c.pilas[2].getTope()->valor < card->valor
                        && (card->valor - c.pilas[2].getTope()->valor == 1)) {
                        c.pilas[2].push(card);
                    } else {
                        printf("No se puede mover debido al orden ascendente de las cartas");
                    }
                }
            } else if (card->simbolo == ESPADA_NEGRO) {
                if (!c.pilas[3].esVacia()) {
                    if (c.pilas[3].getTope()->valor < card->valor
                        && (card->valor - c.pilas[3].getTope()->valor == 1)) {
                        c.pilas[3].push(card);
                    } else {
                        printf("No se puede mover debido al orden ascendente de las cartas");
                    }
                }
            }
        }
        if (c.listas[columna].end != nullptr) {
            c.listas[columna].end->bolteada = true;
        }
    }
}

void Game::moveCardFromColaToList() {
    int col;
    printf("Elige la columna destino:");
    scanf("%d", &col);
    c.moveCardToList(col);
}

void Game::moverCartas() {
    int col;
    int row;
    int destino;
    printf("Ingrese la fila desde donde se moveran las cartas: ");
    scanf("%d", &row);
    printf("Ingrese la columna origen y destino (Ej: 0 0): ");
    scanf("%d %d", &col, &destino);
    moverCartas(row, col, destino);
}

void Game::moverCartas(int fila, int columna, int destino) {
    if (columna != destino) {
        //validamos primero que la lista origen no esta vacia
        if (!c.listas[columna].isEmpity()) {
            if (c.listas[destino].isEmpity()) {
                if (c.listas[columna].getByIndex(fila)->valor == 13) {
                    //ejecutar movimiento
                    playMoveCards(fila, columna, destino);
                }
            } else {
                if (c.listas[destino].end->valor > c.listas[columna].getByIndex(fila)->valor
                    && (c.listas[destino].end->valor - c.listas[columna].getByIndex(fila)->valor == 1)) {
                    playMoveCards(fila, columna, destino);
                }
            }
        }
    } else {
        printf("La columna origne y destino deben ser diferentes ");
    }
}

void Game::playMoveCards(int fila, int columna, int destino) {
    if (c.listas[columna].getByIndex(fila) != nullptr) {
        if (c.listas[columna].getByIndex(fila)->bolteada) {
            //se guardan temporalmente las cartas
            Pila pilaAuxi;
            while (fila < c.listas[columna].size) {
                Carta *cartaAuxi = c.listas[columna].quitEnd();
                pilaAuxi.push(cartaAuxi);
            }
            //se mueven las cartas
            while (!pilaAuxi.esVacia()) {
                Carta *cartaAuxi = pilaAuxi.pop();
                c.listas[destino].addFinal(cartaAuxi);
            }
        }
    }
}

bool Game::youWin() {
    for (int i = 0; i < COLUMNAS; ++i) {
        if (!c.listas[i].isEmpity()) {
            return false;
        }
    }
    return true;
}

void Game::menu() {
    int opcion = 0;

    do {
        printf("OPCIONES DE MOVIMIENTO:\n");
        printf("1. Ver carta\n");
        printf("2. Mover carta\n");
        printf("3. Mover cartas (de filas de cartas a AZ's)\n");
        printf("4. Lista de carta a AZ's (lista a AZ's)\n");
        printf("5. De cola de cartas a AZ's (cola de cartas a AZ's)\n");
        printf("6. De cola de cartas a lista de cartas (cola a listas)\n");
        printf("7. Salir del juego\n");
        scanf("%d", &opcion);
        std::cout << "opcion " << opcion << std::endl;

        if (opcion == 1) {
            verCarta();
            printGame();
        } else if (opcion == 2) {
            moverCarta();
            printGame();
        } else if (opcion == 3) {
            moverCartas();
            printGame();
        } else if (opcion == 4) {
            moveCardToAZs();
            printGame();
        } else if (opcion == 5) {
            c.moveCardToAzWhitCola();
            printGame();
        } else if (opcion == 6) {
            moveCardFromColaToList();
            printGame();
        } else if (opcion == 7) {
            std::exit(0);
        }
    } while ((opcion > 0 && opcion < 8) || !youWin());

}