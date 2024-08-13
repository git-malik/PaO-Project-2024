#ifndef SENSOREERRORI_H
#define SENSOREERRORI_H

#include "sensore.h"
#include "pacchettoErrori.h"

class SensoreErrori : public Sensore{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<PacchettoErrori*> pacchetti;
    public:
        SensoreErrori(std::string name);
        SensoreErrori();
        std::string getId();
        std::string getName();
        void setName(const std::string& name);
        const std::vector<PacchettoErrori*>& getPacchetti();
        void misura();
};

#endif