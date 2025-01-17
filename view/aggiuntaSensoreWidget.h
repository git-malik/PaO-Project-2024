#ifndef AGGIUNTASENSOREWIDGET_H
#define AGGIUNTASENSOREWIDGET_H

#include <QApplication>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QComboBox>
#include "../model/core/sensore.h"
#include "../model/core/connection.h"
#include "../model/core/sensoreCarico.h"
#include "../model/core/sensoreErrori.h"
#include "../model/core/sensoreBanda.h"
#include "../model/core/pacchetto.h"

class AggiuntaSensoreWidget : public QWidget {
    Q_OBJECT
    public:
        AggiuntaSensoreWidget(const std::vector<Connection*>& connections, QWidget *parent = nullptr);
        ~AggiuntaSensoreWidget();
    signals:
        void sensoreAddedSignal(Sensore* sensore, Connection* connection);
    private slots:
        void onAddButtonClicked();
    private:
        QLabel* nameLabel;
        QLineEdit* nameLineEdit;
        QLabel* typeLabel;
        QComboBox* typeComboBox;
        QComboBox* connectionComboBox;
        QPushButton* addButton;
        QPushButton* cancelButton;
        QVBoxLayout* layout;
        QFormLayout* formLayout;
        QWidget* widget;
};

#endif
