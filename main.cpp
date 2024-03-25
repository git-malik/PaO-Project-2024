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

// #include "mainwindow.h" // Add missing include statement for MainWindow class

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Load resources
    Q_INIT_RESOURCE(resources);

    // Load an application style
    QFile styleFile(":/styles/styles/main.qss");
    styleFile.open(QFile::ReadOnly);

    // Apply the loaded stylesheet
    QString style(styleFile.readAll());
    app.setStyleSheet(style);

    // Main window
    QWidget window;
    // MainWindow window;
    QHBoxLayout *mainLayout = new QHBoxLayout(&window);

    // Columns
    // First column
    QVBoxLayout *column1 = new QVBoxLayout;
    window.setLayout(mainLayout); // Set mainLayout as the layout for the MainWindow object
    mainLayout->addLayout(column1);
    // Column Title label
    QLabel *column1Title = new QLabel("Hosts");
    column1->addWidget(column1Title);
    // List of hosts (scrollable)
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);

    QListWidget *hostsList = new QListWidget;
    hostsList->addItem("Host 1");
    hostsList->addItem("Host 2");
    hostsList->addItem("Host 3");
    hostsList->addItem("Host 4");
    hostsList->addItem("Host 5");
    hostsList->addItem("Host 6");
    hostsList->addItem("Host 7");
    hostsList->addItem("Host 8");
    hostsList->addItem("Host 9");
    hostsList->addItem("Host 10");
    hostsList->addItem("Host 11");
    hostsList->addItem("Host 12");

    hostsList->setSelectionMode(QAbstractItemView::SingleSelection);
    hostsList->setSelectionBehavior(QAbstractItemView::SelectRows);
    hostsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    hostsList->setDragDropMode(QAbstractItemView::NoDragDrop);
    hostsList->setAlternatingRowColors(true);
    hostsList->setStyleSheet("QListWidget::item { border-bottom: 1px solid black; }");
    hostsList->setFixedWidth(200);
    hostsList->setFixedHeight(300);

    scrollArea->setWidget(hostsList);
    column1->addWidget(scrollArea);



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
    QPushButton *addButton = new QPushButton("Add +");
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
    QPushButton *openButton = new QPushButton("Open");
    sensorGraphicLayout->addWidget(openButton);

    // Add an horizontal layout for the "Edit" button and the "Delete" button
    QHBoxLayout *sensorEditDelete = new QHBoxLayout;
    QPushButton *editButton = new QPushButton("Edit");
    QPushButton *deleteButton = new QPushButton("Delete");
    sensorEditDelete->addWidget(editButton);
    sensorEditDelete->addWidget(deleteButton);

    // Add a horizontal spacer to align the buttons to the left
    sensorEditDelete->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    // sensorEditDelete->addItem();

    sensorSectionLayout->addLayout(sensorEditDelete);

    // Add the sensor section to the scroll area
    scrollArea2->setWidget(sensorSection);
    column2->addWidget(scrollArea2);









    // Third column
    QVBoxLayout *column3 = new QVBoxLayout;
    mainLayout->addLayout(column3);
    // Column Title label
    QLabel *column3Title = new QLabel("Connections with chosen host");
    column3->addWidget(column3Title);
    // List of connections (scrollable)
    QScrollArea *scrollArea3 = new QScrollArea;
    scrollArea3->setWidgetResizable(true);

    QListWidget *connectionsList = new QListWidget;
    connectionsList->addItem("Connection 1");
    connectionsList->addItem("Connection 2");
    connectionsList->addItem("Connection 3");

    connectionsList->setSelectionMode(QAbstractItemView::SingleSelection);
    connectionsList->setSelectionBehavior(QAbstractItemView::SelectRows);
    connectionsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connectionsList->setDragDropMode(QAbstractItemView::NoDragDrop);
    connectionsList->setAlternatingRowColors(true);
    connectionsList->setStyleSheet("QListWidget::item { border-bottom: 1px solid black; }");
    connectionsList->setFixedWidth(200);
    connectionsList->setFixedHeight(300);

    scrollArea3->setWidget(connectionsList);
    column3->addWidget(scrollArea3);


    window.show();
    return app.exec();
}



// #include "mainwindow.h"

// #include <QApplication>
// #include <QLocale>
// #include <QTranslator>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);

//     QTranslator translator;
//     const QStringList uiLanguages = QLocale::system().uiLanguages();
//     for (const QString &locale : uiLanguages) {
//         const QString baseName = "SensNetCPP_" + QLocale(locale).name();
//         if (translator.load(":/i18n/" + baseName)) {
//             a.installTranslator(&translator);
//             break;
//         }
//     }
//     MainWindow w;
//     w.show();
//     return a.exec();
// }
