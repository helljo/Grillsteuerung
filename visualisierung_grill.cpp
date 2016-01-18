#include "visualisierung_grill.h"
#include "ui_visualisierung_grill.h"
#include "grillsteuerung.h"

Visualisierung_Grill::Visualisierung_Grill(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visualisierung_Grill)
{
    ui->setupUi(this);
    ui->Kerntemperatur->setTitel("Kerntemperatur");
    ui->Aussentemperatur->setTitel("Außentemperatur");


}

Visualisierung_Grill::~Visualisierung_Grill()
{
    delete ui;
}

void Visualisierung_Grill::Datenaustausch()
{
    grillsteuerung->Datenaustausch_hmi_steuerung(werte_HMI);
    grillsteuerung->Datenaustausch_steuerung_hmi(werte_HMI);
}


void Visualisierung_Grill::on_Button_Start_clicked()
{
    grillsteuerung = new Grillsteuerung;
    connect(grillsteuerung, SIGNAL(steuerzyklus_ende()), this, SLOT(Datenaustausch()));
}


