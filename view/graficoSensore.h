#ifndef GRAFICOSENSORE
#define GRAFICOSENSORE

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include "../model/sensore.h"

class GraficoSensore : public QWidget
{
    Q_OBJECT
    public:
        GraficoSensore(Sensore *sensore, QWidget *parent = nullptr);
        GraficoSensore(QWidget *parent = nullptr);
        void setSensore(Sensore *sensore);
        //setters
        void setXAxis(QDateTimeAxis *axis);
        void setYAxis(QValueAxis *axis);
        void setChart(QChart *chart);
        void setChartView(QChartView *chartView);
        void setSeries(QLineSeries *series);
        //getters
        QDateTimeAxis *getXAxis();
        QValueAxis *getYAxis();
        QChart *getChart();
        QChartView *getChartView();
        QLineSeries *getSeries();
        ~GraficoSensore();
    private:
        QChart *m_chart;
        QChartView *m_chartView;
        QLineSeries *m_series;
        QDateTimeAxis *m_axisX;
        QValueAxis *m_axisY;
};

#endif // GRAFICOSENSORE
