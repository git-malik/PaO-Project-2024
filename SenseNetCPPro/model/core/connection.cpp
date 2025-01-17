#include "connection.h"

Connection::Connection(const std::string& id, Host& peer11, Host& peer21)
{
    this->name = id;
    this->peer1 = peer11;
    this->peer2 = peer21;
    this->sensoreBanda = nullptr;
    this->sensoreCarico = nullptr;
    this->sensoreErrori = nullptr;
    this->sensoreJitter = nullptr;
    this->sensoreDelay = nullptr;
    this->sensori = std::vector<Sensore*>(); // Change the type of the vector to std::vector<Sensore*>
}

const std::string& Connection::getName() const
{
    return this->name;
}

const Host& Connection::getPeer1() const
{
    return this->peer1;
}

const Host& Connection::getPeer2() const
{
    return this->peer2;
}

const std::vector<Sensore*>& Connection::getSensori() const
{
    return this->sensori;
}

void Connection::visit(SensoreBanda* sensore)
{
    if (sensoreBanda == nullptr) {
        sensoreBanda = sensore;
        sensori.push_back(sensoreBanda);
    }
}

void Connection::visit(SensoreCarico* sensore)
{
    if (sensoreCarico == nullptr) {
        sensoreCarico = sensore;
        sensori.push_back(sensoreCarico);
    }
}

void Connection::visit(SensoreErrori* sensore)
{
    if (sensoreErrori == nullptr) {
        sensoreErrori = sensore;
        sensori.push_back(sensoreErrori);
    }
}

void Connection::visit(SensoreJitter* sensore)
{
    if (sensoreJitter == nullptr) {
        sensoreJitter = sensore;
        sensori.push_back(sensoreJitter);
    }
}

void Connection::visit(SensoreDelay* sensore)
{
    if (sensoreDelay == nullptr) {
        sensoreDelay = sensore;
        sensori.push_back(sensoreDelay);
    }
}

void Connection::addSensore(Sensore& sensore)
{
    sensore.accept(this);
}

void Connection::removeSensore(const Sensore& sensore)
{
    sensori.erase(std::remove(sensori.begin(), sensori.end(), &sensore), sensori.end());
    if (&sensore == sensoreBanda) {
        delete sensoreBanda;
        sensoreBanda = nullptr;
    } else if (&sensore == sensoreCarico) {
        delete sensoreCarico;
        sensoreCarico = nullptr;
    } else if (&sensore == sensoreErrori) {
        delete sensoreErrori;
        sensoreErrori = nullptr;
    } else if (&sensore == sensoreJitter) {
        delete sensoreJitter;
        sensoreJitter = nullptr;
    } else if (&sensore == sensoreDelay) {
        delete sensoreDelay;
        sensoreDelay = nullptr;
    }
}

bool Connection::operator==(const Connection& other) const
{
    return this->name == other.name && this->peer1 == other.peer1 && this->peer2 == other.peer2;
}

Connection::~Connection()
{
    for (Sensore* s : sensori) {
        delete s;
    }
    sensori.clear();
}