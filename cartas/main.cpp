#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "carta/Carta.h"
#include "utiles/Utiles.h"
#include "lista/ListaDoble.h"
#include <iostream>

#include "control-cartas/ControlCartas.h"

int main() {
    srand(time(0));
    printf("hola");
    ControlCartas c;
    Utiles utiles{};
    c.generarCartas();
    c.generarCartasAleatorias(utiles);
    c.addCardsToCola();
    c.addCartasToListas();
    c.lista1.printList();
    printf("\n");
    c.lista2.printList();
    printf("\n");
    c.lista3.printList();
    printf("\n");
    c.lista4.printList();
    printf("\n");
    c.lista5.printList();
    printf("\n");
    c.lista6.printList();
    printf("\n");
    c.lista7.printList();
    return 0;
}
