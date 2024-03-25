#include "host.h"

Host::Host(char* id) {
    this->id = id;
}

char* Host::getId() {
    return this->id;
}

//redefinition of operator=
Host& Host::operator=(const Host& other) {
    this->id = other.id;
    return *this;
}

//redefinition of copy constructor
Host::Host(const Host& other) {
    this->id = other.id;
}

//redefinition of default constructor
Host::Host() {
    this->id = new char[1];
    this->id[0] = '\0';
}