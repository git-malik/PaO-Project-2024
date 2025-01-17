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

void MainWindow::buttonSensoreAdded()
{
    AggiuntaSensoreWidget* aggiuntaSensore = new AggiuntaSensoreWidget(controller->getConnections());
    connect(aggiuntaSensore, &AggiuntaSensoreWidget::sensoreAddedSignal, this, &MainWindow::addSensoreWidget);
    aggiuntaSensore->show();
}

void MainWindow::addSensoreWidget(Sensore* sensore, Connection* connection)
{

    controller->addSensore(sensore, connection);
    showAllSensors();
}

void MainWindow::removeSensoreWidget(const Sensore* sensore)
{
    controller->removeSensore(sensore);
    showAllSensors();
}

void MainWindow::sensorEditedSlot(Sensore* sensore, const QString& newName)
{
    controller->editSensore(sensore, newName);
    showAllSensors();
}

void MainWindow::showSensors(const std::vector<Sensore*>& sensorVector)
{
    QWidget* res = new QWidget;

    QVBoxLayout* sensorSectionLayout = new QVBoxLayout(res);
    sensorSectionLayout->setAlignment(Qt::AlignTop);
    sensorSectionLayout->setSizeConstraint(QLayout::SetMinimumSize);


    for (Sensore* sensore : sensorVector) {
        SensorWidget* sw = new SensorWidget(sensore);
        sensorSectionLayout->addWidget(sw);
        connect(sw, &SensorWidget::sensoreDeletedSignal, this, &MainWindow::removeSensoreWidget);
        connect(sw, &SensorWidget::sensoreEditedSignal, this, &MainWindow::sensorEditedSlot);
    }

    res->setLayout(sensorSectionLayout);
    scrollArea2->setWidget(res);
}

void MainWindow::showAllSensors()
{
    showSensors(controller->getSensori());
}

void MainWindow::showConnectionSensors(const Connection* connection)
{
    showSensors(connection->getSensori());
}

void MainWindow::showConnections(const std::vector<Connection*>& connections)
{
    if (connectionsList) {
        connectionsList = new QListWidget;
    }

    for (Connection* connection : connections) {
        QListWidgetItem* connectionItem = new QListWidgetItem("");
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

    connect(connectionsList, &QListWidget::itemClicked, this, [this, connections](QListWidgetItem* item) {
        size_t selectedIndex = connectionsList->row(item); // to avoid a warning
        if (selectedIndex < connections.size()) {
            Connection* selectedConnection = connections.at(selectedIndex);
            showConnectionSensors(selectedConnection);
        } else {
            qWarning() << "Selected connection index out of bounds";
        }
    });
}

void MainWindow::showAllConnections()
{
    showConnections(controller->getConnections());
}

void MainWindow::showHostConnections(const Host* host)
{
    showConnections(controller->getConnectionsByHost(host));
}

// JSON
void MainWindow::save()
{
    if (controller->getExportFilename().isEmpty()) {
        exportData();
    } else {
        if (controller->saveJSON()) {
            QMessageBox::information(this, "Save", QString::fromStdString("Sensors saved to ") + controller->getExportFilename());
        } else {
            QMessageBox::critical(this, "Error", QString::fromStdString("Unable to save sensors to file. \n") + controller->getLastErrorMessage());
        }
    }
}

void MainWindow::exportData()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export Sensors", "sensors.json", "JSON Files (*.json)");
    if (controller->exportDataJSON(fileName)) {
        QMessageBox::information(this, "Export", "Sensors exported to " + fileName);
    } else {
        QMessageBox::critical(this, "Export Error\n",
            QString::fromStdString("Unable to export sensors to file. \n") + controller->getLastErrorMessage());
    }
}

