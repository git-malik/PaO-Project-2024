#include "pacchettoCarico.h"
#include <ctime>
#include <iostream>

PacchettoCarico::PacchettoCarico(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoCarico::PacchettoCarico(){
    this->timestamp = Pacchetto::getTime();
    this->valore = Pacchetto::randomFloat();
};

long int PacchettoCarico::getTime() {
    //call parent function getTime
    return Pacchetto::getTime();
}

float PacchettoCarico::getValore() {
    //call parent function getValore
    return Pacchetto::getValore();
}
