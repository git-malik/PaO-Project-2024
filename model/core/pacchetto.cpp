#include "./pacchetto.h"

time_t Pacchetto::currenttime = time(0);

Pacchetto::Pacchetto(){
    this->timestamp = Pacchetto::currenttime; // initialize timestamp
    Pacchetto::currenttime = Pacchetto::currenttime + 60; // decrement timestamp by 60 seconds
    this->valore = 0;//randomFloat();
}

bool Pacchetto::operator==(const Pacchetto &p){
    return this->timestamp == p.timestamp && this->valore == p.valore;
}

time_t Pacchetto::getTime() const{
    return this->timestamp;
}

float Pacchetto::getValore() const {
    return this->valore;
}
