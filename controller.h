#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/core/sensore.h"
#include "model/core/host.h"
#include "model/core/connection.h"
#include "model/json/jsonManager.h"

class Controller {

public:
    explicit Controller();
    ~Controller();

    void addSensore(Sensore* sensore);
    void removeSensore(Sensore* sensore);
    void editSensore(Sensore* sensore, const QString& newName); 
    void addConnection(Connection* connection);
    void removeConnection(Connection* connection);
    void addHost(Host* host);
    void removeHost(Host* host);
    const std::vector<Sensore*>& getSensori();
    const std::vector<Connection*>& getConnections();
    std::vector<Connection*> getConnectionsByHost(Host* host);
    Host* getHostByName(std::string name);
    const std::vector<Host*>& getHosts();
    JSONManager* getJSONManager();

    //operator= overload
    Controller& operator=(const Controller& other);

    // for json
    void clearSensors();
    bool saveJSON();
    bool exportDataJSON(QString filename);
    bool importDataJSON(QString filename);
    const QString getExportFilename();

private:
    std::vector<Sensore*> sensori;
    std::vector<Connection*> connections;
    std::vector<Host*> hosts;
    JSONManager *saver;
    QString exportFilename;
};

#endif // CONTROLLER_H
