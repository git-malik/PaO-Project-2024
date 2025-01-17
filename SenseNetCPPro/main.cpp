#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>



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
    MainWindow window;
    window.show();
    return app.exec();
}
