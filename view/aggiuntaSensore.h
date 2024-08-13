#ifndef AGGIUNTASENSORE_H
#define AGGIUNTASENSORE_H

#include <QApplication>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QComboBox>
#include "../model/core/sensore.h"
#include "../model/core/sensoreCarico.h"
#include "../model/core/sensoreErrori.h"
#include "../model/core/sensoreBanda.h"
#include "../model/core/pacchetto.h"

class AggiuntaSensore : public QWidget {
    Q_OBJECT
    public:
        explicit AggiuntaSensore(QWidget *parent = nullptr);
        virtual ~AggiuntaSensore();
    signals:
        void sensoreAddedSignal(Sensore* sensore);
    public slots:
        void onAddButtonClicked();
    private:
        QLabel* nameLabel;
        QLineEdit* nameLineEdit;
        QLabel* typeLabel;
        QComboBox* typeComboBox;
        QPushButton* addButton;
        QPushButton* cancelButton;
        QVBoxLayout* layout;
        QFormLayout* formLayout;
        QWidget* widget;
};

#endif // AGGIUNTASENSORE_H