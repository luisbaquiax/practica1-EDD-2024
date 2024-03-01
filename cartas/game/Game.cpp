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
    c.printListas(c.tablero, 0, c.listas[0]);
    c.printListas(c.tablero, 1, c.listas[1]);
    c.printListas(c.tablero, 2, c.listas[2]);
    c.printListas(c.tablero, 3, c.listas[3]);
    c.printListas(c.tablero, 4, c.listas[4]);
    c.printListas(c.tablero, 5, c.listas[5]);
    c.printListas(c.tablero, 6, c.listas[6]);

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

    c.printTablero();
}

void Game::moverCarta() {
    int columnaOrigen = 0;
    int columnaDestino = 0;

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
    ListaDoble listOrigen = c.listas[origen];
    ListaDoble listDestino = c.listas[destino];
    if (listOrigen.getEnd()->color != listDestino.getEnd()->color) {
        if (listOrigen.getEnd()->valor < listDestino.getEnd()->valor) {

        } else {
            printf("No se puede mover la carta.\n");
        }
    } else {
        printf("Se debe intercalar los colores.\n");
    }
}

void Game::moveCardToAZs() {

}

void Game::menu() {
    int opcion = 0;

    do {
        printf("OPCIONES DE JUEGO:\n");
        printf("1. Ver carta\n");
        printf("2. Mover carta\n");
        printf("3. Mover cartas (de filas de cartas a AZ's)\n");
        printf("4. Mover carta a la ilera de AZ's (de Cartas a AZ's)\n");
        printf("5. Salir del juego\n");
        scanf("%d", &opcion);
        std::cout << "opcion " << opcion << std::endl;

        if (opcion == 1) {
            verCarta();
            printGame();
        } else if (opcion == 2) {
            moverCarta();
            printGame();
        } else if (opcion == 3) {
            printGame();
        } else if (opcion == 4) {
            printGame();
        } else if (opcion == 5) {
            std::exit(0);
        }
    } while (opcion > 0 && opcion < 5);

}