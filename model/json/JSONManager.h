#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <string>
#include <vector>
#include "../core/sensoreBanda.h"
#include "../core/sensoreCarico.h"
#include "../core/sensoreErrori.h"
#include "../core/connection.h"
#include "./saveException.h"

// JSON
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QString>

class JSONManager {
public:
    JSONManager();
    ~JSONManager();

    void exportJSON(QString filename, std::vector<Connection*> connections) throw();
    std::vector<Connection*> loadJSON(QString filename) throw();

private:

};

#endif // JSONMANAGER_H
