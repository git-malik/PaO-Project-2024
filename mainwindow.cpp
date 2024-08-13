#include "mainwindow.h"

#include <QApplication>
#include <QCheckBox>
#include <QComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QIcon>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QObject>
#include <QPixmap>
#include <QPushButton>
#include <QRegularExpression>
#include <QScrollArea>
#include <QScrollBar>
#include <QScroller>
#include <QSlider>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextEdit>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    controller = new Controller();
    setupUi();
}

MainWindow::MainWindow(Controller* controller, QWidget* parent)
    : QMainWindow(parent)
{
    this->controller = controller;
    setupUi();
}

MainWindow::~MainWindow()
{
}

void MainWindow::buttonSensoreAdded()
{
    AggiuntaSensore* aggiuntaSensore = new AggiuntaSensore();
    connect(aggiuntaSensore, &AggiuntaSensore::sensoreAddedSignal, this, &MainWindow::addSensoreWidget);
    aggiuntaSensore->show();
}

void MainWindow::addSensoreWidget(Sensore* sensore)
{
    controller->addSensore(sensore);
    refreshSensors();
}

void MainWindow::removeSensoreWidget(Sensore* sensore)
{
    controller->removeSensore(sensore);
    refreshSensors();
}

void MainWindow::sensorEditedSlot(Sensore* sensore, const QString& newName)
{
    controller->editSensore(sensore,newName);
    //QMessageBox::information(this, "Sensor Edited", "Sensor" + QString::fromStdString(sensore->getId()) + " edited successfully.");
    refreshSensors();
}

void MainWindow::refreshSensors()
{
    sensorsection = nullptr;
    delete sensorsection;
    sensorsection = setupSensors(nullptr);
    scrollArea2->setWidget(sensorsection);
}

QWidget* MainWindow::setupSensors(Connection* connection)
{
    // clear sensor section items
    QWidget* res = new QWidget;

    // Delete and recreate column2 and scrollArea2
    // Create a new scroll area for the sensor section

    // Get the list of sensors based on the connection
    std::vector<Sensore*> sensors;
    if (connection) {
        sensors = connection->getSensori();
    } else {
        sensors = controller->getSensori();
    }

    // Add the sensors to the sensor section
    QVBoxLayout* sensorSectionLayout = new QVBoxLayout(res);
    sensorSectionLayout->setAlignment(Qt::AlignTop);
    sensorSectionLayout->setSizeConstraint(QLayout::SetMinimumSize);

    // display sensor size
    // QLabel* sensorSize = new QLabel("Sensors: " + QString::number(sensors.size()));
    for (Sensore* sensore : sensors) {
        SensorWidget* sw = new SensorWidget(sensore);
        // SensorWidget* sw = new SensorWidget(sensore, controller);
        sensorSectionLayout->addWidget(sw);
        connect(sw, &SensorWidget::sensoreDeletedSignal, this, &MainWindow::removeSensoreWidget);
        connect(sw, &SensorWidget::sensoreEditedSignal, this, &MainWindow::sensorEditedSlot);
    }

    res->setLayout(sensorSectionLayout);
    return res;
}

void MainWindow::updateConnections(Host* host)
{
    // Clear the connections list
    if (connectionsList) {
        connectionsList->clear();
    }

    // Get the connections for the selected host
    std::vector<Connection*> connections = std::vector<Connection*>();
    if (host) {
        connections = controller->getConnectionsByHost(host);
    } else {
        connections = controller->getConnections();
    }

    // Add the connections to the connections list
    for (Connection* connection : connections) {
        QListWidgetItem* connectionItem = new QListWidgetItem("");
        // Create widgets for the connection
        QWidget* connectionWidget = new QWidget;
        QLabel* connectionLabel1 = new QLabel(QString::fromStdString(connection->getPeer1().getName()));
        QLabel* connectionLabelIcon = new QLabel;
        QIcon connectionIcon(":/resources/icons/Connection.png");
        connectionLabelIcon->setPixmap(connectionIcon.pixmap(64, 16));
        QLabel* connectionLabel2 = new QLabel(QString::fromStdString(connection->getPeer2().getName()));
        QHBoxLayout* connectionLayout = new QHBoxLayout(connectionWidget);
        connectionLayout->addWidget(connectionLabel1);
        connectionLayout->addWidget(connectionLabelIcon);
        connectionLayout->addWidget(connectionLabel2);
        // spacer
        connectionLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
        connectionItem->setSizeHint(connectionWidget->sizeHint());
        connectionsList->addItem(connectionItem);
        connectionsList->setItemWidget(connectionItem, connectionWidget);
        connectionsList->setAlternatingRowColors(true);
    }
    scrollArea3->setWidget(connectionsList);
    connect(connectionsList, &QListWidget::itemClicked, this, [this]() {
        // Get the selected connection
        QListWidgetItem* selectedItem = connectionsList->currentItem();
        if (selectedItem) {
            // get the connection at the row of the selected item
            Connection* selectedConnection = controller->getConnections().at(connectionsList->row(selectedItem));
            // Call setupSensors with the selected connection
            // QMessageBox::information(this, "Selected Host", selectedConnection->getSensori().at(0)->getName().c_str());
            QWidget* sensorsection = setupSensors(selectedConnection);
            scrollArea2->setWidget(sensorsection);
        }
    });
}

