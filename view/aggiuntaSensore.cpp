#include "aggiuntaSensore.h"
#include <QApplication>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QComboBox>

// Sensor addition window
AggiuntaSensore::AggiuntaSensore(QWidget *parent) : QWidget(parent), layout(new QVBoxLayout(this)) {

    formLayout = new QFormLayout;
    nameLabel = new QLabel("Name:");
    nameLineEdit = new QLineEdit;
    formLayout->addRow(nameLabel, nameLineEdit);

    // Dropdown menu type selection
    typeLabel = new QLabel("Type:");
    typeComboBox = new QComboBox;
    typeComboBox->addItem("Speed");
    typeComboBox->addItem("Load");
    typeComboBox->addItem("Errors");

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

    // Sensore *sensore = new Sensore(name, type);
    // emit sensoreAdded(sensore);
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
