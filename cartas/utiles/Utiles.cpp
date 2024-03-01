//
// Created by Luis on 25/02/2024.
//

#include <stdlib.h>
#include "../control-cartas/ControlCartas.h"
#include <time.h>
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

bool Utiles::containNumber(int number, int numbersRandom[CANTIDAD]) {
    for (int i = 0; i < CANTIDAD; ++i) {
        if (numbersRandom[i] == number) {
            return true;
        }
    }
    return false;
}

void Utiles::setNumbersRandom() {
    for (int i = 0; i < CANTIDAD; ++i) {
        numbersRandom[i] = -1;
    }
    for (int i = 0; i < CANTIDAD; ++i) {
        int random = numberRandom(0, CANTIDAD - 1);
        while (containNumber(random, numbersRandom)) {
            random = numberRandom(0, CANTIDAD - 1);
        }
        numbersRandom[i] = random;
    }
}