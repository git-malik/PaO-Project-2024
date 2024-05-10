#ifndef SENSOREBanda_H
#define SENSOREBanda_H

#include "sensore.h"
#include "pacchettoBanda.h"

class SensoreBanda : public Sensore{
    private:
        static int currentid;
        int id;
        std::vector<PacchettoBanda*> pacchetti;
        int bufferSize;
    public:
        SensoreBanda(int bufferSize);
        std::string getId();
        void misura();
};

#endif