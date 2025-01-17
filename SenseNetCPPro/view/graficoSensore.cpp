#include "graficoSensore.h"

GraficoSensore::GraficoSensore(Sensore* sensore, QWidget* parent)
    : QWidget(parent)
    , sensore(sensore)
    , layout(new QVBoxLayout(this))
{
    m_chart = new QChart();
    m_chartView = new QChartView(m_chart);
    m_series = new QLineSeries();
    m_axisX = new QDateTimeAxis();
    m_axisY = new QValueAxis();
    setMinimumWidth(700);
    setMinimumHeight(500);
    m_chart->setTitle(QString::fromStdString(sensore->getId()));
    m_axisX->setTitleText("Time");
    m_chart->legend()->show();
    sensore->accept(this);
    m_series->setMarkerSize(8);
    m_axisX->setRange(QDateTime::currentDateTime().addSecs(+3600), QDateTime::currentDateTime());


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
}

void GraficoSensore::visit(const SensoreCarico* sensoreCarico)
{
    m_series->setName("Connection's load level through time");
    m_axisY->setTitleText("Load Level in %");
    m_axisY->setRange(0, 100);
    std::vector<const PacchettoCarico*> pacchetti = sensoreCarico->getPacchetti();
    for (const PacchettoCarico* pacchetto : pacchetti) {
        QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime()); 
        float value = pacchetto->getValore();
        m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
    }
}

void GraficoSensore::visit(const SensoreBanda* sensoreBanda)
{
    m_series->setName("Connection's bandwidth usage through time");
    m_axisY->setTitleText("Bandwidth Usage in Mbps");
    m_axisY->setRange(0, 1000);
    std::vector<const PacchettoBanda*> pacchetti = sensoreBanda->getPacchetti();
    for (const PacchettoBanda* pacchetto : pacchetti) {
        QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime());
        float value = pacchetto->getValore(); 
        m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
    }
}

void GraficoSensore::visit(const SensoreErrori* sensoreErrori)
{
    
    m_series->setName("Connection's error rate through time");
    m_axisY->setTitleText("Number of Errors");
    m_axisY->setRange(0, 500);
    // Set the color of the line series to red
    m_series->setColor(QColor(255, 0, 0));
    std::vector<const PacchettoErrori*> pacchetti = sensoreErrori->getPacchetti();
    for (const PacchettoErrori* pacchetto : pacchetti) {
        QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime());
        float value = pacchetto->getValore(); 
        m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
    }
}

void GraficoSensore::visit(const SensoreJitter* sensoreJitter)
{
    
    m_series->setName("Connection's jitter through time");
    m_axisY->setTitleText("Jitter in ms");
    m_axisY->setRange(0, 50);
    std::vector<const PacchettoJitter*> pacchetti = sensoreJitter->getPacchetti();
    for (const PacchettoJitter* pacchetto : pacchetti) {
        QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime());
        float value = pacchetto->getValore(); 
        m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
    }
}

void GraficoSensore::visit(const SensoreDelay* sensoreDelay)
{
    
    m_series->setName("Connection's delay through time");
    m_axisY->setTitleText("Delay in ms");
    m_axisY->setRange(0, 1000);
    std::vector<const PacchettoDelay*> pacchetti = sensoreDelay->getPacchetti();
    for (const PacchettoDelay* pacchetto : pacchetti) {
        QDateTime timestamp = QDateTime::fromSecsSinceEpoch(pacchetto->getTime());
        float value = pacchetto->getValore(); 
        m_series->append(QPointF(timestamp.toMSecsSinceEpoch(), value));
    }
}

GraficoSensore::~GraficoSensore()
{
    delete m_axisX;
    delete m_axisY;
    delete m_series;
    delete m_chartView;
    delete m_chart;
    delete layout;

}
