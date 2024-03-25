#include "./sensore.h"
//

Sensore::Sensore(char* id, int bufferSize) {
    this->id = id;
    this->bufferSize = bufferSize;
    this->pacchetti = std::vector<Pacchetto>();
}

char* Sensore::getId() {
    return this->id;
}

int Sensore::getBufferSize() {
    return this->bufferSize;
}

std::vector<Pacchetto> Sensore::getPacchetti() {
    return this->pacchetti;
}

void Sensore::misura() {
}

Sensore::~Sensore() {
    delete this->id;
    this->pacchetti.clear();
}