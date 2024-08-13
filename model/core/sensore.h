#include <vector>
#include <algorithm>
#include "pacchetto.h"
#include "pacchettoBanda.h"
#include <string>

#ifndef SENSORE_H
#define SENSORE_H
class Sensore
{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<Pacchetto*> pacchetti;
    public:
        Sensore(std::string name);
        Sensore();
        virtual std::string getId();
        virtual std::string getName();
        virtual void setName(const std::string& name);
        const std::vector<Pacchetto*>& getPacchetti();
        virtual void misura() = 0;
        Sensore& operator=(const Sensore& other);
        //operator==
        bool operator==(const Sensore& sensore) const;
        virtual ~Sensore();

};

#endif