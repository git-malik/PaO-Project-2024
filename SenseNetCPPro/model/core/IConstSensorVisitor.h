#ifndef ICONSTSENSORVISITOR_H
#define ICONSTSENSORVISITOR_H

class SensoreBanda;
class SensoreCarico;
class SensoreErrori;
class SensoreJitter;
class SensoreDelay;

class IConstSensorVisitor
{
public:
    virtual void visit(const SensoreBanda*) = 0;
    virtual void visit(const SensoreCarico*) = 0;
    virtual void visit(const SensoreErrori*) = 0;
    virtual void visit(const SensoreJitter*) = 0;
    virtual void visit(const SensoreDelay*) = 0;
};

#endif // ICONSTSENSORVISITOR_H