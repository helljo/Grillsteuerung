#ifndef GRILLPOSITION_H
#define GRILLPOSITION_H

#include <QWidget>
#include <QPainter>
#include <Qt>

class Grillposition : public QWidget
{
    Q_OBJECT
public:
    explicit Grillposition(QWidget *parent = 0);

private:
    virtual void paintEvent(QPaintEvent *);
    int m_temperatur;
    int m_position;

signals:

public slots:
    void setPosition(int position);
    void setTemp(int temperatur);

};

#endif // GRILLPOSITION_H
