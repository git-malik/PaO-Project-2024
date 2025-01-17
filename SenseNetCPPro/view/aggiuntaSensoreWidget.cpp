#include "aggiuntaSensoreWidget.h"
#include <QApplication>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QComboBox>
#include <QMessageBox>

#include "../controller.h"



AggiuntaSensoreWidget::AggiuntaSensoreWidget(const std::vector<Connection*>& connections, QWidget *parent) : QWidget(parent), layout(new QVBoxLayout(this)) {
    formLayout = new QFormLayout;
    nameLabel = new QLabel("Name:");
    nameLineEdit = new QLineEdit;
    formLayout->addRow(nameLabel, nameLineEdit);
    QLabel* connectionLabel = new QLabel("Associated Connection:");
    connectionComboBox = new QComboBox;
    for (Connection* connection : connections) {
        connectionComboBox->addItem(QString::fromStdString(connection->getName()), QVariant::fromValue(connection));
    }
    connectionComboBox->setCurrentIndex(0);
    connectionComboBox->setFocus();

    formLayout->addRow(connectionLabel, connectionComboBox);

    typeLabel = new QLabel("Type:");
    typeComboBox = new QComboBox;
    typeComboBox->addItem("Bandwidth");
    typeComboBox->addItem("Load");
    typeComboBox->addItem("Errors");
    typeComboBox->addItem("Delay");
    typeComboBox->addItem("Jitter");

    typeComboBox->setCurrentIndex(0);
    typeComboBox->setFocus();

    formLayout->addRow(typeLabel, typeComboBox);

    layout->addLayout(formLayout);

    addButton = new QPushButton("DONE");
    addButton->setProperty("cssClass", "green");
    layout->addWidget(addButton);

    // Cancel button
    cancelButton = new QPushButton("CANCEL");
    cancelButton->setProperty("cssClass", "white");
    layout->addWidget(cancelButton);

    setLayout(layout);

    connect(addButton, &QPushButton::clicked, this, &AggiuntaSensoreWidget::onAddButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AggiuntaSensoreWidget::close);
}

// Add button clicked
void AggiuntaSensoreWidget::onAddButtonClicked() {
    QString name = nameLineEdit->text();
    QString type = typeComboBox->currentText();
    Connection* connection = connectionComboBox->currentData().value<Connection*>();

    if (name.isEmpty() || connection == nullptr) {
        return;
    }
    switch (typeComboBox->currentIndex()) {
        case 0: // Bandwidth
            emit sensoreAddedSignal(new SensoreBanda(name.toStdString()), connection);
            break;
        case 1: // Load
            emit sensoreAddedSignal(new SensoreCarico(name.toStdString()), connection);
            break;
        case 2: // Errors
            emit sensoreAddedSignal(new SensoreErrori(name.toStdString()), connection);
            break;
        case 3: // Delay
            emit sensoreAddedSignal(new SensoreDelay(name.toStdString()), connection);
            break;
        case 4: // Jitter
            emit sensoreAddedSignal(new SensoreJitter(name.toStdString()), connection);
            break;
        default:
            return;
    }
    close();
}

// Destructor
AggiuntaSensoreWidget::~AggiuntaSensoreWidget() {
    delete nameLabel;
    delete nameLineEdit;
    delete typeLabel;
    delete typeComboBox;
    delete addButton;
    delete cancelButton;
    delete formLayout;
    delete layout;
}
