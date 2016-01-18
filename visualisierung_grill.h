#ifndef VISUALISIERUNG_GRILL_H
#define VISUALISIERUNG_GRILL_H

#include <QMainWindow>
#include "Uebergabevariablen.h"
#include "grillsteuerung.h"

namespace Ui {
class Visualisierung_Grill;
}

class Visualisierung_Grill : public QMainWindow
{
    Q_OBJECT

public:
    explicit Visualisierung_Grill(QWidget *parent = 0);
    ~Visualisierung_Grill();

public slots:




private slots:
    void on_Button_Start_clicked();
    void Datenaustausch();

private:
    Ui::Visualisierung_Grill *ui;
    werteuebergabe werte_HMI;
    Grillsteuerung* grillsteuerung;
};

#endif // VISUALISIERUNG_GRILL_H
