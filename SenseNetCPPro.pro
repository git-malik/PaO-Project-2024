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
    #model/saveException.cpp \
    main.cpp \
    controller.cpp \
    mainwindow.cpp \
    model/core/pacchetto.cpp \
    model/core/pacchettoBanda.cpp \
    model/core/pacchettoCarico.cpp \
    model/core/pacchettoErrori.cpp \
    model/core/sensore.cpp \
    model/core/sensoreBanda.cpp \
    model/core/sensoreCarico.cpp \
    model/core/sensoreErrori.cpp\
    view/aggiuntaSensore.cpp \
    view/graficoSensore.cpp \
    view/sensorWidget.cpp \

HEADERS += \
    model/core/connection.h \
    model/core/host.h \
    model/json/jsonManager.h \
    model/saveException.h \
    mainwindow.h \
    controller.h \
    model/core/pacchetto.h \
    model/core/pacchettoBanda.h \
    model/core/pacchettoCarico.h \
    model/core/pacchettoErrori.h \
    model/core/sensore.h \
    model/core/sensoreBanda.h \
    model/core/sensoreCarico.h \
    model/core/sensoreErrori.h \
    view/aggiuntaSensore.h \
    view/graficoSensore.h \
    view/sensorWidget.h \

RESOURCES += \
    resources/resources.qrc

TRANSLATIONS += \
    SenseNetCPPro_en_150.ts
CONFIG += lrelease
CONFIG += embed_translations
ICON = appico.icns
RC_ICONS = appico.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
