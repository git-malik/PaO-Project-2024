#ifndef SENSOREJITTER_H
#define SENSOREJITTER_H

#include "sensore.h"
#include "pacchettoJitter.h"

class SensoreJitter : public Sensore{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<const PacchettoJitter*> pacchetti;
    public:
        SensoreJitter(const std::string& name);
        SensoreJitter();
        const std::string& getId() const override;
        const std::string& getName() const override;
        void setName(const std::string& name) override;
        const std::vector<const PacchettoJitter*>& getPacchetti() const;
        void misura() override;
        void accept(IConstSensorVisitor* visitor) const override;
        void accept(ISensorVisitor* visitor) override;
        ~SensoreJitter();

};

#endif