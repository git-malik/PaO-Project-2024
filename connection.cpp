#include "connection.h"
#include "host.h"
#include <vector>

Connection::Connection(char* id, Host peer1, Host peer2) {
    this->id = id;
    this->peer1 = peer1;
    this->peer2 = peer2;
    this->sensori = std::vector<Sensore*>();
}

char* Connection::getId() {
    return this->id;
}

Host* Connection::getPeers(){
    Host* peers = new Host[2];
    peers[0] = this->peer1;
    peers[1] = this->peer2;
    return peers;
}

std::vector<Sensore*> Connection::getSensori() {
    return this->sensori;
}

void Connection::addSensore(Sensore* sensore) {
    this->sensori.push_back(sensore);
}

void Connection::removeSensore(Sensore* sensore) {
    for (int i = 0; i < (int)this->sensori.size(); i++) {
        if (sensori[i] == sensore) {
            this->sensori.erase(this->sensori.begin() + i);
            break;
        }
    }
}
