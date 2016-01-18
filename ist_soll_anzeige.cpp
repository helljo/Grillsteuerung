#include "ist_soll_anzeige.h"

Ist_Soll_Anzeige::Ist_Soll_Anzeige(QWidget *parent) :
    QWidget(parent)
{
    m_sollwert = 0.0;
    m_istwert = 0.0;
    m_soll_string = "kein Sollwert";
    m_ist_string = "kein Istwert";
    m_Titel = "kein Titel";
}

void Ist_Soll_Anzeige::paintEvent(QPaintEvent *)
{
    //Hintergrund zeichnen
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.setPen(QPen(Qt::yellow,3));
    painter.drawRect(0,0,500,220);

    painter.setBrush(Qt::blue);
    painter.setPen(QPen(Qt::yellow,1));

    QFont schriftart;
    schriftart.setPointSize(20);
    painter.setFont(schriftart);
    painter.drawText(50,50,m_Titel);

    schriftart.setPointSize(15);
    painter.setFont(schriftart);
    painter.drawText(50,120,("Sollwert: " + m_soll_string));
    painter.drawText(50,155,("Istwert: " + m_ist_string));
    painter.drawText(50,190,"Abweichung: "+QString::number((m_sollwert-m_istwert)));







}

void Ist_Soll_Anzeige::setSoll(double sollWert)
{
    m_sollwert = sollWert;
    QString m_soll_string = QString::number(m_sollwert);
    this->repaint();
}

void Ist_Soll_Anzeige::setIst(double istWert)
{
    m_istwert = istWert;
    QString m_ist_string = QString::number(m_istwert);
    this->repaint();
}

void Ist_Soll_Anzeige::setTitel(QString Titel)
{
    m_Titel = Titel;
    this->repaint();
}
