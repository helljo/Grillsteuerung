#include "grillsteuerung.h"


Grillsteuerung::Grillsteuerung(QObject *parent) :
    QObject(parent)
{
    error = 0;
    i  = 0;
    Sensor_innentemp = new RPI_Sensor(ONEWIRE,"10-000801b5a7a6");
    QTimer* Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(regler()));
    Timer->start(100);
}

void Grillsteuerung::regler()
{
    double regelgroesse = 0.0;

    if (i == 10)
    {
    try
        {
            werte_steuerung.isttemperatur_Innen = (Sensor_innentemp->read_Sensor()/1000.0);
            werte_steuerung.isttemperatur_Aussen = (Sensor_innentemp->read_Sensor()/1000.0);
            //double innentemperatur =
            //uebergabe.isttemperatur_Aussen = normierung(innentemperatur, uebergabe.mintemp_aussen, uebergabe.maxtemp_aussen);
            regelgroesse = PID(werte_steuerung.solltemperatur_Aussen, werte_steuerung.isttemperatur_Aussen);
            i = 0;
            werte_steuerung.garpunkt = garpunktbestimmung();
        }
        catch(int error)
        {
            werte_steuerung.error = error;
        }
    }
    else
    {
        i++;
    }

    werte_steuerung.motor = steuerung(werte_steuerung.betriebsart, werte_steuerung.motoransteuerung, int(regelgroesse));
    werte_steuerung.spiessposition = motorposition();

    emit steuerzyklus_ende();
}

int Grillsteuerung::getError()
{
    return error;
}

int Grillsteuerung::garpunktbestimmung()
{
	//Bestimmung der Garpunktes aus der aktuellen und der gewünschten Innentemperatur
    double garpunkt = werte_steuerung.solltemperatur_Innen / (werte_steuerung.isttemperatur_Innen - 20.0) * 100.0;
	wertebegrenzung(garpunkt);
	return int(garpunkt);
}

void Grillsteuerung::Datenaustausch_hmi_steuerung(werteuebergabe &daten_von_hmi)
{
    werte_steuerung.solltemperatur_Aussen = daten_von_hmi.solltemperatur_Aussen;
    werte_steuerung.solltemperatur_Aussen = daten_von_hmi.solltemperatur_Innen;
    werte_steuerung.motoransteuerung = daten_von_hmi.motoransteuerung;
    werte_steuerung.betriebsart = daten_von_hmi.betriebsart;
    werte_steuerung.pAnteil = daten_von_hmi.pAnteil;
    werte_steuerung.iAnteil = daten_von_hmi.iAnteil;
    werte_steuerung.dAnteil = daten_von_hmi.dAnteil;
    werte_steuerung.mintemp_aussen = daten_von_hmi.mintemp_aussen;
    werte_steuerung.maxtemp_aussen = daten_von_hmi.maxtemp_aussen;
    werte_steuerung.mintemp_innen = daten_von_hmi.mintemp_innen;
    werte_steuerung.maxtemp_innen = daten_von_hmi.maxtemp_innen;
}

void Grillsteuerung::Datenaustausch_steuerung_hmi(werteuebergabe &daten_von_steuerung)
{
    daten_von_steuerung.isttemperatur_Aussen = werte_steuerung.isttemperatur_Aussen;
    daten_von_steuerung.isttemperatur_Innen = werte_steuerung.isttemperatur_Innen;
    daten_von_steuerung.motor = werte_steuerung.motor;
    daten_von_steuerung.error = werte_steuerung.error;
    daten_von_steuerung.spiessposition = werte_steuerung.error;
    daten_von_steuerung.garpunkt = werte_steuerung.garpunkt;
}
