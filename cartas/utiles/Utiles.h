//
// Created by Luis on 25/02/2024.
//

#ifndef CARTAS_UTILES_H
#define CARTAS_UTILES_H
const int CANTIDAD = 52;
const int N_CARDS_COLA = 24;
const int FILAS = 13;
const int COLUMNAS = 7;

class Utiles {
public:
    int numbersRandom[CANTIDAD];

    void setNumbersRandom();

    int numberRandom(int lower, int upper);

    bool containNumber(int number, int nums[CANTIDAD]);
};


#endif //CARTAS_UTILES_H
