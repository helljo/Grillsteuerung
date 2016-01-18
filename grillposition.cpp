#include "grillposition.h"

Grillposition::Grillposition(QWidget *parent) :
    QWidget(parent)
{
    m_position = 500;
    m_temperatur = 25;
}


void Grillposition::paintEvent(QPaintEvent *)
{

    //Grundgerüst Zeichnen
    QPainter painter(this);
    painter.scale(0.5,0.44);
    painter.setBrush(Qt::black);
    painter.setPen(QPen(Qt::yellow,3));
    painter.drawRect(0,0,1000,1000);
    painter.setBrush(Qt::red);
    painter.setPen(QPen(Qt::gray,10));
    painter.drawRect(150,150,700,200);
    painter.setBrush(Qt::gray);
    painter.drawRect(150,350,50,500);
    painter.drawRect(800,350,50,500);

    //Bewegliche Rechtecke Anlegen
    QRect spiess;
    spiess.setBottomLeft(QPoint(175,m_position+5));
    spiess.setTopRight(QPoint(825,m_position-5));

    QRect braten;
    braten.setBottomLeft(QPoint(225,m_position+50));
    braten.setTopRight(QPoint(775,m_position-50));

    //Bewegliche Rechtecke Zeichnen
    painter.setBrush(Qt::darkGray);
    painter.setPen(QPen(Qt::black,1));
    painter.drawRect(spiess);

    painter.setPen(QColor(210,105,30));
    painter.setBrush(QColor(210,105,30));
    painter.drawRect(braten);

}

void Grillposition::setPosition(int position)
{
    m_position = position*4+450;
    this->repaint();
}
void Grillposition::setTemp(int temperatur)
{
    m_temperatur = temperatur;
    this->repaint();
}
