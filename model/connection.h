#ifndef CONNECTION_H
#define CONNECTION_H
#include "host.h"
#include "sensore.h"
#include <vector>
#include <cstring>

class Connection
{
private:
    std::string name;
    Host peer1;
    Host peer2;
    std::vector<Sensore*> sensori; // Change the type of the vector to hold pointers to const Sensore objects
public:
    Connection(std::string id, const Host& peer11, const Host& peer21);
    std::string getName() const;
    const std::vector<Sensore*>& getSensori(); // Change the return type of the getSensori() function
    const Host& getPeer1();
    const Host& getPeer2();
    void addSensore(const Sensore& sensore);
    void removeSensore(const Sensore& sensore);
    void removeSensoreAt(int index);


};

#endif
