#ifndef SENSORECARICO_H
#define SENSORECARICO_H

#include "sensore.h"
#include "pacchettoCarico.h"

class SensoreCarico : public Sensore{
    private:
        
        static int currentid;
        std::string id;
        std::string name;
        std::vector<const PacchettoCarico*> pacchetti;
    public:
        SensoreCarico(const std::string& name);
        SensoreCarico();
        const std::string& getId() const override;
        const std::string& getName() const override;
        void setName(const std::string& name) override;
        const std::vector<const PacchettoCarico*>& getPacchetti() const;
        void misura() override;
        void accept(IConstSensorVisitor* visitor) const override;
        void accept(ISensorVisitor* visitor) override;
        ~SensoreCarico();
};

#endif