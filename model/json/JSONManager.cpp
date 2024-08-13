#include "jsonManager.h"

// Constructor
JSONManager::JSONManager() {}

// Destructor
JSONManager::~JSONManager() {}

// Save the sensor data to a JSON file
void JSONManager::exportJSON(QString filename, std::vector<Connection*> connections) throw() {
    // Create a JSON array to hold the sensor data
    QJsonArray connectionArray;

    // Iterate through the connections and add them to the JSON array
    for (Connection* connection : connections) {
        QJsonObject connectionObject;
        connectionObject["name"] = QString::fromStdString(connection->getName());
        // connectionObject["peer1"] = QString::fromStdString(connection->getPeer1().getName());
        // connectionObject["peer2"] = QString::fromStdString(connection->getPeer2().getName());

        // Create a JSON array to hold the sensor data
        QJsonArray sensorArray;

        // Iterate through the sensors and add them to the JSON array
        for (Sensore* sensor : connection->getSensori()) {
            QJsonObject sensorObject;
            sensorObject["id"] = QString::fromStdString(sensor->getId());
            sensorObject["name"] = QString::fromStdString(sensor->getName());
            // Add other sensor properties as needed
            sensorArray.append(sensorObject);
        }

        // Add the sensor array to the connection object
        connectionObject["sensors"] = sensorArray;

        // Add the connection object to the connection array
        connectionArray.append(connectionObject);
    }

    // Create a JSON document and set the root to the sensor array
    QJsonDocument document;
    document.setArray(connectionArray);

    // Save the JSON data to a file
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(document.toJson());
        file.close();
    } else {
        SaveException* ex = new SaveException("Unable to save sensors to file.");
        throw ex;
    }
}

// Load the sensor data from a JSON file
std::vector<Connection*> JSONManager::loadJSON(QString filename) throw() {
    // Check if the filename is valid
    if (!filename.isEmpty()) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly)) {
            // Read the JSON data from the file
            QByteArray jsonData = file.readAll();
            file.close();

            // Parse the JSON data
            QJsonDocument document = QJsonDocument::fromJson(jsonData);
            if (!document.isNull()) {
                // Get the sensor array from the JSON document
                QJsonArray connectionArray = document.array();

                // Create a vector to hold the imported sensors
                std::vector<Connection*> importedConnections;

                // Add the new sensors from the JSON data
                for (const QJsonValue& value : connectionArray) {
                    QJsonObject connectionObject = value.toObject();
                    std::string name = connectionObject["name"].toString().toStdString();
                    // std::string peer1 = connectionObject["peer1"].toString().toStdString();
                    // std::string peer2 = connectionObject["peer2"].toString().toStdString();

                    // Create a new connection
                    // Connection* connection = new Connection(name);
                    // Connection *c1 = new Connection("A-B", new Host("A"), new Host("B"));
                    // 
                    Host* h1 = new Host(name.substr(0, 1));
                    Host* h2 = new Host(name.substr(2, 1));
                    Connection *connection = new Connection(name, *h1, *h2);

                    // Get the sensor array from the connection object
                    QJsonArray sensorArray = connectionObject["sensors"].toArray();

                    // Add the sensors to the connection
                    for (const QJsonValue& sensorValue : sensorArray) {
                        QJsonObject sensorObject = sensorValue.toObject();
                        std::string id = sensorObject["id"].toString().toStdString();
                        std::string name = sensorObject["name"].toString().toStdString();

                        // Determine the sensor type based on the id prefix
                        Sensore* sensor;
                        if (id.substr(0, 3) == "BS#") {
                            sensor = new SensoreBanda(name);
                        } else if (id.substr(0, 3) == "LS#") {
                            sensor = new SensoreCarico(name);
                        } else if (id.substr(0, 3) == "ES#") {
                            sensor = new SensoreErrori(name);
                        } else {
                            // Default to bandwidth sensor
                            sensor = new SensoreBanda(name);
                        }

                        // Add the sensor to the connection
                        connection->addSensore(*sensor);
                    }

                    // Add the connection to the imported connections vector
                    importedConnections.push_back(connection);
                }

                // Return the imported sensors
                return importedConnections;
            }
        }
    }
}