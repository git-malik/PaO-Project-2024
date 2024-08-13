#include "aggiuntaSensore.h"
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


// Sensor addition window
AggiuntaSensore::AggiuntaSensore(QWidget *parent) : QWidget(parent), layout(new QVBoxLayout(this)) {

    formLayout = new QFormLayout;
    nameLabel = new QLabel("Name:");
    nameLineEdit = new QLineEdit;
    formLayout->addRow(nameLabel, nameLineEdit);

    // Dropdown menu type selection
    typeLabel = new QLabel("Type:");
    typeComboBox = new QComboBox;
    typeComboBox->addItem("Bandwidth");
    typeComboBox->addItem("Load");
    typeComboBox->addItem("Errors");
    typeComboBox->setCurrentIndex(0);
    typeComboBox->setFocus();

    formLayout->addRow(typeLabel, typeComboBox);

    layout->addLayout(formLayout);

    addButton = new QPushButton("DONE");
    addButton->setProperty("cssClass", "green");
    layout->addWidget(addButton);

    // Cancel button
    cancelButton = new QPushButton("CANCEL");
    layout->addWidget(cancelButton);

    setLayout(layout);

    connect(addButton, &QPushButton::clicked, this, &AggiuntaSensore::onAddButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AggiuntaSensore::close);
}

// Add button clicked
void AggiuntaSensore::onAddButtonClicked() {
    QString name = nameLineEdit->text();
    QString type = typeComboBox->currentText();

    if (name.isEmpty()) {
        return;
    }
    if (type == "Bandwidth") {
        emit sensoreAddedSignal(new SensoreBanda(name.toStdString()));
    } else if (type == "Load") {
        emit sensoreAddedSignal(new SensoreCarico(name.toStdString()));
    } else if (type == "Errors") {
        emit sensoreAddedSignal(new SensoreErrori(name.toStdString()));
    }else{
        return;
    }

    close();
}

// Destructor
AggiuntaSensore::~AggiuntaSensore() {
    delete nameLabel;
    delete nameLineEdit;
    delete typeLabel;
    delete typeComboBox;
    delete addButton;
    delete cancelButton;
    delete layout;
    delete formLayout;
}
