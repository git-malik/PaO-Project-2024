#include "./sensore.h"
//
 
int Sensore::currentid = 1;
//std::vector<Pacchetto*> pacchetti = std::vector<Pacchetto*>();

Sensore::Sensore(const std::string& name) {
    this->pacchetti = std::vector<const Pacchetto*>();
    this->id = "S#"+std::to_string(Sensore::currentid);
    this->name = name;
    Sensore::currentid += 1;
}

Sensore::Sensore() {
    this->pacchetti = std::vector<const Pacchetto*>();
    this->id = "S#"+std::to_string(Sensore::currentid);
    this->name = "Generic Sensor";
    Sensore::currentid += 1;
}

/* const std::vector<const Pacchetto*>& Sensore::getPacchetti() const {
    return this->pacchetti;
} */

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

const std::string& Sensore::getId() const {
    return this->id;
}

const std::string& Sensore::getName() const {
    return this->name;
}


Sensore::~Sensore() {
    for (const Pacchetto* p : this->pacchetti) {
        delete p;
    }
    this->pacchetti.clear();
}
