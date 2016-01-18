#ifndef PIDREGLER_H
#define PIDREGLER_H

#pragma once
class PIDRegler
{
public:
	PIDRegler(void);
    int PIDsetParAdd(double pVerstaerkung, double iVerstaerkung = 0.0, double dVerstaerkung = 0.0);
	double PID(double soll, double ist);
	double normierung(double eingabe, double min, double max);
	double skalierung(double eingabe, double min, double max);
    void wertebegrenzung(double &wert) const;



private:

	double proportionalverstaerkung;
	double integralverstaerkung;
	double differentialverstaerkung;
	double regeldifferenzAlt;
	double integral;
	double zeitbasis;


	double pRegler(double regeldifferenz);
	double iRegler(double regeldifferenz);
	double dRegler(double regeldifferenz);
	double differenz(double soll, double ist);
    bool isEqual(double min, double max,double genauigkeit);

};

#endif
