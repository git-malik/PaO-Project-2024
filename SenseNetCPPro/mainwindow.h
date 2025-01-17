#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <vector>
#include "model/core/sensore.h"
#include "model/core/connection.h"
#include "model/core/host.h"
#include "view/aggiuntaSensoreWidget.h"
#include "view/sensorWidget.h"
#include "controller.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);
        MainWindow(Controller* controller, QWidget *parent = nullptr);
        ~MainWindow();
    private slots:
        void addSensoreWidget(Sensore* sensore, Connection* connection);
        void removeSensoreWidget(const Sensore* sensore);
        void sensorEditedSlot(Sensore* sensore, const QString& newName);
        void buttonSensoreAdded();
        void save();
        void exportData();
        void importData();
    private:
        Controller *controller;
        QWidget *window;
        QScrollArea* scrollArea3;
        QScrollArea* scrollArea2;
        QListWidget* connectionsList;

        void setupUi();

        void showAllSensors();
        void showConnectionSensors(const Connection* connection);
        void showSensors(const std::vector<Sensore*>& sensorVector);
        void showAllConnections();
        void showHostConnections(const Host* host);
        void showConnections(const std::vector<Connection*>& connections);
};
#endif // MAINWINDOW_H
