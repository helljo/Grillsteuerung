#include "Motorsteuerung.h"


Motorsteuerung::Motorsteuerung()://Innitialisierungsliste
    referenz(100),
	referenzfahren_schritt(1),
	neu_referenzieren_schritt(1),
	istposition_absolut(0),
	istposition_normiert(0),
	istposition_zwischenspeicher(0),
	motor(stopp),
    referenzfahrt_aktiv(true),
    neu_referenzieren_aktiv(false)
{
    pin_endschalteraussen = 1;
    pin_endschalterinnen = 2;
    pin_motorrausfahren = 3;
    pin_motorreinfahren = 4;
}


Motorsteuerung::~Motorsteuerung(void)
{
}


motorzustand Motorsteuerung::steuerung(steuerungsart handauto, motorzustand verfahrwunsch, double automatikposition)
{
	if (referenzfahrt_aktiv == true)
	{
		//wenn Referenzfahrt aktiv ist, wird nur diese ausgeführt
		Motorsteuerung::referenzfahren();
	}

	else if (neu_referenzieren_aktiv == true)
	{
		//während des neu referenzierens wird ausschließlich diese Funktion ausgeführt
		Motorsteuerung::neu_referenzieren();
	}

	else
	{
		//Auswertung der Betriebsart
		switch (handauto)
		{
		case handbetrieb:
			{
				//in der Betriebsart Handbetrieb wird der Verfahrwunsch direkt an die Motoransteuerung übergeben
				motor = verfahrwunsch;
				break;
			}
		case automatik:
			{
				//Im Automatikbetrieb wird die gewünschte Position des Linearantriebs an die Lageregelung übergeben
				automatikbetrieb(automatikposition);
				break;
			}
		case referenzfahrt:
			{
				//wird eine Referenzfahrt ausgelöst, wird diese aktiviert und ab dem nästen Programmdurchlauf ausgeführt
				referenzfahrt_aktiv = true;
				break;
			}
		case referenzieren:
			{
				//wird ein neu Referenzieren ausgelöst, wird diese aktiviert und ab dem nächsten Programmdurchlauf ausgeführt
                neu_referenzieren_aktiv = true;
				break;
			}
		default:
			{
				//wird keine gültige Betriebsart übergeben, wird der Motor gestoppt
				motor = stopp;
				break;
			}
		}		
	}

	//Aufruf der Motoransteuerung mit dem zuvor bestimmten Verfahrbefehl
    Motorsteuerung::motoransteuerung();

	//zyklische Bestimmung der aktuellen Position
	Motorsteuerung::positiondbestimmung();

    return motor;
}

void Motorsteuerung::referenzfahren()
{
	//Schrittkette zur Steuerung der Referenzfahrt
	switch (referenzfahren_schritt)
	{
	case 1:
		{
			motor = rausfahren;
			referenzfahren_schritt++;
			break;
		}
		
	case 2:
		{
			//warten auf Endschalter außen
			if(digitalRead (pin_endschalteraussen) == false)
			{
				break;
			}
			istposition_absolut = 0;
			motor = reinfahren;
			referenzfahren_schritt++;
			break;
		}
		
	case 3:
		{
			//warten auf Endschalter innen
			if(digitalRead (pin_endschalterinnen) == false)
			{
				break;
			}
			motor = rausfahren;
			referenz = istposition_absolut;
			referenzfahren_schritt++;
			break;
		}
	
	case 4:
		{
			//warten auf Endschalter außen
			if(digitalRead (pin_endschalteraussen) == false)
			{
				break;
			}
			istposition_absolut = 0;
			motor = stopp;
			referenzfahrt_aktiv = false;
			break;
		}
	}
}

void Motorsteuerung::neu_referenzieren()
{
	switch (neu_referenzieren_schritt)
	{
	case 1:
		{
			istposition_zwischenspeicher = 0;
			motor = rausfahren;
			neu_referenzieren_schritt++;
			break;
		}
	case 2:
		{
			if(digitalRead (pin_endschalteraussen) == false)
			{
				istposition_zwischenspeicher++;
				break;
			}
			istposition_absolut = 0;
			motor = reinfahren;
			neu_referenzieren_schritt++;
			break;
		}
	case 3:
		{
			if(istposition_zwischenspeicher != 0)
			{
				istposition_zwischenspeicher--;
				break;
			}
			motor = stopp;
			neu_referenzieren_aktiv = false;
			neu_referenzieren_schritt = 1;
		}
	}
}

void Motorsteuerung::automatikbetrieb(double automatikposition)
{

	int positionsdifferenz = automatikposition - istposition_normiert;

	if (positionsdifferenz >= 3)
	{
		motor = reinfahren;
	}
	else if (positionsdifferenz <=-3)
	{
		motor = rausfahren;
	}
	else
	{
		motor = stopp;
	}
}

void Motorsteuerung::motoransteuerung()
{
	switch (motor)
	{
	case reinfahren:
		{
			if (digitalRead (pin_endschalterinnen) == false)
			{
				digitalWrite (pin_motorrausfahren, false);
				digitalWrite (pin_motorreinfahren, true);
			}
			else
			{
				digitalWrite (pin_motorrausfahren, false);
				digitalWrite (pin_motorreinfahren, false);
			}
			break;
		}

	case rausfahren:
		{
			if (digitalRead (pin_endschalteraussen) == false)
			{
				digitalWrite (pin_motorrausfahren, true);
				digitalWrite (pin_motorreinfahren, false);
			}
			else
			{
				digitalWrite (pin_motorrausfahren, false);
				digitalWrite (pin_motorreinfahren, false);
			}
			break;
		}

	case stopp:
		{
			digitalWrite (pin_motorrausfahren, false);
			digitalWrite (pin_motorreinfahren, false);
			break;
		}
	}
}

void Motorsteuerung::positiondbestimmung()
{
	if (digitalRead (pin_motorrausfahren) == true)
	{
		istposition_absolut++;
	}
	
	if (digitalRead (pin_motorreinfahren) == true)
	{
		istposition_absolut--;
	}

	istposition_normiert = (istposition_absolut * 100) / referenz;

	if (referenzfahrt_aktiv == false)
	{
        if (istposition_normiert > 100)
		{
			istposition_normiert = 100;
			neu_referenzieren_aktiv = true;
		}
        if (istposition_normiert < 0)
		{
			istposition_normiert = 0;
			neu_referenzieren_aktiv = true;
		}
	}
}

int Motorsteuerung::motorposition()
{
	return int(istposition_normiert);
}





bool digitalWrite (int pin, bool wert)
{
    return true;
}
bool digitalRead (int pin)
{
    return false;
}
