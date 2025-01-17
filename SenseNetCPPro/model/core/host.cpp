#include "host.h"

int Host::hostId = 1;

Host::Host(){
    this->name = "H"+std::to_string(Host::hostId);
    Host::hostId += 1;
}

Host::Host(const std::string& name): Host(){
    this->name = name;
}

Host& Host::operator=(const Host& other) {
    this->name = other.name;
    return *this;
}

Host::Host(Host& other) {
    this->name = other.name;
}


const std::string& Host::getName() const{
    return this->name;
}

bool Host::operator==(const Host& other) const {
    return this->name == other.name;
}
