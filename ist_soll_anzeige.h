#ifndef IST_SOLL_ANZEIGE_H
#define IST_SOLL_ANZEIGE_H

#include <QWidget>
#include <Qt>
#include <QPainter>

class Ist_Soll_Anzeige : public QWidget
{
    Q_OBJECT
public:
    explicit Ist_Soll_Anzeige(QWidget *parent = 0);
    void setSoll(double sollWert);
    void setIst(double istWert);
    void setTitel(QString Titel);

private:
    void paintEvent(QPaintEvent *);
    double m_sollwert;
    double m_istwert;
    QString m_soll_string;
    QString m_ist_string;
    QString m_Titel;

signals:

public slots:

};

#endif // IST_SOLL_ANZEIGE_H
