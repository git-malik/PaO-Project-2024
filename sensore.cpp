#include "./sensore.h"
//
 
int Sensore::id = 1;
//std::vector<Pacchetto*> pacchetti = std::vector<Pacchetto*>();

Sensore::Sensore(int bufferSize) {
    this->id = 0;
    this->bufferSize = bufferSize;
    this->id +=1;
}

int Sensore::getBufferSize() {
    return this->bufferSize;
}

// std::vector<Pacchetto*> Sensore::getPacchetti() {
//     return this->pacchetti;
// }
