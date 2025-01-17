QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    model/core/connection.cpp \
    model/core/host.cpp \
    model/json/jsonManager.cpp \
    main.cpp \
    controller.cpp \
    mainwindow.cpp \
    model/core/pacchetto.cpp \
    model/core/pacchettoBanda.cpp \
    model/core/pacchettoCarico.cpp \
    model/core/pacchettoErrori.cpp \
    model/core/pacchettoJitter.cpp \
    model/core/pacchettoDelay.cpp \
    model/core/sensore.cpp \
    model/core/sensoreBanda.cpp \
    model/core/sensoreCarico.cpp \
    model/core/sensoreErrori.cpp\
    model/core/sensoreJitter.cpp \
    model/core/sensoreDelay.cpp \
    view/aggiuntaSensoreWidget.cpp \
    view/graficoSensore.cpp \
    view/sensorWidget.cpp \

HEADERS += \
    model/core/connection.h \
    model/core/host.h \
    model/core/IConstSensorVisitor.h \
    model/core/ISensorVisitor.h \
    model/json/jsonManager.h \
    mainwindow.h \
    controller.h \
    model/core/pacchetto.h \
    model/core/pacchettoBanda.h \
    model/core/pacchettoCarico.h \
    model/core/pacchettoErrori.h \
    model/core/pacchettoJitter.h \
    model/core/pacchettoDelay.h \
    model/core/sensore.h \
    model/core/sensoreBanda.h \
    model/core/sensoreCarico.h \
    model/core/sensoreErrori.h \
    model/core/sensoreJitter.h \
    model/core/sensoreDelay.h \
    view/aggiuntaSensoreWidget.h \
    view/graficoSensore.h \
    view/sensorWidget.h \

RESOURCES += \
    resources/resources.qrc

ICON = appico.icns
RC_ICONS = appico.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
