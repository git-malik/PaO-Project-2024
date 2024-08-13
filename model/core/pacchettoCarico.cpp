#include "pacchettoCarico.h"

PacchettoCarico::PacchettoCarico(time_t timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoCarico::PacchettoCarico(){
    this->timestamp = Pacchetto::getTime();
    this->valore = Pacchetto::randomFloat();
};

time_t PacchettoCarico::getTime() {
    return this->timestamp;
}

float PacchettoCarico::getValore() {
    return this->valore;
}
