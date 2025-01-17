#ifndef SENSOREERRORI_H
#define SENSOREERRORI_H

#include "sensore.h"
#include "pacchettoErrori.h"

class SensoreErrori : public Sensore{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<const PacchettoErrori*> pacchetti;
    public:
        SensoreErrori(const std::string& name);
        SensoreErrori();
        const std::string& getId() const override;
        const std::string& getName() const override;
        void setName(const std::string& name) override;
        const std::vector<const PacchettoErrori*>& getPacchetti() const;
        void misura() override;
        void accept(IConstSensorVisitor* visitor) const override;
        void accept(ISensorVisitor* visitor) override;
        ~SensoreErrori();
        
};

#endif