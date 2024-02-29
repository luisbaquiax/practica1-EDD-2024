//
// Created by Luis on 25/02/2024.
//

#include <stdlib.h>
#include "../control-cartas/ControlCartas.h"

/**
 * Genera número aleatorio entre lower y upper inluyendo a upper
 * @param lower
 * @param upper
 * @return
 */
int Utiles::numberRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

bool Utiles::containNumber(int number) {
    for (int i = 0; i < CANTIDAD; ++i) {
        if (numbersRandom[i] == number) {
            return true;
        }
    }
    return false;
}

void Utiles::setNumbersRandom() {
    for (int i = 0; i < CANTIDAD; ++i) {
        int random = numberRandom(1, CANTIDAD);
        while (!containNumber(numbersRandom[i])) {
            random = numberRandom(1, CANTIDAD);
        }
        numbersRandom[i] = random;
    }
}