#ifndef SENSOREDELAY_H
#define SENSOREDELAY_H

#include "sensore.h"
#include "pacchettoDelay.h"

class SensoreDelay : public Sensore{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<const PacchettoDelay*> pacchetti;
    public:
        SensoreDelay(const std::string& name);
        SensoreDelay();
        const std::string& getId() const override;
        const std::string& getName() const override;
        void setName(const std::string& name) override;
        const std::vector<const PacchettoDelay*>& getPacchetti() const;
        void misura() override;
        void accept(IConstSensorVisitor* visitor) const override;
        void accept(ISensorVisitor* visitor) override;
        ~SensoreDelay();
};

#endif