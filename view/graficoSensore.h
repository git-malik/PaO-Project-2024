#ifndef GRAFICOSENSORE
#define GRAFICOSENSORE

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QDateTime>
#include <QVBoxLayout>
#include <QString>
#include "../model/sensore.h"
#include "../model/pacchetto.h"

using namespace QtCharts;

class GraficoSensore : public QWidget
{
    Q_OBJECT
    public:
    //
        GraficoSensore(Sensore *sensore, QWidget *parent = nullptr);
        GraficoSensore(QWidget *parent = nullptr);
        void setSensore(Sensore *sensore);
        //setters
        void setXAxis(QtCharts::QDateTimeAxis *axis);
        void setYAxis(QtCharts::QValueAxis *axis);
        void setChart(QtCharts::QChart *chart);
        void setChartView(QtCharts::QChartView *chartView);
        void setSeries(QtCharts::QLineSeries *series);
        //getters
        QDateTimeAxis *getXAxis();
        QValueAxis *getYAxis();
        QChart *getChart();
        QChartView *getChartView();
        QLineSeries *getSeries();
        //set layout
        ~GraficoSensore();
    private:
        QChart *m_chart;
        QChartView *m_chartView;
        QLineSeries *m_series;
        QDateTimeAxis *m_axisX;
        QValueAxis *m_axisY;
        QVBoxLayout* layout;
};

#endif // GRAFICOSENSORE
