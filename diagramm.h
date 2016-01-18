#ifndef DIAGRAMM_H
#define DIAGRAMM_H

#include <QWidget>
#include <qsize.h>
#include <QPainter>
#include <Qt>

class Diagramm : public QWidget
{
    Q_OBJECT
public:
    explicit Diagramm(QWidget *parent = 0);
    void set_ziel_temp(double zieltemperatur);

private:
    virtual void paintEvent(QPaintEvent *);
    int temp_zu_hoehe(double temperatur);
    std::vector<double> m_messwerte;
    QSize size;
    int m_anzahl_striche;
    double m_schrittweite;
    double m_zieltemperatur;

signals:

public slots:

    void set_messwerte(std::vector<double> &messwerte);

    //show_max
    //show_min
};

#endif // DIAGRAMM_H
