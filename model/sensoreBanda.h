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
        int bufferSize;
    public:
        SensoreBanda(int bufferSize);
        std::string getId();
        //std::string getName();
        const std::vector<PacchettoBanda*>& getPacchetti();
        void misura();
};

#endif