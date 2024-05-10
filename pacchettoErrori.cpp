#include "pacchettoErrori.h"
#include <ctime>
#include <random>
#include <iostream>

PacchettoErrori::PacchettoErrori(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoErrori::PacchettoErrori(): Pacchetto() {}

float PacchettoErrori::randomFloat()
{
    return 1+ (float)(rand()) + 99; 
}

long int PacchettoErrori::getTime() {
    //call parent function getTime
    return Pacchetto::getTime();
}

float PacchettoErrori::getValore() {
    //call parent function getValore
    return Pacchetto::getValore();
}
