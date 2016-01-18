#include "status_anzeige.h"

Status_Anzeige::Status_Anzeige(QWidget *parent) :
    QWidget(parent)
{
    set_Status(BETRIEBSBEREIT);
    m_textfeld.setBottomLeft(QPoint(5,125));
    m_textfeld.setTopRight(QPoint(195,75));
    m_ursprung_text.setX(10);
    m_ursprung_text.setY(100);
}
void Status_Anzeige::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::yellow);
    painter.setFont(m_schriftart);
    painter.setBrush(m_hintergrund);
    painter.drawRect(0,0,200,200);
    painter.setPen(m_textfarbe);
    painter.drawText(m_textfeld,m_ausgabetext,Qt::AlignCenter|Qt::AlignHCenter);

}

void Status_Anzeige::set_Status(Status Status)
{
    switch (Status) {
    case BETRIEBSBEREIT: status_betriebsbereit();   break;
    case BETRIEB_AUTO:   status_auto();             break;
    case BETRIEB_HAND:   status_hand();             break;
    case REFERENZFAHRT:  status_referenzfahrt();    break;
    case FERTIG:         status_fertig();           break;
    default:                                        break;
    }
}

void Status_Anzeige::status_betriebsbereit()
{
    m_hintergrund = Qt::green;
    m_textfarbe.setColor(Qt::black);
    m_ausgabetext = "Betriebsbereit";
    m_schriftart.setPointSize(20);
}

void Status_Anzeige::status_auto()
{
    m_hintergrund = Qt::yellow;
    m_textfarbe.setColor(Qt::black);
    m_ausgabetext = "Automatik";
    m_schriftart.setPointSize(25);
}

void Status_Anzeige::status_hand()
{
    m_hintergrund = Qt::yellow;
    m_textfarbe.setColor(Qt::black);
    m_ausgabetext = "Handbetrieb";
    m_schriftart.setPointSize(25);
}

void Status_Anzeige::status_referenzfahrt()
{
    m_hintergrund = Qt::red;
    m_textfarbe.setColor(Qt::black);
    m_ausgabetext = "Referenzfahrt";
    m_schriftart.setPointSize(20);
}

void Status_Anzeige::status_fertig()
{
    m_hintergrund = Qt::green;
    m_textfarbe.setColor(Qt::black);
    m_ausgabetext = "Fertig!";
    m_schriftart.setPointSize(30);
}
