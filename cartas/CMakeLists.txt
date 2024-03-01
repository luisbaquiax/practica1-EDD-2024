cmake_minimum_required(VERSION 3.27)
project(cartas)

set(CMAKE_CXX_STANDARD 17)

add_executable(cartas main.cpp
        carta/Carta.cpp
        carta/Carta.h
        cola/Cola.h
        cola/Cola.cpp
        pila/Pila.cpp
        pila/Pila.h
        control-cartas/ControlCartas.cpp
        control-cartas/ControlCartas.h
        utiles/Utiles.cpp
        utiles/Utiles.h
        lista/ListaDoble.cpp
        lista/ListaDoble.h
        game/Game.cpp
        game/Game.h
)
