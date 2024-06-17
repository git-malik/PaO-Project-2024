#ifndef SENSORECARICO_H
#define SENSORECARICO_H

#include "sensore.h"
#include "pacchettoCarico.h"

class SensoreCarico : public Sensore{
    private:
        
        static int currentid;
        std::string id;
        std::string name;
        std::vector<PacchettoCarico*> pacchetti;
        int bufferSize;
    public:
        SensoreCarico(int bufferSize);
        std::string getId();
        const std::vector<PacchettoCarico*>& getPacchetti();
        void misura();
};

#endif