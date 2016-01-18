#include "visualisierung_grill.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visualisierung_Grill w;
    w.show();

    return a.exec();
}
