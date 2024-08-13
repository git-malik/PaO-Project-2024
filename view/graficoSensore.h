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
#include "../model/core/sensore.h"
#include "../model/core/pacchetto.h"
#include "../model/core/sensoreCarico.h"
#include "../model/core/sensoreErrori.h"
#include "../model/core/sensoreBanda.h"
//include pacchetto
#include "../model/core/pacchettoCarico.h"
#include "../model/core/pacchettoErrori.h"
#include "../model/core/pacchettoBanda.h"
#include <cstdlib>

class GraficoSensore : public QWidget
{
    Q_OBJECT
    public:
    //
        GraficoSensore(Sensore* sensore, QWidget *parent = nullptr);
        // GraficoSensore(QWidget *parent = nullptr);
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
        //set layout
        ~GraficoSensore();
    private:
        Sensore* sensore;
        QChart *m_chart;
        QChartView *m_chartView;
        QLineSeries *m_series;
        QDateTimeAxis *m_axisX;
        QValueAxis *m_axisY;
        QVBoxLayout* layout;
};

#endif // GRAFICOSENSORE
