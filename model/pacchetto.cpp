#include "./pacchetto.h"
#include <random>
#include <random>
#include <chrono>
#include <iostream>

Pacchetto::Pacchetto(){
    // TODO migliorare la generazione del timestamp
    this->timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
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
