#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "model/core/sensore.h"
#include "model/core/host.h"
#include "model/core/connection.h"
#include "model/json/jsonManager.h"

class Controller {

public:
    Controller();
    ~Controller();

    void addSensore(Sensore* sensore, Connection* connection);
    void removeSensore(const Sensore* sensore);
    void editSensore(Sensore* sensore, const QString& newName); 
    std::vector<Sensore*> getSensori() const;
    const std::vector<Connection*>& getConnections() const;
    const std::vector<Host*>& getHosts() const;
    const std::vector<Connection*> getConnectionsByHost(const Host* host) const;
    const Host* getHostByName(const std::string& name) const;
    const std::vector<Sensore*> getSensoriByName(const std::string& name) const;

    const JSONManager& getJSONManager() const;

    // for json
    void clearSensors();
    bool saveJSON();
    bool exportDataJSON(const QString& filename);
    bool importDataJSON(const QString& filename);
    const QString& getExportFilename() const;
    const QString getLastErrorMessage();

private:
    std::vector<Connection*> connections;
    std::vector<Host*> hosts;
    JSONManager *saver;
    QString exportFilename;
    QString lastErrorMessage;
};

#endif
