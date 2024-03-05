//
// Created by Luis on 25/02/2024.
//

#include "Carta.h"

std::string Carta::getPrint() {
    std::string auxi = "";
    if (valor < 10 || valor > 10) {
        auxi = valorString + simbolo + color;
    } else {
        auxi = valorString + simbolo + color;
    }
    return auxi;
}

std::string Carta::toString() {
    std::string bolteadaStr = bolteada ? "true" : "false";
    return "id " + std::to_string(id) + " " +
           "val " + std::to_string(valor) + " " +
           "pri " + getPrint() + " ";
}