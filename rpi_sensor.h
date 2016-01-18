//bei verwendung dieser KLasse muss die Konfigurationsdatei um "CONFIG += console" ergänzt werden

#ifndef RPI_SENSOR_H
#define RPI_SENSOR_H

#include <QObject>
#include <QString>
#include <QFile>

enum BUS {I2C ,ONEWIRE};

class RPI_Sensor : public QObject
{
    Q_OBJECT
public:
    explicit RPI_Sensor(BUS bus,QString adresse, QObject *parent = 0);

private:
    int read_I2C();
    int read_ONEWIRE();
    BUS m_verwendeter_bus;
    QString m_sensor_adresse;

signals:

public slots:
    int read_Sensor();
};

#endif // RPI_SENSOR_H
