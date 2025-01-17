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
#include <cstdlib>
#include "../model/core/sensore.h"
#include "../model/core/pacchetto.h"
#include "../model/core/IConstSensorVisitor.h"
#include "../model/core/sensoreCarico.h"
#include "../model/core/sensoreErrori.h"
#include "../model/core/sensoreBanda.h"
#include "../model/core/sensoreJitter.h"
#include "../model/core/sensoreDelay.h"
//include pacchetto
#include "../model/core/pacchettoCarico.h"
#include "../model/core/pacchettoErrori.h"
#include "../model/core/pacchettoBanda.h"
#include "../model/core/pacchettoJitter.h"
#include "../model/core/pacchettoDelay.h"

class GraficoSensore : public QWidget, public IConstSensorVisitor
{
    Q_OBJECT
    public:
    //
        GraficoSensore(Sensore* sensore, QWidget *parent = nullptr);
        ~GraficoSensore();
        // visit
        void visit(const SensoreCarico* sensore) override;
        void visit(const SensoreErrori* sensore) override;
        void visit(const SensoreBanda* sensore) override;
        void visit(const SensoreJitter* sensore) override;
        void visit(const SensoreDelay* sensore) override;
        
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
