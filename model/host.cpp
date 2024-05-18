#include "host.h"

int Host::hostId = 1;

Host::Host(){
    this->id = Host::hostId;
    this->name = "H"+std::to_string(id);
    Host::hostId += 1;
}

Host::Host(std::string name): Host(){
    this->name = name;
}

//redefinition of operator=
Host& Host::operator=(const Host& other) {
    this->id = other.id;
    this->name = other.name;
    return *this;
}

//redefinition of copy constructor
Host::Host(Host& other) {
    this->id = other.id;
    this->name = other.name;
}

//redefinition of default constructor

//redefinition of getId
int Host::getId() {
    return this->id;
}

//redefinition of getName
std::string Host::getName() const{
    return this->name;
}
