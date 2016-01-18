#ifndef UEBERGABEVARIABLEN_H
#define UEBERGABEVARIABLEN_H

//Variablendefinitionen
enum motorzustand {rausfahren, reinfahren, stopp};
enum steuerungsart {automatik, handbetrieb, referenzfahrt, referenzieren};

#define HIGH true;
#define LOW false;

//Übergabestruktur

struct werteuebergabe
{
double solltemperatur_Aussen;			//in °C
double isttemperatur_Aussen;			//in °C
double solltemperatur_Innen;			//in °C
double isttemperatur_Innen;				//in °C
motorzustand motoransteuerung;			//Ansteuerung im Handbetrieb
motorzustand motor;                     //Rückmeldung der Motorsteuerung
steuerungsart betriebsart;              //Betriebsart Hand/Auto + Auslösen einer Referenzfahrt
int error;                          	//Rückmeldung über Notwendigkeit einer Referenzfahrt
int spiessposition;						//aktuelle Position des Spießes (0-100)
int garpunkt;							//relative Innentemperatur (1-100)
double pAnteil;							//Reglerparameter für Gartemperaturregelung
double iAnteil;
double dAnteil;
double mintemp_aussen;                  //Normierungsgrenzen für gemessene Temperaturen
double maxtemp_aussen;
double mintemp_innen;
double maxtemp_innen;
};

#endif
