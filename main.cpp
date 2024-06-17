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
#include "model/host.cpp"
// #include "model/connection.cpp"
// #include "model/sensoreBanda.cpp"



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

    // // Create a new host
    // Host *h1 = new Host("123");
    // Host *h2 = new Host("456");

    // // Create a new connection
    // Connection *c1 = new Connection("abc", *h1, *h2);
    
    // for (int i = 0; i < 5; i++)
    // {
    //     c1->addSensore(new SensoreBanda(10));
    // }

    // // Create the main window
    // MainWindow window(c1, c1->getSensori().size());
    
    MainWindow window;

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
