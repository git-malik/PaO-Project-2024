#include "connection.h"

Connection::Connection(std::string id, const Host& peer11, const Host& peer21) {
    this->name = id;
    this->peer1 = const_cast<Host&>(peer11);
    this->peer2 = const_cast<Host&>(peer21);
    this->sensori = std::vector<Sensore*>(); // Change the type of the vector to std::vector<Sensore*>
}

std::string Connection::getName() const{
    return this->name;
}

const Host& Connection::getPeer1() {
    return this->peer1;
}

const Host& Connection::getPeer2() {
    return this->peer2;
}


const std::vector<Sensore*>& Connection::getSensori(){
    return this->sensori;
}

void Connection::addSensore(const Sensore& sensore){
    if (this->sensori.size() == 3) {
        return;
    }
    //controllo per ogni elemento di classe diversa da fare per forza con il for
    for (int i = 0; i < (int)this->sensori.size(); i++) {
        if (typeid(*sensori[i]) == typeid(sensore)) {
            return;
        }
    }
    //cast sensore to Sensore*
    Sensore* s = const_cast<Sensore*>(&sensore);
    this->sensori.push_back(s);

}

void Connection::removeSensore(const Sensore& sensore){
    for (int i = 0; i < (int)this->sensori.size(); i++) {
        if (sensori[i] == &sensore) {
            this->sensori.erase(this->sensori.begin() + i);
            break;
        }
    }
}

void Connection::removeSensoreAt(int index) {
    if(index < 0 || index >= (int)this->sensori.size()) {
        return;
    }
    this->sensori.erase(this->sensori.begin() + index);
}

bool Connection::operator==(const Connection& other) const {
    return this->name == other.name && this->peer1 == other.peer1 && this->peer2 == other.peer2 && this->sensori == other.sensori;
}