// JSON
void MainWindow::save()
{
    // Check if the export filename is empty
    if (controller->getExportFilename().isEmpty()) {
        exportData();
    } else {
        // Save the sensors to a JSON file
        if (controller->saveJSON()) {
            QMessageBox::information(this, "Save", "Sensors saved to " + controller->getExportFilename());
        } else {
            QMessageBox::critical(this, "Error", "Unable to save sensors to file.");
        }
    }
}

void MainWindow::exportData()
{
    // Open a file dialog to select the JSON file
    QString fileName = QFileDialog::getSaveFileName(this, "Export Sensors", "sensors.json", "JSON Files (*.json)");
    if (controller->exportDataJSON(fileName)) {
        QMessageBox::information(this, "Export", "Sensors exported to " + fileName);
    } else {
        QMessageBox::critical(this, "Error", "Unable to export sensors to file.");
    }
}

void MainWindow::importData()
{
    // Open a file dialog to select the JSON file
    QString fileName = QFileDialog::getOpenFileName(this, "Import Sensors", "", "JSON Files (*.json)");
    if (controller->importDataJSON(fileName)) {
        setupUi();
        QMessageBox::information(this, "Import", "Sensors imported from " + fileName);
    } else {
        QMessageBox::critical(this, "Error", "Unable to import sensors from file.");
    }
}

