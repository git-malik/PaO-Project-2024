#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>
#include <QStackedWidget>
#include "QtWidgets/qlineedit.h"
#include "../model/core/sensore.h"
#include "./graficoSensore.h"

class SensorWidget: public QWidget
{
    Q_OBJECT

private:
    Sensore* sensore;
    QLabel* sensorName;
    QLabel* sensorId;
    QPushButton* openButton;
    QPushButton* editButton;
    QPushButton* deleteButton;
public:
    // SensorWidget(Sensore* sensore, Controller* controller, QWidget* parent = nullptr); // controller aggiunto
    SensorWidget(Sensore* sensore, QWidget* parent = nullptr); // controller aggiunto
    QString getSensorName();
    QString getSensorId();
    void toggleEdit();

public slots:
    void openChart();

signals:
    void sensoreDeletedSignal(Sensore* sensore);
    void sensoreEditedSignal(Sensore* sensore, const QString& newName);

};

#endif // SENSORWIDGET_H
