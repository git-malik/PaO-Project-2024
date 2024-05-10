#include "pacchettoBanda.h"
#include <ctime>
#include <random>
#include <iostream>

PacchettoBanda::PacchettoBanda(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoBanda::PacchettoBanda() : Pacchetto() {};

float PacchettoBanda::randomFloat()
{
    //call parent function randomFloat
    return Pacchetto::randomFloat();
}

long int PacchettoBanda::getTime() {
    //call parent function getTime
    return Pacchetto::getTime();
}

float PacchettoBanda::getValore() {
    //call parent function getValore
    return Pacchetto::getValore();
}
