#ifndef SENSOREBanda_H
#define SENSOREBanda_H

#include "sensore.h"
#include "pacchettoBanda.h"

class SensoreBanda : public Sensore{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<const PacchettoBanda*> pacchetti;
    public:
        SensoreBanda(const std::string& name);
        SensoreBanda();
        const std::string& getId() const override;
        const std::string& getName() const override;
        void setName(const std::string& name) override;
        const std::vector<const PacchettoBanda*>& getPacchetti() const;
        void misura() override;
        void accept(IConstSensorVisitor* visitor) const override;
        void accept(ISensorVisitor* visitor) override;
        ~SensoreBanda();
};

#endif
