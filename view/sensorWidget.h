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

#define MISURAZIONIPERGRAFICO 10

class SensorWidget: public QWidget
{
    Q_OBJECT

private:
    Sensore* sensore;
    QLabel* sensorName;
    QLabel* sensorId;
    QPushButton* editButton;

public:
    SensorWidget(Sensore* sensore, QWidget* parent = nullptr);
    ~SensorWidget();

private slots:
    void toggleEdit();
    void openChart();

signals:
    void sensoreDeletedSignal(const Sensore* sensore);
    void sensoreEditedSignal(Sensore* sensore, const QString& newName);
};

#endif
