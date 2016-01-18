#ifndef STATUS_ANZEIGE_H
#define STATUS_ANZEIGE_H

#include <QWidget>
#include <QPainter>
#include <QString>

enum Status{BETRIEBSBEREIT, BETRIEB_HAND, BETRIEB_AUTO, FERTIG, REFERENZFAHRT};

class Status_Anzeige : public QWidget
{
    Q_OBJECT
public:
    explicit Status_Anzeige(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
private:
    void status_betriebsbereit();
    void status_auto();
    void status_hand();
    void status_referenzfahrt();
    void status_fertig();

    QBrush m_hintergrund;
    QPen m_textfarbe;
    QString m_ausgabetext;
    QFont m_schriftart;
    QPoint m_ursprung_text;
    QRect m_textfeld;

signals:

public slots:
    void set_Status(Status Status);

};

#endif // STATUS_ANZEIGE_H
