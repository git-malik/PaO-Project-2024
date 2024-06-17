#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// #include "model/connection.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // MainWindow(Connection *data, int size, QWidget *parent = nullptr);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //openChart slot
    void openChart();
    void addSensore();
private:
    // Connection *c_data;
    int c_size;
};
#endif // MAINWINDOW_H
