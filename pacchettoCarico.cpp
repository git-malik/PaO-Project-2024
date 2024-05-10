#include "pacchettoCarico.h"
#include <ctime>
#include <random>
#include <iostream>

PacchettoCarico::PacchettoCarico(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoCarico::PacchettoCarico() : Pacchetto(){};

float PacchettoCarico::randomFloat()
{
    //call parent function randomFloat
    return Pacchetto::randomFloat();
}

long int PacchettoCarico::getTime() {
    //call parent function getTime
    return Pacchetto::getTime();
}

float PacchettoCarico::getValore() {
    //call parent function getValore
    return Pacchetto::getValore();
}
