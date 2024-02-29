//
// Created by Luis on 25/02/2024.
//

#ifndef CARTAS_UTILES_H
#define CARTAS_UTILES_H
const int CANTIDAD = 52;
const int N_CARDS_COLA = 24;

class Utiles {
public:
    int numbersRandom[CANTIDAD];

    void setNumbersRandom();

    int numberRandom(int lower, int upper);

    bool containNumber(int number);
};


#endif //CARTAS_UTILES_H
