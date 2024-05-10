#include "./sensore.h"
//
 
int Sensore::id = 1;

Sensore::Sensore(int bufferSize) {
    this->id = 0;
    this->bufferSize = bufferSize;
    this->pacchetti = std::vector<Pacchetto*>();
    this->id +=1;
}

int Sensore::getBufferSize() {
    return this->bufferSize;
}

std::vector<Pacchetto*>& Sensore::getPacchetti() {
    return this->pacchetti;
}
