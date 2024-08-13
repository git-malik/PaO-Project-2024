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
#include <QtWidgets/QMainWindow>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include "model/core/host.cpp"
#include "model/core/connection.h"
#include "model/core/sensoreBanda.h"
#include "model/core/sensoreErrori.h"
#include "model/core/sensoreCarico.h"
#include "controller.cpp"



// #include "mainwindow.h" // Add missing include statement for MainWindow class

// JSON WRITING TEST
// struct Sensor {
//     std::string id;
//     std::string name;
//     std::vector<Pacchetto*> pacchetti;
//     Sensor(std::string id, std::string name, std::vector<Pacchetto*> pacchetti) : id(id), name(name), pacchetti(pacchetti) {}
// };

// Sensor s1("1", "Sensore1", std::vector<Pacchetto*>());

// QJsonObject content;
// content.insert("id", QString::fromStdString(s1.id));
// content.insert("name", QString::fromStdString(s1.name));
// QJsonArray pacchetti;
// for (Pacchetto* p : s1.pacchetti) {
//     QJsonObject pacchetto;
//     pacchetto.insert("id", QString::fromStdString(p->getId()));
//     pacchetto.insert("name", QString::fromStdString(p->getName()));
//     pacchetti.append(pacchetto);
// }
// content.insert("pacchetti", pacchetti);

// QJsonDocument document;
// QJsonDocument doc(content);
// QString jsonString = doc.toJson(QJsonDocument::Indented);
// QFile file("sensor.json");
// if (file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
//     QTextStream iStream( &file );
//     iStream.setCodec( "utf-8" );
//     iStream << bytes;
//     file.close();
// } else {
//     cout << "file open failed: " << path.toStdString() << endl;
// }

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


    Controller *controller = new Controller();
    //  // Create a new host
    Host *a = new Host("A");
    Host *b = new Host("B");
    Host *c = new Host("C");
    Host *d = new Host("D");


    //  // Create a new connection
    Connection *c1 = new Connection("A-B", *a, *b);
    Connection *c2 = new Connection("B-C", *b, *c);
    Connection *c3 = new Connection("C-D", *c, *d);
    Connection *c4 = new Connection("A-C", *a, *c);

    SensoreBanda *s1 = new SensoreBanda();
    SensoreCarico *s2 = new SensoreCarico();
    SensoreErrori *s3 = new SensoreErrori();
    c1->addSensore(*s1);
    c2->addSensore(*s2);
    c3->addSensore(*s3);

    // Add hosts to controller
    controller->addHost(a);
    controller->addHost(b);
    controller->addHost(c);
    controller->addHost(d);

    // Add connections to controller
    controller->addConnection(c1);
    controller->addConnection(c2);
    controller->addConnection(c3);
    controller->addConnection(c4);

    // Add sensors to connection
    controller->addSensore(s1);
    controller->addSensore(s2);
    controller->addSensore(s3);

    //da migliorare

    // Create the main window
    //MainWindow window(hostlist, 4, connlist, 4, sensorVector);
    
    MainWindow window(controller, nullptr);

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
