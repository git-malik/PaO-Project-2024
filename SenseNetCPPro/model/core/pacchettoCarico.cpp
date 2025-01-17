#include "pacchettoCarico.h"

PacchettoCarico::PacchettoCarico(){
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
};

float PacchettoCarico::randomFloat()
{
    return 1 + (float)(rand()) / ((float)(RAND_MAX / (100 - 1)));
}

time_t PacchettoCarico::getTime() const {
    return this->timestamp;
}

float PacchettoCarico::getValore() const {
    return this->valore;
}

