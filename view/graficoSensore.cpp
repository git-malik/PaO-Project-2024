#include "graficoSensore.h"
//todo molto più avanti
//slidegrid

GraficoSensore::GraficoSensore(QWidget *parent) : QWidget(parent)
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
}

GraficoSensore::GraficoSensore(Sensore *sensore, QWidget *parent) : QWidget(parent)
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

    // Add data points from sensore.getPacchetti()
    // std::vector<Pacchetto*> pacchetti = sensore->getPacchetti();
    // for (const Pacchetto& pacchetto : pacchetti) {
    //     QDateTime timestamp = pacchetto.getTime(); // Assuming Pacchetto has a getTimestamp() method
    //     double value = pacchetto.getValue(); // Assuming Pacchetto has a getValue() method
    //     m_series->append(timestamp.toMSecsSinceEpoch(), value);
    // }
}

void GraficoSensore::setSensore(Sensore *sensore)
{
    // Clear the series
    m_series->clear();

    // Add data points from sensore.getPacchetti()
    // std::vector<Pacchetto*> pacchetti = sensore->getPacchetti();
    // for (const Pacchetto& pacchetto : pacchetti) {
    //     QDateTime timestamp = pacchetto.getTime(); // Assuming Pacchetto has a getTimestamp() method
    //     double value = pacchetto.getValue(); // Assuming Pacchetto has a getValue() method
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