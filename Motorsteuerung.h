
#ifndef MOTORSTEUERUNG_H
#define MOTORSTEUERUNG_H

#pragma once

#include "Uebergabevariablen.h"


class Motorsteuerung
{
public:
    Motorsteuerung();
	~Motorsteuerung(void);

	motorzustand steuerung(steuerungsart handauto, motorzustand verfahrwunsch, double automatikposition);
	int motorposition();

private:

	int pin_endschalteraussen;
	int pin_endschalterinnen;
	int pin_motorrausfahren;
	int pin_motorreinfahren;
	int referenz;
	int referenzfahren_schritt;
	int neu_referenzieren_schritt;
	int istposition_absolut;
	int istposition_normiert;
	int istposition_zwischenspeicher;
	motorzustand motor;
	bool referenzfahrt_aktiv;
	bool neu_referenzieren_aktiv;

	motorzustand motorzustand_erkennen();
	void automatikbetrieb(double automatikposition);
	void positiondbestimmung();
    void motoransteuerung();
	void referenzfahren();
	void neu_referenzieren();

};


bool digitalWrite (int pin, bool wert);
bool digitalRead (int pin);

#endif
