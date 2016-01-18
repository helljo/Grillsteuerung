#-------------------------------------------------
#
# Project created by QtCreator 2014-08-21T22:50:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visualisierung_Grill
TEMPLATE = app


SOURCES += main.cpp\
        visualisierung_grill.cpp \
    diagramm.cpp \
    grillposition.cpp \
    ist_soll_anzeige.cpp \
    status_anzeige.cpp \
    grillsteuerung.cpp \
    Motorsteuerung.cpp \
    PIDRegler.cpp \
    rpi_sensor.cpp

HEADERS  += visualisierung_grill.h \
    diagramm.h \
    grillposition.h \
    ist_soll_anzeige.h \
    status_anzeige.h \
    grillsteuerung.h \
    Motorsteuerung.h \
    PIDRegler.h \
    Uebergabevariablen.h \
    rpi_sensor.h

FORMS    += visualisierung_grill.ui
