#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <string>
#include <vector>
#include "../core/sensoreBanda.h"
#include "../core/sensoreCarico.h"
#include "../core/sensoreErrori.h"
#include "../core/sensoreJitter.h"
#include "../core/sensoreDelay.h"
#include "../core/connection.h"

// JSON
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QString>

class JSONManager {
public:
    void exportJSON(const QString& filename, const std::vector<Connection*>& connections);
    std::vector<Connection*> loadJSON(const QString& filename);
};

#endif
