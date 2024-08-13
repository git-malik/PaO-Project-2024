#ifndef SENSOREBanda_H
#define SENSOREBanda_H

#include "sensore.h"
#include "pacchettoBanda.h"

class SensoreBanda : public Sensore{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<PacchettoBanda*> pacchetti;
    public:
        SensoreBanda(std::string name);
        SensoreBanda();
        std::string getId();
        std::string getName();
        void setName(const std::string& name);
        const std::vector<PacchettoBanda*>& getPacchetti();
        void misura();
};

#endif