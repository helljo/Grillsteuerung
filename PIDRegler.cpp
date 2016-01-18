#include "PIDRegler.h"
#include <algorithm>

PIDRegler::PIDRegler(void) : //Innitialisierungsliste
	proportionalverstaerkung(0.0), 
	integralverstaerkung(0.0),
	differentialverstaerkung(0.0),
	regeldifferenzAlt(0.0),
	integral(0.0),
	zeitbasis(0.0)
{
}

double PIDRegler::normierung(double eingabe, double min, double max)
{
	//Kontrolle auf Plausibilität der Eingabewerte
	//Methode wird mit Fehlercode beendet, wenn min gleich max ist (div/0)
    if(isEqual(min, max, 0.0001))
	{
		throw -103;
		//throw "Min / Max gleich";
	}

	//Normierung der Eingabe auf 0 - 100%
	double ausgabe = (eingabe - min) / (max - min) * 100.0;

	return ausgabe;
}

/*
void f()
{
	g();
}

int g()
{
	try
	{
		double ausgabe = skalierung(1.0, 2.0, 3.0);
		ausgabe = skalierung(1.0, 2.0, 3.0);
		ausgabe = skalierung(1.0, 2.0, 2.0);
		ausgabe = skalierung(1.0, 2.0, 3.0);
		ausgabe = skalierung(1.0, 2.0, 3.0);
	} catch(int errorno)
	//	catch(const char* errormsg) {
	//		cout << errormsg; 
	//}

	{
		cout << "Fehlerbehandlung" << errorno << endl;
	}
}
*/


double PIDRegler::skalierung(double eingabe, double min, double max)
{
	//Kontrolle auf Plausibilität der Eingabewerte
	//Methode wird mit Fehlercode beendet, wenn min gleich max ist (Ergebnis gleich Null)
    if(isEqual(min, max, 0.0001))
	{
		throw -102;
		//throw "Min / Max gleich";
	}

	//Skalierung der Eingabe auf Wertebereich
	double ausgabe = eingabe / 100.0 * (max - min) + min;

	//Rückgabe für feherfreie Bearbeitung
	return ausgabe;
}

double PIDRegler::differenz(double soll, double ist)
{
	//Berechnung der Regeldifferenz
	double differenz = soll - ist;

	//Rückgabe für feherfreie Bearbeitung
	return differenz;
}

double PIDRegler::pRegler(double regeldifferenz)
{
	//Berechnung des Proportionalanteils
	double pAnteil = proportionalverstaerkung * regeldifferenz;

	//Proportionalanteil auf 0 - 100% begrenzen
	wertebegrenzung(pAnteil);

	return pAnteil;
}

double PIDRegler::iRegler(double regeldifferenz)
{
	//nummerische Integration der Regeldifferenz
	integral = integral + regeldifferenz;
	
	//Berechnung des Integralanteils
	double iAnteil = integralverstaerkung * integral;

	//Integralanteil auf 0 - 100% begrenzen
	wertebegrenzung(iAnteil);

	return iAnteil;
}

double PIDRegler::dRegler(double regeldifferenz)
{
	//nummerische Differentiation der Regeldifferenz
	double differenzial = regeldifferenz - regeldifferenzAlt;
	regeldifferenzAlt = regeldifferenz;
	
	//Berechnung des Differentialanteils
	double dAnteil = integralverstaerkung * differenzial;

	//Differentialanteil auf 0 - 100% begrenzen
	wertebegrenzung(dAnteil);

	return dAnteil;
}

void PIDRegler::wertebegrenzung(double &wert) const
{
	//Wert wird nach oben auf 100.0 begrenzt
	if(wert > 100.0)
		wert = 100.0;

	//Wert wird nach unten auf 0.0 begrenzt
	else if(wert < 0.0)
		wert = 0.0;
}

#define ASSERT(functioncall) if ((error = functioncall) != 0) { return error; }

double PIDRegler::PID(double soll, double ist)
{

	//Kontrolle auf Plausibilität der Eingabewerte
	//Methode wird mit Fehlercode beendet, wenn Eingabe außerhalb des definierten Wertebereiches liegt
	if(soll < 0.0 || soll > 100.0 || ist < 0.0 || ist > 100.0)
	{
		throw -201;
	}
	
	//Regeldifferenz bilden
	double regeldifferenz = differenz(soll, ist);
	
	//Proportionalanteil bilden
	double pAnteil = pRegler(regeldifferenz);

	//Integralanteil bilden
	double iAnteil = iRegler(regeldifferenz);

	//Differentialanteil bilden
	double dAnteil = dRegler(regeldifferenz);

	//Regleranteile werden addiert
	double regelgroesse = pAnteil + iAnteil + dAnteil;

	//Regelgröße auf 0 - 100% begrenzen
	wertebegrenzung(regelgroesse);

	return regelgroesse;
}

int PIDRegler::PIDsetParAdd(double pVerstaerkung, double iVerstaerkung, double dVerstaerkung)
{
	proportionalverstaerkung = pVerstaerkung;
	integralverstaerkung = iVerstaerkung;
	differentialverstaerkung = dVerstaerkung;

	return 0;
}

bool PIDRegler::isEqual(double min, double max,double genauigkeit)
{
    double diff = max-min;
    if (diff<0)
    diff = diff * -1;

    if (diff < genauigkeit)
    {
        return true;
    }else
    {
        return false;
    }


}
