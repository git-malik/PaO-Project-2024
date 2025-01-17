#include "controller.h"

Controller::Controller()
{
    saver = new JSONManager();
    exportFilename = "";
    hosts.push_back(new Host("A"));
    hosts.push_back(new Host("B"));
    hosts.push_back(new Host("C"));
    hosts.push_back(new Host("D"));
    hosts.push_back(new Host("E"));
    hosts.push_back(new Host("F"));
    hosts.push_back(new Host("G"));

    connections.push_back(new Connection("A-B", *hosts[0], *hosts[1]));
    connections.push_back(new Connection("B-C", *hosts[1], *hosts[2]));
    connections.push_back(new Connection("C-D", *hosts[2], *hosts[3]));
    connections.push_back(new Connection("D-E", *hosts[3], *hosts[4]));
    connections.push_back(new Connection("B-F", *hosts[1], *hosts[5]));
    connections.push_back(new Connection("A-D", *hosts[0], *hosts[3]));
    connections.push_back(new Connection("C-F", *hosts[2], *hosts[5]));
}

void Controller::addSensore(Sensore* sensore, Connection* c)
{
    for (Connection* connection : connections) {
        if (connection == c) {
            c->addSensore(*sensore);
            return;
        }
    }
}

/**
 * @brief This function checks if the sensor is present in one of the connections and removes it.
 * @param sensore the sensor to compare with the sensors in the connections
 */
void Controller::removeSensore(const Sensore* sensore)
{
    for (Connection* connection : connections) {
        connection->removeSensore(*sensore);
    }
}

std::vector<Sensore*> Controller::getSensori() const
{
    std::vector<Sensore*> sensori;
    for (Connection* connection : connections) {
        for (Sensore* s : connection->getSensori()) {
            sensori.push_back(s);
        }
    }
    return sensori;
}

const std::vector<Host*>& Controller::getHosts() const
{
    return hosts;
}

const std::vector<Connection*>& Controller::getConnections() const
{
    return connections;
}

const std::vector<Connection*> Controller::getConnectionsByHost(const Host* host) const
{
    std::vector<Connection*> connectionsByHost;
    for (Connection* connection : connections) {
        if (connection->getPeer1() == *host || connection->getPeer2() == *host) {
            connectionsByHost.push_back(connection);
        }
    }
    return connectionsByHost;
}

const Host* Controller::getHostByName(const std::string& name) const
{
    for (Host* host : hosts) {
        if (host->getName() == name) {
            return host;
        }
    }
    return nullptr;
}

const std::vector<Sensore*> Controller::getSensoriByName(const std::string& text) const{
    std::vector<Sensore*> sensoriByName;
    for (Connection* connection : connections) {
        for (Sensore* s : connection->getSensori()) {
            QRegularExpression regex(QString::fromStdString(text), QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionMatch match = regex.match(QString::fromStdString(s->getName()));
            QRegularExpressionMatch match2 = regex.match(QString::fromStdString(s->getId()));
            if (match.hasMatch() || match2.hasMatch()) {
                sensoriByName.push_back(s);
            }
        }
    }
    return sensoriByName;
}

void Controller::clearSensors() {
    for (Connection* connection : connections) {
        for (Sensore* s : connection->getSensori())
        {
            connection->removeSensore(*s);
        }
        
    }

}

bool Controller::saveJSON()
{
    try {
        exportDataJSON(exportFilename);
    } catch (const std::exception& e) {
        return false;
    }
    return true;
}

bool Controller::exportDataJSON(const QString& filename)
{
    try {
        if (filename.isEmpty()) {
            return false;
        }
        saver->exportJSON(filename, connections);
        exportFilename = filename;
    } catch (const std::exception& e) {
        lastErrorMessage = QString::fromStdString(e.what());
        return false;
    }
    return true;
}

bool Controller::importDataJSON(const QString& filename)
{
    try {
        if (filename.isEmpty()) {
            return false;
        }

        std::vector<Connection*> importedConnections = saver->loadJSON(filename);
        clearSensors();
        for (Connection* importedConnection : importedConnections) {
            for (Connection* connection : connections) {
                if (connection->getName() == importedConnection->getName()) {
                    *connection = *importedConnection;
                    break;
                }
            }
        }
        exportFilename = filename;

    } catch (const std::exception& e) {
        lastErrorMessage = QString::fromStdString(e.what());
        return false;
    }
    return true;
}

const QString& Controller::getExportFilename() const
{
    return exportFilename;
}

const QString Controller::getLastErrorMessage()
{
    QString message = lastErrorMessage;
    lastErrorMessage = "";
    return message;
}

void Controller::editSensore(Sensore* sensore, const QString& newName)
{

    for (Sensore* sensor : getSensori()) {
        if (sensor == sensore) {
            sensor->setName(newName.toStdString());
            return;
        }
    }
    throw std::runtime_error("Sensor not found");
}

Controller::~Controller()
{
    delete saver;
    for (Connection* connection : connections) {
        delete connection;
    }
    connections.clear();
    for (Host* host : hosts) {
        delete host;
    }
    hosts.clear();
}

