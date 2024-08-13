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
    public:
        SensoreCarico(std::string name);
        SensoreCarico();
        std::string getId();
        std::string getName();
        void setName(const std::string& name);
        const std::vector<PacchettoCarico*>& getPacchetti();
        void misura();
};

#endif