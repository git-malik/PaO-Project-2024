#include "pacchettoCarico.h"
#include <ctime>
#include <iostream>

PacchettoCarico::PacchettoCarico(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoCarico::PacchettoCarico(){
    this->timestamp = Pacchetto::getTime();
    this->valore = Pacchetto::randomFloat();
};

long int PacchettoCarico::getTime() {
    return this->timestamp;
}

float PacchettoCarico::getValore() {
    return this->valore;
}
