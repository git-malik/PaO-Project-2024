#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollArea>
#include <QCheckBox>
#include <QScrollBar>
#include <QSlider>
#include <QScroller>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QSpacerItem>
#include <QFile>
#include <QIcon>
#include <QPixmap>
#include <QMenuBar>
#include <QMenu>
#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // QWidget window;
    QWidget *window = new QWidget;
    window->setWindowTitle("SensNet");

    // MainWindow window;
    QHBoxLayout *mainLayout = new QHBoxLayout(window);

    // Columns
    // Second column
    QVBoxLayout *column2 = new QVBoxLayout;
    mainLayout->addLayout(column2);
    // Column Title label
    QLabel *column2Title = new QLabel("Sensors for chosen host");
    column2->addWidget(column2Title);
    // List of sensors (scrollable)
    QScrollArea *scrollArea2 = new QScrollArea;
    scrollArea2->setWidgetResizable(true);
    // add a widget to the top, before the scroll area
    QWidget *topWidget = new QWidget;
    QHBoxLayout *topWidgetLayout = new QHBoxLayout(topWidget);
    topWidgetLayout->setAlignment(Qt::AlignTop);
    topWidgetLayout->setSizeConstraint(QLayout::SetMinimumSize);

    // Add an "Add +" button
    QPushButton *addButton = new QPushButton(" ADD");
    QIcon addIcon(":/resources/icons/add.png");
    addButton->setIcon(addIcon);
    // addButton->setObjectName("green");
    addButton->setProperty("cssClass", "green");
    topWidgetLayout->addWidget(addButton);
    topWidgetLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    // Add a search bar with magnifying glass icon
    QLineEdit *searchBar = new QLineEdit;
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
    QWidget *sensorSection = new QWidget;
    QVBoxLayout *sensorSectionLayout = new QVBoxLayout(sensorSection);
    // align to the top
    sensorSectionLayout->setAlignment(Qt::AlignTop);
    // sets the layout size constraint to minimum size
    sensorSectionLayout->setSizeConstraint(QLayout::SetMinimumSize);

    // add an horizontal layout for the sensor name and the sensor id
    QHBoxLayout *sensorNameId = new QHBoxLayout;
    QLabel *sensorName = new QLabel("Speed");
    QLabel *sensorId = new QLabel("#AD0");

    // Add a horizontal spacer to align the labels to the left
    // QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    sensorNameId->addWidget(sensorName);
    sensorNameId->addWidget(sensorId);
    sensorNameId->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    sensorSectionLayout->addLayout(sensorNameId);

    // Add an horizontal layout for the sensor graphic and the sensor value
    QHBoxLayout *sensorGraphicValue = new QHBoxLayout;
    QVBoxLayout *sensorGraphicLayout = new QVBoxLayout;
    QGridLayout *sensorValueLayout = new QGridLayout; // Changed to QGridLayout

    QLabel *sensorGraphic = new QLabel("Graphic");
    sensorGraphicLayout->addWidget(sensorGraphic);

    // Create four QLabel objects for the values
    QLabel *value1 = new QLabel("Value 1");
    QLabel *value2 = new QLabel("Value 2");
    QLabel *value3 = new QLabel("Value 3");
    QLabel *value4 = new QLabel("Value 4");

    // Add the QLabel objects to the QGridLayout
    sensorValueLayout->addWidget(value1, 0, 0);
    sensorValueLayout->addWidget(value2, 0, 1);
    sensorValueLayout->addWidget(value3, 1, 0);
    sensorValueLayout->addWidget(value4, 1, 1);

    sensorGraphicValue->addLayout(sensorGraphicLayout);
    sensorGraphicValue->addLayout(sensorValueLayout); // Added the sensorValueLayout to the sensorGraphicValue layout

    sensorSectionLayout->addLayout(sensorGraphicValue);

    // Add an "Open" button
    QPushButton *openButton = new QPushButton(" OPEN");
    QIcon openIcon(":/resources/icons/open.png");
    openButton->setIcon(openIcon);
    sensorGraphicLayout->addWidget(openButton);

    // Add an horizontal layout for the "Edit" button and the "Delete" button
    QHBoxLayout *sensorEditDelete = new QHBoxLayout;
    QPushButton *editButton = new QPushButton(" EDIT");
    // adds the default QT edit icon
    QIcon editIcon(":/resources/icons/edit.png");
    editButton->setIcon(editIcon);
    editButton->setProperty("cssClass", "blue");
    QPushButton *deleteButton = new QPushButton(" DELETE");
    QIcon deleteIcon(":/resources/icons/delete.png");
    deleteButton->setIcon(deleteIcon);
    deleteButton->setProperty("cssClass", "red");
    sensorEditDelete->addWidget(editButton);
    sensorEditDelete->addWidget(deleteButton);

    // Add a horizontal spacer to align the buttons to the left
    sensorEditDelete->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    // sensorEditDelete->addItem();

    sensorSectionLayout->addLayout(sensorEditDelete);

    // Add the sensor section to the scroll area
    scrollArea2->setWidget(sensorSection);
    column2->addWidget(scrollArea2);




    // First column
    QVBoxLayout *column1 = new QVBoxLayout;
    window->setLayout(mainLayout); // Set mainLayout as the layout for the MainWindow object
    mainLayout->addLayout(column1);
    // Column Title label
    QLabel *column1Title = new QLabel("Hosts");
    column1->addWidget(column1Title);
    // List of hosts (scrollable)
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);

    QListWidget *hostsList = new QListWidget;
    // Add icon with text with every item
    QListWidgetItem *item1 = new QListWidgetItem("Host 1");
    item1->setIcon(QIcon(":/resources/icons/pc.png"));
    hostsList->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem("Host 2");
    item2->setIcon(QIcon(":/resources/icons/pc.png"));
    hostsList->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem("Host 3");
    item3->setIcon(QIcon(":/resources/icons/pc.png"));
    hostsList->addItem(item3);

    hostsList->setSelectionMode(QAbstractItemView::SingleSelection);
    hostsList->setSelectionBehavior(QAbstractItemView::SelectRows);
    hostsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    hostsList->setDragDropMode(QAbstractItemView::NoDragDrop);
    hostsList->setAlternatingRowColors(true);
    // hostsList->setStyleSheet("QListWidget::item { border-bottom: 1px solid black; }");

    scrollArea->setWidget(hostsList);
    column1->addWidget(scrollArea);




    // Third column
    QVBoxLayout *column3 = new QVBoxLayout;
    mainLayout->addLayout(column3);
    // Column Title label
    QLabel *column3Title = new QLabel("Connections with chosen host");
    column3->addWidget(column3Title);
    // List of connections (scrollable)
    QScrollArea *scrollArea3 = new QScrollArea;
    scrollArea3->setWidgetResizable(true);


    // Connections section
    QListWidget *connectionsList = new QListWidget;
    QListWidgetItem *connection1 = new QListWidgetItem("");
    // Create widgets for the connection
    QWidget *connection1Widget = new QWidget;
    QLabel *connection1Label = new QLabel("Host 1");
    QLabel *connection1Labelicon = new QLabel;
    QIcon connectionIcon(":/resources/icons/Connection.png");
    connection1Labelicon->setPixmap(connectionIcon.pixmap(64, 16));
    QLabel *connection1Label2 = new QLabel("Host 2");
    QHBoxLayout *connection1Layout = new QHBoxLayout(connection1Widget);
    connection1Layout->addWidget(connection1Label);
    connection1Layout->addWidget(connection1Labelicon);
    connection1Layout->addWidget(connection1Label2);
    // spacer
    connection1Layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    connection1->setSizeHint(connection1Widget->sizeHint());
    connectionsList->addItem(connection1);
    connectionsList->setItemWidget(connection1, connection1Widget);
    connectionsList->setAlternatingRowColors(true);

    scrollArea3->setWidget(connectionsList);
    column3->addWidget(scrollArea3);


    // Set the toolbar
    QToolBar *toolbar = addToolBar("ToolBar");
    toolbar->setFloatable(false);
    // toolbar->setMovable(false);

    // Save button
    QToolButton *saveButton = new QToolButton(this);
    saveButton->setIcon(QIcon(":/resources/icons/save.png"));
    saveButton->setText("Save");
    saveButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    saveButton->setProperty("cssClass", "label");
    toolbar->addWidget(saveButton);

    // Export button
    QToolButton *exportButton = new QToolButton(this);
    exportButton->setIcon(QIcon(":/resources/icons/export.png"));
    exportButton->setText("Export");
    exportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    exportButton->setProperty("cssClass", "label");
    toolbar->addWidget(exportButton);

    // Import button
    QToolButton *importButton = new QToolButton(this);
    importButton->setIcon(QIcon(":/resources/icons/import.png"));
    importButton->setText("Import");
    importButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    importButton->setProperty("cssClass", "label");
    toolbar->addWidget(importButton);

    // Connect the clicked signal of the buttons to slots
    // connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    // connect(exportButton, SIGNAL(clicked()), this, SLOT(export()));

    // Set the central widget
    setCentralWidget(window);
}

MainWindow::~MainWindow() {}
