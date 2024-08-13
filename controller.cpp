#include "controller.h"

Controller::Controller()
{
    sensori = std::vector<Sensore*>();
    // Create a new SensorSaver object
    saver = new JSONManager();
    // Create a filename for the JSON file
    exportFilename = "";
}

Controller::~Controller()
{
    //delete the SensorSaver object
    //delete saver;
}

void Controller::addSensore(Sensore* sensore)
{
    sensori.push_back(sensore);
    //save the sensor to the file
    //saver->saveSensor(sensore);
}

//remove sensore
void Controller::removeSensore(Sensore* sensore)
{
    //remove the sensor from the file
    for (Connection* connection : connections) {
        connection->removeSensore(*sensore);
    }
    sensori.erase(std::remove(sensori.begin(), sensori.end(), sensore), sensori.end());

    //saver->removeSensor(sensore);
}

void Controller::addHost(Host* host)
{
    hosts.push_back(host);
    // save the host to the file
    // saver->saveHost(*host);
}

void Controller::removeHost(Host* host)
{
    // remove the host from the vector
    hosts.erase(std::remove(hosts.begin(), hosts.end(), host), hosts.end());
    // remove the host from the file
    // saver->removeHost(*host);
}

void Controller::addConnection(Connection* connection)
{
    connections.push_back(connection);
    // save the connection to the file
    // saver->saveConnection(*connection);
}

void Controller::removeConnection(Connection* connection)
{
    // remove the connection from the vector
    connections.erase(std::remove(connections.begin(), connections.end(), connection), connections.end());
    // remove the connection from the file
    // saver->removeConnection(*connection);
}

const std::vector<Sensore*>& Controller::getSensori()
{
    return sensori;
}

// Getter for hosts
const std::vector<Host*>& Controller::getHosts()
{
    return hosts;
}

// Getter for connections
const std::vector<Connection*>& Controller::getConnections()
{
    return connections;
}

// Getter for saver
// JSONManager* Controller::getJSONManager()
// {
//     return saver;
// }

std::vector<Connection*> Controller::getConnectionsByHost(Host* host)
{
    std::vector<Connection*> connectionsByHost;
    for (Connection* connection : connections)
    {
        if (connection->getPeer1() == *host || connection->getPeer2() == *host)
        {
            connectionsByHost.push_back(connection);
        }
    }
    return connectionsByHost;
}

Host* Controller::getHostByName(std::string name){
    for (Host* host : hosts)
    {
        if (host->getName() == name)
        {
            return host;
        }
    }
    return nullptr;
}

//operator= overload
Controller& Controller::operator=(const Controller& other)
{
    if (this != &other)
    {
        //delete the SensorSaver object
        //delete saver;
        //copy the sensori vector
        sensori = other.sensori;
        hosts = other.hosts;
        connections = other.connections;
        saver = other.saver;

    }
    return *this;
}

// for json
void Controller::clearSensors() {
    // Clear the existing sensors
    for (Sensore* sensor : sensori) {
        removeSensore(sensor);
    }
    sensori.clear();
}

bool Controller::saveJSON() {
    try {
        exportDataJSON(exportFilename);
    } catch (const std::exception& e) {
        return false;
    }
    return true;
}

bool Controller::exportDataJSON(QString filename) {
    try {
        // Check if the filename is valid
        if (filename.isEmpty()) {
            return false;
        }
        saver->exportJSON(filename, connections);
        exportFilename = filename;
    } catch (const std::exception& e) {
        return false;
    }
    return true;
}

bool Controller::importDataJSON(QString filename) {
    try {
        // Check if the filename is valid
        if (filename.isEmpty()) {
            return false;
        }

        // Load the data from the JSON file
        std::vector<Connection*> importedConnections = saver->loadJSON(filename);

        // Clear the existing sensors
        clearSensors();

        // Add sensors to matching connections
        for (Connection* importedConnection : importedConnections) {
            Connection* existingConnection = nullptr;
            
            // Find matching existing connection
            for (Connection* connection : connections) {
                if (connection->getName() == importedConnection->getName()) {
                    existingConnection = connection;
                    break;
                }
            }

            // If connection doesn't exist, raise an error
            if (!existingConnection) {
                throw std::runtime_error("Connection " + importedConnection->getName() + " does not exist in the current configuration.");
            }

            // Add sensors to the existing connection
            for (Sensore* sensor : importedConnection->getSensori()) {
                existingConnection->addSensore(*sensor);
                // Add sensor to the controller's sensor list if it's not already there
                if (std::find(sensori.begin(), sensori.end(), sensor) == sensori.end()) {
                    addSensore(sensor);
                }
            }

            // Clean up the imported connection as we're not using it
            delete importedConnection;
        }

        // Update the export filename
        exportFilename = filename;

    } catch (const std::exception& e) {
        // Log the error message
        qDebug() << "Error importing JSON: " << e.what();
        return false;
    }
    return true;
}

const QString Controller::getExportFilename() {
    return exportFilename;
}

void Controller::editSensore(Sensore* sensore, const QString& newName)
{
    for (Sensore* sensor : sensori)
        if (sensor == sensore){
            sensor->setName(newName.toStdString());
            return;
        }
    throw std::runtime_error("Sensor not found");
}