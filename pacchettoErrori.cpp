#include "pacchettoErrori.h"
#include <ctime>
#include <iostream>

PacchettoErrori::PacchettoErrori(long int timestamp, float valore) : Pacchetto(timestamp, valore), timestamp(timestamp), valore(valore){};

PacchettoErrori::PacchettoErrori(): Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
}

PacchettoErrori::PacchettoErrori(float random): Pacchetto(){
    this->timestamp = Pacchetto::getTime();
    this->valore = random;
}

float PacchettoErrori::randomFloat()
{
    return (float)(rand()); 
}

long int PacchettoErrori::getTime() {
    //call parent function getTime
    return this->timestamp;
}

float PacchettoErrori::getValore() {
    //call parent function getValore
    return this->valore;
}
