//
// Created by Luis on 25/02/2024.
//

#ifndef CARTAS_CARTA_H
#define CARTAS_CARTA_H

#include <string>

const std::string CORAZON_ROJO = "<3";
const std::string DIAMANT_ROJO = "<>";
const std::string TREBOL_NEGRO = "E3";
const std::string ESPADA_NEGRO = "!!";
const std::string ROJO = "R";
const std::string NEGRO = "N";
const std::string AZ_CORAZON = "<3";
const std::string AZ_DIAM = "<>";
const std::string AZ_TREBOL = "E3";
const std::string AZ_ESPADA = "!!";
const std::string SIM_BOLTEADA = "XXXXX";
const std::string ESPACIO = "     ";
const std::string NADA = "*****";


class Carta {
public:
    Carta *siguiente;
    Carta *anterior;

    std::string color;
    std::string simbolo;
    std::string valorString;
    int valor;
    int id;
    bool bolteada;

    Carta(const std::string &color,
          const std::string &simbolo,
          const std::string &valorString,
          int valor,
          int id,
          bool bolteada) :
            color(color),
            simbolo(simbolo),
            valorString(valorString),
            valor(valor),
            id(id),
            bolteada(bolteada),
            siguiente(nullptr),
            anterior(nullptr) {};

    std::string getPrint();

    std::string toString();
};


#endif //CARTAS_CARTA_H
