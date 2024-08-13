#include "sensorWidget.h"

// SensorWidget::SensorWidget(Sensore* sensore, Controller* controller, QWidget* parent) : QWidget(parent), sensore(sensore) {
SensorWidget::SensorWidget(Sensore* sensore, QWidget* parent) : QWidget(parent), sensore(sensore) {
    // Create the main layout for the sensor widget
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(4, 4, 4, 4);
    mainLayout->setSpacing(10);

    // Row 1: Sensor Name and ID
    QHBoxLayout* nameIdLayout = new QHBoxLayout();
    sensorName = new QLabel(QString::fromStdString(sensore->getName()));
    sensorId = new QLabel(QString::fromStdString(sensore->getId()));
    nameIdLayout->addWidget(sensorName);
    nameIdLayout->addWidget(sensorId);
    nameIdLayout->addStretch();

    // Row 2: Open Chart button
    QHBoxLayout* graphicChartLayout = new QHBoxLayout();
    QPushButton* openChartButton = new QPushButton("OPEN CHART");
    openChartButton->setIcon(QIcon(":/resources/icons/open.png"));
    graphicChartLayout->addWidget(openChartButton);
    // graphicChartLayout->addStretch();

    // Row 3: Edit and Delete buttons
    QHBoxLayout* editDeleteLayout = new QHBoxLayout();
    editButton = new QPushButton("EDIT");
    QPushButton* deleteButton = new QPushButton("DELETE");
    editButton->setIcon(QIcon(":/resources/icons/edit.png"));
    deleteButton->setIcon(QIcon(":/resources/icons/delete.png"));
    editButton->setProperty("cssClass", "blue");
    deleteButton->setProperty("cssClass", "red");

    // Add the buttons to the layout
    editDeleteLayout->addWidget(editButton);
    editDeleteLayout->addWidget(deleteButton);
    editDeleteLayout->addStretch();

    // Horizontal separation line
    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    // Add the three rows to the main layout
    mainLayout->addLayout(nameIdLayout);
    mainLayout->addLayout(graphicChartLayout);
    mainLayout->addLayout(editDeleteLayout);
    mainLayout->addWidget(line);

    // Connect signals and slots
    // Add slot for delete button
    connect(openChartButton, &QPushButton::clicked, this, &SensorWidget::openChart);
    connect(editButton, &QPushButton::clicked, this, &SensorWidget::toggleEdit);
    connect(deleteButton, &QPushButton::clicked, this, [this, sensore] {
        emit sensoreDeletedSignal(sensore);
    });

    // Set a fixed height for the widget to make it compact
    setFixedHeight(120); // Adjust this value as needed
}

void SensorWidget::toggleEdit() {
    //replaces sensorname with SensorNameEdit
    QLineEdit* sensorNameEdit = new QLineEdit(sensorName->text());
    layout()->replaceWidget(sensorName, sensorNameEdit);
    sensorNameEdit->setStyleSheet("background-color: white; color: black;");

    //changes button
    editButton->setText(" CONFIRM");
    editButton->setStyleSheet("background-color: green; color: white;");
    editButton->setIcon(QIcon(":/resources/icons/tick.png"));

    //connects the button to the confirmEdit function
    connect(editButton, &QPushButton::clicked, this, [this, sensorNameEdit] {
        emit sensoreEditedSignal(sensore, sensorNameEdit->text());
    });
}

void SensorWidget::openChart(){
    for (size_t i = 0; i < 10; i++)
    {
        sensore->misura();
    }
    GraficoSensore* g = new GraficoSensore(sensore);
    g->show();
}

QString SensorWidget::getSensorName(){
    return sensorName->text();
}

QString SensorWidget::getSensorId(){
    return sensorId->text();
}
