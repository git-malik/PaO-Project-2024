#include "./pacchetto.h"
#include <random>
#include <ctime>
#include <iostream>

Pacchetto::Pacchetto(){
    // TODO migliorare la generazione del timestamp
    //generate timestamp between current time and current time - 1 minute
    this->timestamp = time(0) - (rand() % 60);
    this->valore = Pacchetto::randomFloat();
}

float Pacchetto::randomFloat()
{
    return 1 + (float)(rand()) / ((float)(RAND_MAX / (100 - 1)));
}

Pacchetto::Pacchetto(long int timestamp, float valore){
    this->timestamp = timestamp;
    this->valore = valore;
}

Pacchetto::Pacchetto(const Pacchetto &p){
    this->timestamp = p.timestamp;
    this->valore = p.valore;
}

//operator==
bool Pacchetto::operator==(const Pacchetto &p){
    return this->timestamp == p.timestamp && this->valore == p.valore;
}

long int Pacchetto::getTime() {
    return this->timestamp;
}

float Pacchetto::getValore() {
    return this->valore;
}
