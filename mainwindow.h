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
#include "controller.h"
#include "view/aggiuntaSensore.h"
#include "view/sensorWidget.h"
#include "controller.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        //MainWindow(Host* host[], int hostlistsize, Connection* connlist[], int connlistsize, const std::vector<Sensore*>& sensorVector, QWidget *parent = nullptr);
        MainWindow(QWidget *parent = nullptr);
        MainWindow(Controller* controller, QWidget *parent = nullptr);
        
        ~MainWindow();
    public slots:
        void buttonSensoreAdded();
        void addSensoreWidget(Sensore* sensore);
        void removeSensoreWidget(Sensore* sensore);
        void sensorEditedSlot(Sensore* sensore, const QString& newName);
        // json
        void save();
        void exportData();
        void importData();
        // void updateConnections(Host* host = nullptr);
    //private slots:
    // signals:
    //     void hostSelectedSignal(Host* host);
    //EMIT e slot interni (per aggiornare la view) non servono a molto a quanto pare, si vedrà in seguito
    private:
        // Connection *c_data;
        Controller *controller;
        QWidget *window;
        QWidget* sensorsection;
        QScrollArea* scrollArea3;
        QScrollArea* scrollArea2;
        QListWidget *connectionsList;
        int c_size;
        void setupUi();
        void refreshSensors();
        QWidget* setupSensors(Connection* connection);
        void updateConnections(Host* host = nullptr);
};
#endif // MAINWINDOW_H
