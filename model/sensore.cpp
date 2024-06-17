#include "./sensore.h"
//
 
int Sensore::id = 1;
//std::vector<Pacchetto*> pacchetti = std::vector<Pacchetto*>();

Sensore::Sensore(int bufferSize) {
    this->currentid = "S#"+std::to_string(Sensore::id);
    this->bufferSize = bufferSize;
    this->id +=1;
}

int Sensore::getBufferSize() {
    return this->bufferSize;
}

const std::vector<Pacchetto*>& Sensore::getPacchetti() {
    return this->pacchetti;
}

std::string Sensore::getName() {
    return this->name;
}

Sensore& Sensore::operator=(const Sensore& other) {
    this->id = other.id;
    this->bufferSize = other.bufferSize;
    return *this;
}

bool Sensore::operator==(const Sensore& sensore) const {
    return this->id == sensore.id;
}
