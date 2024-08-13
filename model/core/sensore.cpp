#include "./sensore.h"
//
 
int Sensore::currentid = 1;
//std::vector<Pacchetto*> pacchetti = std::vector<Pacchetto*>();

Sensore::Sensore(std::string name) {
    this->pacchetti = std::vector<Pacchetto*>();
    this->id = "S#"+std::to_string(Sensore::currentid);
    this->name = name;
    Sensore::currentid += 1;
}

Sensore::Sensore() {
    this->pacchetti = std::vector<Pacchetto*>();
    this->id = "S#"+std::to_string(Sensore::currentid);
    this->name = "Generic Sensor";
    Sensore::currentid += 1;
}

const std::vector<Pacchetto*>& Sensore::getPacchetti() {
    return this->pacchetti;
}

Sensore& Sensore::operator=(const Sensore& other) {
    this->id = other.id;
    this->name = other.name;
    return *this;
}

bool Sensore::operator==(const Sensore& sensore) const {
    return this->id == sensore.id;
}

void Sensore::setName(const std::string& newName) {
    this->name = newName;
}

std::string Sensore::getId() {
    return this->id;
}

std::string Sensore::getName() {
    return this->name;
}


Sensore::~Sensore() {
}