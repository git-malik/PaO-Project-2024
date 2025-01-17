#include <vector>
#include <algorithm>
#include "pacchetto.h"
#include "pacchettoBanda.h"
#include "IConstSensorVisitor.h"
#include "ISensorVisitor.h"
#include <string>

#ifndef SENSORE_H
#define SENSORE_H
class Sensore
{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<const Pacchetto*> pacchetti;
    public:
        Sensore(const std::string& name);
        Sensore();
        virtual const std::string& getId() const;
        virtual const std::string& getName() const;
        virtual void setName(const std::string& name);
        const std::vector<const Pacchetto*>& getPacchetti() const;
        virtual void misura() = 0;
        virtual void accept(IConstSensorVisitor* visitor) const = 0;
        virtual void accept(ISensorVisitor* visitor) = 0;
        virtual Sensore& operator=(const Sensore& other);
        virtual bool operator==(const Sensore& sensore) const;
        virtual ~Sensore();

};

#endif