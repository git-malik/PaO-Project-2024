#include "jsonManager.h"

void JSONManager::exportJSON(const QString& filename, const std::vector<Connection*>& connections)
{
    QJsonArray connectionArray;

    for (Connection* connection : connections) {
        QJsonObject connectionObject;
        connectionObject["name"] = QString::fromStdString(connection->getName());

        QJsonArray sensorArray;

        for (Sensore* sensor : connection->getSensori()) {
            QJsonObject sensorObject;
            sensorObject["id"] = QString::fromStdString(sensor->getId());
            sensorObject["name"] = QString::fromStdString(sensor->getName());
            sensorArray.append(sensorObject);
        }

        connectionObject["sensors"] = sensorArray;

        connectionArray.append(connectionObject);
    }

    QJsonDocument document;
    document.setArray(connectionArray);

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(document.toJson());
        file.close();
    } else {
        throw std::runtime_error("Unable to save sensors to given file");
    }
}

std::vector<Connection*> JSONManager::loadJSON(const QString& filename)
{
    std::vector<Connection*> importedConnections;
    if (!filename.isEmpty()) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly)) {
            // Read the JSON data from the file
            QByteArray jsonData = file.readAll();
            file.close();

            QJsonDocument document = QJsonDocument::fromJson(jsonData);
            if (!document.isNull()) {
                QJsonArray connectionArray = document.array();

                for (const QJsonValue& value : connectionArray) {
                    QJsonObject connectionObject = value.toObject();
                    std::string name = connectionObject["name"].toString().toStdString();

                    std::string peer1 = name.substr(0, name.find("-"));
                    std::string peer2 = name.substr(name.find("-") + 1);
                    Host* h1 = new Host(peer1);
                    Host* h2 = new Host(peer2);
                    Connection* connection = new Connection(name, *h1, *h2);

                    QJsonArray sensorArray = connectionObject["sensors"].toArray();

                    for (const QJsonValue& sensorValue : sensorArray) {
                        QJsonObject sensorObject = sensorValue.toObject();
                        std::string id = sensorObject["id"].toString().toStdString();
                        std::string name = sensorObject["name"].toString().toStdString();

                        Sensore* sensor;
                        std::string idPrefix = id.substr(0, id.find("#") + 1);
                        if (idPrefix == "BS#") {
                            sensor = new SensoreBanda(name);
                        } else if (idPrefix == "LS#") {
                            sensor = new SensoreCarico(name);
                        } else if (idPrefix == "ES#") {
                            sensor = new SensoreErrori(name);
                        } else if (idPrefix == "JS#") {
                            sensor = new SensoreJitter(name);
                        } else if (idPrefix == "DS#") {
                            sensor = new SensoreDelay(name);
                        } else {
                            throw std::runtime_error("Unrecognized sensor type with ID: " + id);
                        }
                        connection->addSensore(*sensor);
                    }
                    importedConnections.push_back(connection);
                }
            }
        }
    }
    return importedConnections;
}
