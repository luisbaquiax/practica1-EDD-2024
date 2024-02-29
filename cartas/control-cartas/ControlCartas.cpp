//
// Created by Luis on 25/02/2024.
//

#include "ControlCartas.h"
#include "iostream"
#include <string>

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
        cola1.push(cartasAleatorias[i]);
    }

    printf("datos cola\n");
    cola1.printData();
}

void ControlCartas::addCartasToListas() {
    printf("agregando a la lista\n");
    lista1.addFinal(*&cartasAleatorias[24]);

    lista2.addFinal(cartasAleatorias[25]);
    lista2.addFinal(cartasAleatorias[26]);

    lista3.addFinal(cartasAleatorias[27]);
    lista3.addFinal(cartasAleatorias[28]);
    lista3.addFinal(cartasAleatorias[29]);

    lista4.addFinal(cartasAleatorias[30]);
    lista4.addFinal(cartasAleatorias[31]);
    lista4.addFinal(cartasAleatorias[32]);
    lista4.addFinal(cartasAleatorias[33]);

    lista5.addFinal(cartasAleatorias[34]);
    lista5.addFinal(cartasAleatorias[35]);
    lista5.addFinal(cartasAleatorias[36]);
    lista5.addFinal(cartasAleatorias[37]);
    lista5.addFinal(cartasAleatorias[38]);

    lista6.addFinal(cartasAleatorias[39]);
    lista6.addFinal(cartasAleatorias[40]);
    lista6.addFinal(cartasAleatorias[41]);
    lista6.addFinal(cartasAleatorias[42]);
    lista6.addFinal(cartasAleatorias[43]);
    lista6.addFinal(cartasAleatorias[44]);

    lista7.addFinal(cartasAleatorias[45]);
    lista7.addFinal(cartasAleatorias[46]);
    lista7.addFinal(cartasAleatorias[47]);
    lista7.addFinal(cartasAleatorias[48]);
    lista7.addFinal(cartasAleatorias[49]);
    lista7.addFinal(cartasAleatorias[50]);
    lista7.addFinal(cartasAleatorias[51]);


    //lista1.printList();
}

void ControlCartas::printColas() {

}

void ControlCartas::printListas() {

}

void ControlCartas::printPilas() {}