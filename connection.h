#ifndef CONNECTION_H
#define CONNECTION_H
#include "host.h"
#include "sensore.h"
#include <vector>

class Connection
{
private:
    char* id;
    Host peer1;
    Host peer2;
    std::vector<Sensore*> sensori;
public:
    Connection(char* id, Host peer1, Host peer2);
    char* getId();
    std::vector<Sensore*> getSensori();
    Host* getPeers();
    void addSensore(Sensore* sensore);
    void removeSensore(Sensore* sensore);
    void removeSensoreAt(int index);
    ~Connection();
};

#endif