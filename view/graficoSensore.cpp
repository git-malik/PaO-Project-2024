#include "graficoSensore.h"
#include "../model/pacchetto.cpp"

#include "../model/sensoreCarico.h"
#include "../model/sensoreErrori.h"
#include "../model/sensoreBanda.h"
//include pacchetto
#include "../model/pacchettoCarico.h"
#include "../model/pacchettoErrori.h"
#include "../model/pacchettoBanda.h"


//todo molto più avanti
//slidegrid

GraficoSensore::GraficoSensore(QWidget *parent) : QWidget(parent), layout(new QVBoxLayout(this))
{
    m_chart = new QChart();
    m_chartView = new QChartView(m_chart);
    m_series = new QLineSeries();
    m_axisX = new QDateTimeAxis(); // Use QDateTimeAxis for timestamp on x-axis
    m_axisY = new QValueAxis();
    m_chart->addSeries(m_series);
    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_chart->addAxis(m_axisY, Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setRubberBand(QChartView::RectangleRubberBand);
    m_chartView->setDragMode(QGraphicsView::RubberBandDrag);
    m_chartView->setInteractive(true);
    m_chartView->setMouseTracking(true);
    m_chartView->setChart(m_chart);

    layout->addWidget(m_chartView);
    setLayout(layout);
    //set min widht and height
    setMinimumWidth(500);
    setMinimumHeight(500);


}

GraficoSensore::GraficoSensore(Sensore *sensore, QWidget *parent) : QWidget(parent), layout(new QVBoxLayout(this))
{

    m_chart = new QChart();
    m_chartView = new QChartView(m_chart);
    m_series = new QLineSeries();
    m_axisX = new QDateTimeAxis(); // Use QDateTimeAxis for timestamp on x-axis
    m_axisY = new QValueAxis();
    m_chart->addSeries(m_series);
    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_chart->addAxis(m_axisY, Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setRubberBand(QChartView::RectangleRubberBand);
    m_chartView->setDragMode(QGraphicsView::RubberBandDrag);
    m_chartView->setInteractive(true);
    m_chartView->setMouseTracking(true);
    m_chartView->setChart(m_chart);

    layout->addWidget(m_chartView);
    setLayout(layout);
    //set min widht and height
    setMinimumWidth(500);
    setMinimumHeight(500);

    //add sensor name to the chart
    m_chart->setTitle(QString::fromStdString(sensore->getId()));

    //check if the sensor is a load sensor or a speed sensor or an error sensor and add the data accordingly
    if (SensoreCarico* sensoreCarico = dynamic_cast<SensoreCarico*>(sensore)) {
        // Add data points from sensore.getPacchetti()
        std::vector<PacchettoCarico*> pacchetti = sensoreCarico->getPacchetti();
        for (PacchettoCarico* pacchetto : pacchetti) {
            QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime()); // Assuming Pacchetto has a getTimestamp() method that returns a time in seconds
            float value = pacchetto->getValore(); // Assuming Pacchetto has a getValue() method
            m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
        }
    } else if (SensoreBanda* sensoreBanda = dynamic_cast<SensoreBanda*>(sensore)) {
        // Add data points from sensore.getPacchetti()
        std::vector<PacchettoBanda*> pacchetti = sensoreBanda->getPacchetti();
        for (PacchettoBanda* pacchetto : pacchetti) {
            QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime()); // Assuming Pacchetto has a getTimestamp() method that returns a time in seconds
            float value = pacchetto->getValore(); // Assuming Pacchetto has a getValue() method
            m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
        }
    } else if (SensoreErrori* sensoreErrori = dynamic_cast<SensoreErrori*>(sensore)) {
        // Add data points from sensore.getPacchetti()
        std::vector<PacchettoErrori*> pacchetti = sensoreErrori->getPacchetti();
        for (PacchettoErrori* pacchetto : pacchetti) {
            QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime()); // Assuming Pacchetto has a getTimestamp() method that returns a time in seconds
            float value = pacchetto->getValore(); // Assuming Pacchetto has a getValue() method
            m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
        }
    }

    //set the chart scale to the maximum value of the sensor
    m_axisY->setRange(0, 100);
    //set the chart scale to the maximum value of the sensor
    m_axisX->setRange(QDateTime::currentDateTime().addSecs(-60), QDateTime::currentDateTime());

}

void GraficoSensore::setSensore(Sensore *sensore)
{
    // Clear the series
    m_series->clear();

    // Add data points from sensore.getPacchetti()
    // std::vector<Pacchetto*> pacchetti = sensore->getPacchetti();
    // for (Pacchetto* pacchetto : pacchetti) {
    //     QDateTime timestamp = QDateTime::currentDateTime(); // Assuming Pacchetto has a getTimestamp() method
    //     double value = pacchetto->getValore(); // Assuming Pacchetto has a getValue() method
    //     m_series->append(timestamp.toMSecsSinceEpoch(), value);
    // }
}

void GraficoSensore::setXAxis(QDateTimeAxis *axis)
{
    m_axisX = axis;
}

void GraficoSensore::setYAxis(QValueAxis *axis)
{
    m_axisY = axis;
}

void GraficoSensore::setChart(QChart *chart)
{
    m_chart = chart;
}

void GraficoSensore::setChartView(QChartView *chartView)
{
    m_chartView = chartView;
}

void GraficoSensore::setSeries(QLineSeries *series)
{
    m_series = series;
}

QDateTimeAxis *GraficoSensore::getXAxis()
{
    return m_axisX;
}

QValueAxis *GraficoSensore::getYAxis()
{
    return m_axisY;
}

QChart *GraficoSensore::getChart()
{
    return m_chart;
}

QChartView *GraficoSensore::getChartView()
{
    return m_chartView;
}

QLineSeries *GraficoSensore::getSeries()
{
    return m_series;
}

GraficoSensore::~GraficoSensore()
{
    delete m_chart;
    delete m_chartView;
    delete m_series;
    delete m_axisX;
    delete m_axisY;
}