void MainWindow::importData()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Import Sensors", "", "JSON Files (*.json)");
    if (controller->importDataJSON(fileName)) {
        showAllSensors();
        QMessageBox::information(this, "Import", "Sensors imported from " + fileName);
    } else {
        QMessageBox::critical(this, "Import Error\n",
            "Unable to import sensors from file.\n" + controller->getLastErrorMessage());
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
    QWidget* topWidget = new QWidget;
    QHBoxLayout* topWidgetLayout = new QHBoxLayout(topWidget);
    topWidgetLayout->setAlignment(Qt::AlignTop);
    topWidgetLayout->setSizeConstraint(QLayout::SetMinimumSize);

    QPushButton* addButton = new QPushButton(" ADD");
    QIcon addIcon(":/resources/icons/add.png");
    addButton->setIcon(addIcon);
    addButton->setProperty("cssClass", "green");
    topWidgetLayout->addWidget(addButton);
    topWidgetLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    connect(addButton, SIGNAL(clicked()), this, SLOT(buttonSensoreAdded()));
    addButton->setShortcut(Qt::CTRL | Qt::Key_N);


    QLineEdit* searchBar = new QLineEdit;
    searchBar->setPlaceholderText("Search...");
    searchBar->setFixedWidth(200);
    searchBar->setFixedHeight(30);
    searchBar->setClearButtonEnabled(true);

    QIcon searchIcon(":/resources/icons/searchico.png");
    searchBar->addAction(searchIcon, QLineEdit::LeadingPosition);

    topWidgetLayout->addWidget(searchBar);

    column2->addWidget(topWidget);

    // Sensor section
    showAllSensors();
    column2->addWidget(scrollArea2);

    connect(searchBar, &QLineEdit::textChanged, this, [this](const QString& searchText) {
        if (searchText.isEmpty()) {
            showAllSensors();
            return;
        }
        std::vector<Sensore*> sensors = controller->getSensoriByName(searchText.toStdString());
        showSensors(sensors);
    });


    // First column
    QVBoxLayout* column1 = new QVBoxLayout;
    window->setLayout(mainLayout);
    mainLayout->addLayout(column1);
    // Column Title label
    QLabel* column1Title = new QLabel("Hosts");
    column1->addWidget(column1Title);
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);

    QListWidget* hostsList = new QListWidget;

    for (Host* host2 : controller->getHosts()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(host2->getName()));
        item->setIcon(QIcon(":/resources/icons/pc.png"));
        hostsList->addItem(item);
    }
    connect(hostsList, &QListWidget::itemClicked, this, [this, hostsList]() {
        QListWidgetItem* selectedItem = hostsList->currentItem();
        if (selectedItem) {
            QString hostName = selectedItem->text();

            const Host* selectedHost = controller->getHostByName(hostName.toStdString());
            showHostConnections(selectedHost);
        }
    });

    hostsList->setSelectionMode(QAbstractItemView::SingleSelection);
    hostsList->setSelectionBehavior(QAbstractItemView::SelectRows);
    hostsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    hostsList->setDragDropMode(QAbstractItemView::NoDragDrop);
    hostsList->setAlternatingRowColors(true);

    scrollArea->setWidget(hostsList);
    column1->addWidget(scrollArea);

    // Third column
    QVBoxLayout* column3 = new QVBoxLayout;
    mainLayout->addLayout(column3);
    QLabel* column3Title = new QLabel("Connections with chosen host");
    column3->addWidget(column3Title);
    scrollArea3 = new QScrollArea;
    scrollArea3->setWidgetResizable(true);

    connectionsList = new QListWidget;
    showAllConnections();

    scrollArea3->setWidget(connectionsList);
    column3->addWidget(scrollArea3);

    setCentralWidget(window);

    if (!findChild<QToolBar*>("ToolBar")) {
        QToolBar* toolbar = addToolBar("ToolBar");
        toolbar->setObjectName("ToolBar");
        toolbar->setFloatable(false);

        QToolButton* saveButton = new QToolButton(this);
        saveButton->setIcon(QIcon(":/resources/icons/save.png"));
        saveButton->setText("Save");
        saveButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        saveButton->setProperty("cssClass", "label");
        saveButton->setShortcut(Qt::CTRL | Qt::Key_S);
        toolbar->addWidget(saveButton);

        QToolButton* exportButton = new QToolButton(this);
        exportButton->setIcon(QIcon(":/resources/icons/export.png"));
        exportButton->setText("Export");
        exportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        exportButton->setProperty("cssClass", "label");
        exportButton->setShortcut(Qt::CTRL | Qt::Key_E);
        toolbar->addWidget(exportButton);

        QToolButton* importButton = new QToolButton(this);
        importButton->setIcon(QIcon(":/resources/icons/import.png"));
        importButton->setText("Import");
        importButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        importButton->setProperty("cssClass", "label");
        importButton->setShortcut(Qt::CTRL | Qt::Key_I);
        toolbar->addWidget(importButton);

        connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
        connect(exportButton, SIGNAL(clicked()), this, SLOT(exportData()));
        connect(importButton, SIGNAL(clicked()), this, SLOT(importData()));
    }
}

// destructor
MainWindow::~MainWindow()
{
    delete connectionsList;
    delete scrollArea3;
    delete scrollArea2;
    delete controller;
    delete window;
}
