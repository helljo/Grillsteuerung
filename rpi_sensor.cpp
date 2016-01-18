#include "rpi_sensor.h"

RPI_Sensor::RPI_Sensor(BUS bus,QString adresse,QObject *parent) :
    QObject(parent)
{
    m_verwendeter_bus = bus;
    m_sensor_adresse = adresse;
}

int RPI_Sensor::read_Sensor()
{
    int messwert = 0;
    switch (m_verwendeter_bus)
    {
    case I2C:
        messwert = read_I2C(); break;
    case ONEWIRE:
        messwert = read_ONEWIRE(); break;
    }
    return messwert;
}

int RPI_Sensor::read_I2C()
{
    return 0;
}

int RPI_Sensor::read_ONEWIRE()
{
    QString Adress_string = "E:\\sys\\bus\\devices\\";
    Adress_string += m_sensor_adresse;
    Adress_string += "\\w1_slave.txt";
    QFile Text(Adress_string);
    Text.open(QIODevice::ReadOnly|QIODevice::Text);
    QString text_string = (QString)Text.readAll();
    int pos_temp = text_string.lastIndexOf("t=")+2;
    text_string = text_string.mid(pos_temp,5);
    return text_string.toInt();
}
