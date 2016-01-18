#ifndef GRILLSTEUERUNG_H
#define GRILLSTEUERUNG_H

//#include "grillsteuerung_global.h"
#include "Uebergabevariablen.h"
#include "PIDRegler.h"
#include "Motorsteuerung.h"
#include <QT>
#include <QObject>
#include <QTimer>
#include "rpi_sensor.h"

class Grillsteuerung: public QObject, public Motorsteuerung, PIDRegler
{
    Q_OBJECT
public:
    explicit Grillsteuerung(QObject *parent = 0);
    int getError();
    void Datenaustausch_hmi_steuerung(werteuebergabe &daten_von_hmi);
    void Datenaustausch_steuerung_hmi(werteuebergabe &daten_von_steuerung);

public slots:
    void regler();


private:
    RPI_Sensor* Sensor_innentemp;
    werteuebergabe werte_steuerung;
    int error;
    int i;
	
	int garpunktbestimmung();

signals:
    void steuerzyklus_ende();
};

#endif // GRILLSTEUERUNG_H
