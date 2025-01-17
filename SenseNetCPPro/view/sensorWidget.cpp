#include "sensorWidget.h"

SensorWidget::SensorWidget(Sensore* sensore, QWidget* parent) : QWidget(parent), sensore(sensore) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(4, 4, 4, 4);
    mainLayout->setSpacing(10);

    QHBoxLayout* nameIdLayout = new QHBoxLayout();
    sensorName = new QLabel(QString::fromStdString(sensore->getName()));
    sensorId = new QLabel(QString::fromStdString(sensore->getId()));
    nameIdLayout->addWidget(sensorName);
    nameIdLayout->addWidget(sensorId);
    nameIdLayout->addStretch();

    QHBoxLayout* graphicChartLayout = new QHBoxLayout();
    QPushButton* openChartButton = new QPushButton("OPEN CHART");
    openChartButton->setProperty("cssClass", "white");
    openChartButton->setIcon(QIcon(":/resources/icons/open.png"));
    graphicChartLayout->addWidget(openChartButton);

    QHBoxLayout* editDeleteLayout = new QHBoxLayout();
    editButton = new QPushButton("EDIT");
    QPushButton* deleteButton = new QPushButton("DELETE");
    editButton->setIcon(QIcon(":/resources/icons/edit.png"));
    deleteButton->setIcon(QIcon(":/resources/icons/delete.png"));
    editButton->setProperty("cssClass", "blue");
    deleteButton->setProperty("cssClass", "red");

    editDeleteLayout->addWidget(editButton);
    editDeleteLayout->addWidget(deleteButton);
    editDeleteLayout->addStretch();

    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    mainLayout->addLayout(nameIdLayout);
    mainLayout->addLayout(graphicChartLayout);
    mainLayout->addLayout(editDeleteLayout);
    mainLayout->addWidget(line);

    connect(openChartButton, &QPushButton::clicked, this, &SensorWidget::openChart);
    connect(editButton, &QPushButton::clicked, this, &SensorWidget::toggleEdit);
    connect(deleteButton, &QPushButton::clicked, this, [this, sensore] {
        emit sensoreDeletedSignal(sensore);
    });

    setFixedHeight(120);
}

void SensorWidget::toggleEdit() {
    QLineEdit* sensorNameEdit = new QLineEdit(sensorName->text());
    layout()->replaceWidget(sensorName, sensorNameEdit);
    sensorNameEdit->setStyleSheet("background-color: white; color: black;");

    editButton->setText(" CONFIRM");
    editButton->setStyleSheet("background-color: green; color: white;");
    editButton->setIcon(QIcon(":/resources/icons/tick.png"));

    connect(editButton, &QPushButton::clicked, this, [this, sensorNameEdit] {
        if (!sensorNameEdit->text().isEmpty()) {
            emit sensoreEditedSignal(sensore, sensorNameEdit->text());
        }
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
SensorWidget::~SensorWidget() {
    delete sensorName;
    delete sensorId;
    delete editButton;
}