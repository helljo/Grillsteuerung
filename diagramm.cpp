#include "diagramm.h"
#include "math.h"


Diagramm::Diagramm(QWidget *parent) :
    QWidget(parent)
{
 for(int j=0; j<1000; j++)
 {
     m_messwerte.push_back(j/10);
 }
    m_zieltemperatur = 65.5;
}


void Diagramm::paintEvent(QPaintEvent *)
{
    // Painter für das Widget erzeugen
    QPainter painter(this);

    //Farben für den Hintergrund auswählen
    painter.setPen(QPen(Qt::yellow, 3)
                   );
    painter.setBrush(Qt::black);
    //HIntergrund Zeichnen
    painter.drawRect(0,0,1000,280);

    //Koordniatensystem anpassen damit Werte vo unten nach oben aufgetragen werden
    painter.scale(1,-1);
    painter.translate(0,-280);

    //Farben für das Diagramm festlegen
    painter.setBrush(Qt::blue);
    painter.setRenderHint(QPainter::Antialiasing);

    //Ursprung des Koordinatensystems festlegen
    QPointF Anfangspunkt;
    Anfangspunkt.setX(50);
    Anfangspunkt.setY(50);

    //skalierung für das Diagramm festlegen
    int skalenabschnitte = int(m_messwerte.size()/900)+1;


    //Messwerte in einen Pfad umwandeln der gezeichnet werden kann
    QPainterPath Tempverlauf(Anfangspunkt);

    for(uint i=0; i<(uint)(m_messwerte.size()/skalenabschnitte);i++)
    {
        //painter.drawLine(j*10+10,Messwerte[j]+10,(j+1)*10+10,Messwerte[j+1]+10);
        Tempverlauf.lineTo((int)(i+50),(temp_zu_hoehe(m_messwerte[i*skalenabschnitte])+50));
    }
    Tempverlauf.lineTo((int)((((m_messwerte.size()/skalenabschnitte))-1)+50),50);

    //Pfad Zeichnen
    painter.drawPath(Tempverlauf);
    //Koordinatenachsen Zeichen
    painter.setPen(Qt::white);
    //x-Achse
    painter.drawLine(50,50,950,50);
    //y-Achse
    painter.drawLine(50,50,50,250);
    //Trennstriche
    painter.setPen(QPen(Qt::gray,1,Qt::DashLine));
    painter.drawLine(50,100,945,100);
    painter.drawLine(50,150,945,150);
    painter.drawLine(50,200,945,200);
    painter.drawLine(50,250,945,250);



    //Skalierung der X-Achse ausrechnen
    m_anzahl_striche = skalenabschnitte;
    painter.setPen(QPen(Qt::white,3));
    for(int k=0; k<=m_anzahl_striche;k++)
    {
       painter.drawLine((900/m_anzahl_striche)*k+50,45,(900/m_anzahl_striche)*k+50,55);

    }

    painter.scale(1,-1);
    painter.translate(0,-280);
    for(int k=0; k<=m_anzahl_striche;k++)
    {
    QString beschriftung = QString::number(15*k);
    QFont schriftart;
    schriftart.setPointSize(12);
    painter.setFont(schriftart);
    painter.drawText((900/m_anzahl_striche)*k+40 ,260,beschriftung);
    }
    painter.drawText(960,235,"min");
    painter.drawText(40,20,"°C");
    painter.drawText(20,35,"100");
    painter.drawText(20,85,"75");
    painter.drawText(20,135,"50");
    painter.drawText(20,185,"25");
    painter.drawText(20,235,"0");
    painter.setPen(Qt::red);
    painter.drawText(15,235-temp_zu_hoehe(m_zieltemperatur),QString::number(m_zieltemperatur));
    painter.drawLine(50,235-temp_zu_hoehe(m_zieltemperatur),945,235-temp_zu_hoehe(m_zieltemperatur));

}

//Die methode übernimmt einen std::vector der die Messwerte bereithält und stellt sie der Klasse zur verfügung
 void Diagramm::set_messwerte(std::vector<double> &input_messwerte)
 {
     m_messwerte = input_messwerte;
 }

 int Diagramm::temp_zu_hoehe(double temperatur)
 {

        int hoehe = (int)(temperatur/0.5);

        return hoehe;

 }

 void Diagramm::set_ziel_temp(double zieltemperatur)
 {
     m_zieltemperatur = zieltemperatur;
 }
