#ifndef CONNECTION_H
#define CONNECTION_H

#include "host.h"
#include "sensore.h"
#include "sensoreBanda.h"
#include "sensoreCarico.h"
#include "sensoreErrori.h"
#include "sensoreJitter.h"
#include "sensoreDelay.h"
#include "ISensorVisitor.h"
#include <vector>
#include <cstring>

class Connection: public ISensorVisitor
{
private:
    std::string name;
    Host peer1;
    Host peer2;
    SensoreBanda* sensoreBanda;
    SensoreCarico* sensoreCarico;
    SensoreErrori* sensoreErrori;
    SensoreJitter* sensoreJitter;
    SensoreDelay* sensoreDelay;
    std::vector<Sensore*> sensori; 
public:
    Connection(const std::string& id, Host& peer11, Host& peer21);
    const std::string& getName() const;
    const std::vector<Sensore*>& getSensori() const;
    const Host& getPeer1() const;
    const Host& getPeer2() const;
    void addSensore(Sensore& sensore);
    void removeSensore(const Sensore& sensore);
    ~Connection();

    void visit(SensoreBanda* sensore) override;
    void visit(SensoreCarico* sensore) override;
    void visit(SensoreErrori* sensore) override;
    void visit(SensoreJitter* sensore) override;
    void visit(SensoreDelay* sensore) override;

    //operator== override
    bool operator==(const Connection& other) const;

};

#endif