void MainWindow::setupUi()
{
    window = new QWidget();
    window->setWindowTitle("SenseNet");

    // MainWindow window;
    QHBoxLayout* mainLayout = new QHBoxLayout(window);

    // Columns
    // Second column
    QVBoxLayout* column2 = new QVBoxLayout;
    mainLayout->addLayout(column2);
    // Column Title label
    QLabel* column2Title = new QLabel("Sensors for chosen host");
    column2->addWidget(column2Title);
    // List of sensors (scrollable)
    scrollArea2 = new QScrollArea;
    scrollArea2->setWidgetResizable(true);
    // add a widget to the top, before the scroll area
    QWidget* topWidget = new QWidget;
    QHBoxLayout* topWidgetLayout = new QHBoxLayout(topWidget);
    topWidgetLayout->setAlignment(Qt::AlignTop);
    topWidgetLayout->setSizeConstraint(QLayout::SetMinimumSize);

    // Add an "Add +" button
    QPushButton* addButton = new QPushButton(" ADD");
    QIcon addIcon(":/resources/icons/add.png");
    addButton->setIcon(addIcon);
    // addButton->setObjectName("green");
    addButton->setProperty("cssClass", "green");
    topWidgetLayout->addWidget(addButton);
    topWidgetLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    // Add a slot for the "Add" button
    // connect(addButton, &QPushButton::clicked, this, [this] {
    //     AddSensorWindow *addSensorWindow = new AddSensorWindow();
    // });
    connect(addButton, SIGNAL(clicked()), this, SLOT(buttonSensoreAdded()));

    // Connect the addedSensoreSignal() signal to the addSensoreWidget() slot

    // Add a search bar with magnifying glass icon
    QLineEdit* searchBar = new QLineEdit;
    searchBar->setPlaceholderText("Search...");
    // searchBar->setStyleSheet("QLineEdit { border-radius: 5px; padding: 5px; }");
    searchBar->setFixedWidth(200);
    searchBar->setFixedHeight(30);
    searchBar->setClearButtonEnabled(true);

    // Set the search icon
    QIcon searchIcon(":/resources/icons/searchico.png");
    searchBar->addAction(searchIcon, QLineEdit::LeadingPosition);

    topWidgetLayout->addWidget(searchBar);

    column2->addWidget(topWidget);

    // Sensor section
    refreshSensors();
    column2->addWidget(scrollArea2);
    // end of sensorWidget SECTION

    // Connect the textChanged signal of the search bar to a slot
    connect(searchBar, &QLineEdit::textChanged, this, [this](const QString& searchText) {
        if (searchText.isEmpty()) {
            QList<SensorWidget*> sensorWidgets = sensorsection->findChildren<SensorWidget*>();
            for (SensorWidget* sensorWidget : sensorWidgets) {
                sensorWidget->show();
            }
            return;
        }
        // Perform search based on the entered text
        QRegularExpression regex("." + searchText + ".", QRegularExpression::CaseInsensitiveOption);
        QList<SensorWidget*> sensorWidgets = sensorsection->findChildren<SensorWidget*>();
        for (SensorWidget* sensorWidget : sensorWidgets) {
            if (sensorWidget->getSensorName().contains(searchText, Qt::CaseInsensitive)) {
                sensorWidget->show();
            } else if (sensorWidget->getSensorId().contains(searchText, Qt::CaseInsensitive)) {
                sensorWidget->show();
            } else {
                sensorWidget->hide();
            }
        }
    });

    // Add the sensor section to the scroll area
    // scrollArea2->setWidget(sensorSection);
    // column2->addWidget(scrollArea2);

    // First column
    QVBoxLayout* column1 = new QVBoxLayout;
    window->setLayout(mainLayout); // Set mainLayout as the layout for the MainWindow object
    mainLayout->addLayout(column1);
    // Column Title label
    QLabel* column1Title = new QLabel("Hosts");
    column1->addWidget(column1Title);
    // List of hosts (scrollable)
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);

    QListWidget* hostsList = new QListWidget;

    for (Host* host2 : controller->getHosts()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(host2->getName()));
        item->setIcon(QIcon(":/resources/icons/pc.png"));
        hostsList->addItem(item);
        // Add onFocus listener
    }
    connect(hostsList, &QListWidget::itemClicked, this, [this, hostsList]() {
        // Get the selected host
        QListWidgetItem* selectedItem = hostsList->currentItem();
        if (selectedItem) {
            QString hostName = selectedItem->text();
            Host* selectedHost = controller->getHostByName(hostName.toStdString());
            // Emit the signal with the selected host
            // emit hostSelectedSignal(selectedHost);
            updateConnections(selectedHost);
            // QMessageBox::information(this, "Selected Host", "You have selected a host!");
        }
    });

    hostsList->setSelectionMode(QAbstractItemView::SingleSelection);
    hostsList->setSelectionBehavior(QAbstractItemView::SelectRows);
    hostsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    hostsList->setDragDropMode(QAbstractItemView::NoDragDrop);
    hostsList->setAlternatingRowColors(true);
    // hostsList->setStyleSheet("QListWidget::item { border-bottom: 1px solid black; }");

    scrollArea->setWidget(hostsList);
    column1->addWidget(scrollArea);

    // Third column
    QVBoxLayout* column3 = new QVBoxLayout;
    mainLayout->addLayout(column3);
    // Column Title label
    QLabel* column3Title = new QLabel("Connections with chosen host");
    column3->addWidget(column3Title);
    // List of connections (scrollable)
    scrollArea3 = new QScrollArea;
    scrollArea3->setWidgetResizable(true);

    // Connections section

    connectionsList = new QListWidget;
    updateConnections(nullptr);

    scrollArea3->setWidget(connectionsList);
    column3->addWidget(scrollArea3);

    // Set the toolbar
    setCentralWidget(window);

    // Check if the toolbar already exists
    if (!findChild<QToolBar*>("ToolBar")) {
        QToolBar* toolbar = addToolBar("ToolBar");
        toolbar->setObjectName("ToolBar");
        toolbar->setFloatable(false);

        QToolButton* saveButton = new QToolButton(this);
        saveButton->setIcon(QIcon(":/resources/icons/save.png"));
        saveButton->setText("Save");
        saveButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        saveButton->setProperty("cssClass", "label");
        toolbar->addWidget(saveButton);

        QToolButton* exportButton = new QToolButton(this);
        exportButton->setIcon(QIcon(":/resources/icons/export.png"));
        exportButton->setText("Export");
        exportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        exportButton->setProperty("cssClass", "label");
        toolbar->addWidget(exportButton);

        QToolButton* importButton = new QToolButton(this);
        importButton->setIcon(QIcon(":/resources/icons/import.png"));
        importButton->setText("Import");
        importButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        importButton->setProperty("cssClass", "label");
        toolbar->addWidget(importButton);

        connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
        connect(exportButton, SIGNAL(clicked()), this, SLOT(exportData()));
        connect(importButton, SIGNAL(clicked()), this, SLOT(importData()));
    }
}
