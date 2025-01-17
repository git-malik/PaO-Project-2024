#ifndef ISENSORVISITOR_H
#define ISENSORVISITOR_H

class SensoreBanda;
class SensoreCarico;
class SensoreErrori;
class SensoreJitter;
class SensoreDelay;

class ISensorVisitor
{
public:
    virtual void visit(SensoreBanda*) = 0;
    virtual void visit(SensoreCarico*) = 0;
    virtual void visit(SensoreErrori*) = 0;
    virtual void visit(SensoreJitter*) = 0;
    virtual void visit(SensoreDelay*) = 0;

    virtual ~ISensorVisitor() = default;
};

#endif // ISENSORVISITOR_H