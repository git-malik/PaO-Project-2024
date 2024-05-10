#include "sensoreBanda.h"
#include <iostream>

int SensoreBanda::currentid = 1;

SensoreBanda::SensoreBanda(int bufferSize) : Sensore(bufferSize) {
    this->pacchetti = std::vector<PacchettoBanda*>();
    this->id = SensoreBanda::currentid;
    SensoreBanda::currentid += 1;
}

void SensoreBanda::misura() {
    PacchettoBanda * p = new PacchettoBanda();
    //this->this->pacchetti.push_back(p);

    this->pacchetti.push_back(p);
    std::rotate(this->pacchetti.rbegin(), this->pacchetti.rbegin() + 1, this->pacchetti.rend());
    for (int i = 0; i < this->pacchetti.size(); i++)
    {
        std::cout << "Pacchetto " << i << " Banda: " << this->pacchetti[i]->getValore() << std::endl;
    }
    //print size
    std::cout << "Size: " << this->pacchetti.size() << std::endl;
}

//getId
std::string SensoreBanda::getId() {
    return "BS#" + std::to_string(this->id);
}
