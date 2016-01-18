/********************************************************************************
** Form generated from reading UI file 'visualisierung_grill.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALISIERUNG_GRILL_H
#define UI_VISUALISIERUNG_GRILL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "diagramm.h"
#include "grillposition.h"
#include "ist_soll_anzeige.h"
#include "status_anzeige.h"

QT_BEGIN_NAMESPACE

class Ui_Visualisierung_Grill
{
public:
    QWidget *centralWidget;
    Grillposition *Spiessposition;
    Diagramm *Temp_Verlauf;
    Ist_Soll_Anzeige *Kerntemperatur;
    Ist_Soll_Anzeige *Aussentemperatur;
    QPushButton *Button_Start;
    QPushButton *Button_Einstellungen;
    QGroupBox *groupBox;
    QPushButton *Button_Hand;
    QPushButton *Button_Automatik;
    QGroupBox *groupBox_3;
    QPushButton *Button_fahren_hin;
    QPushButton *Button_fahren_weg;
    QGroupBox *groupBox_2;
    QPushButton *Button_Rind;
    QPushButton *Button_Schwein;
    Status_Anzeige *widget;

    void setupUi(QMainWindow *Visualisierung_Grill)
    {
        if (Visualisierung_Grill->objectName().isEmpty())
            Visualisierung_Grill->setObjectName(QStringLiteral("Visualisierung_Grill"));
        Visualisierung_Grill->resize(1280, 720);
        Visualisierung_Grill->setStyleSheet(QStringLiteral("background-color:  black;"));
        centralWidget = new QWidget(Visualisierung_Grill);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(1280, 720));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral(""));
        Spiessposition = new Grillposition(centralWidget);
        Spiessposition->setObjectName(QStringLiteral("Spiessposition"));
        Spiessposition->setGeometry(QRect(280, 0, 500, 440));
        Spiessposition->setMinimumSize(QSize(500, 440));
        Temp_Verlauf = new Diagramm(centralWidget);
        Temp_Verlauf->setObjectName(QStringLiteral("Temp_Verlauf"));
        Temp_Verlauf->setGeometry(QRect(280, 440, 1000, 280));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Temp_Verlauf->sizePolicy().hasHeightForWidth());
        Temp_Verlauf->setSizePolicy(sizePolicy1);
        Temp_Verlauf->setMinimumSize(QSize(1000, 280));
        Kerntemperatur = new Ist_Soll_Anzeige(centralWidget);
        Kerntemperatur->setObjectName(QStringLiteral("Kerntemperatur"));
        Kerntemperatur->setGeometry(QRect(780, 220, 500, 220));
        Kerntemperatur->setMinimumSize(QSize(500, 220));
        Aussentemperatur = new Ist_Soll_Anzeige(centralWidget);
        Aussentemperatur->setObjectName(QStringLiteral("Aussentemperatur"));
        Aussentemperatur->setGeometry(QRect(780, 0, 500, 220));
        Aussentemperatur->setMinimumSize(QSize(500, 220));
        Button_Start = new QPushButton(centralWidget);
        Button_Start->setObjectName(QStringLiteral("Button_Start"));
        Button_Start->setGeometry(QRect(40, 10, 200, 40));
        QFont font;
        font.setPointSize(15);
        Button_Start->setFont(font);
        Button_Start->setStyleSheet(QStringLiteral("background-color: white;"));
        Button_Einstellungen = new QPushButton(centralWidget);
        Button_Einstellungen->setObjectName(QStringLiteral("Button_Einstellungen"));
        Button_Einstellungen->setGeometry(QRect(40, 660, 200, 40));
        Button_Einstellungen->setFont(font);
        Button_Einstellungen->setStyleSheet(QStringLiteral("background-color: white;"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(15, 60, 250, 115));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox->setPalette(palette);
        groupBox->setFont(font);
        Button_Hand = new QPushButton(groupBox);
        Button_Hand->setObjectName(QStringLiteral("Button_Hand"));
        Button_Hand->setGeometry(QRect(25, 25, 200, 40));
        Button_Hand->setFont(font);
        Button_Hand->setStyleSheet(QStringLiteral("background-color: white;"));
        Button_Automatik = new QPushButton(groupBox);
        Button_Automatik->setObjectName(QStringLiteral("Button_Automatik"));
        Button_Automatik->setGeometry(QRect(25, 65, 200, 40));
        Button_Automatik->setFont(font);
        Button_Automatik->setStyleSheet(QStringLiteral("background-color: white;"));
        Button_Automatik->raise();
        Button_Hand->raise();
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(15, 300, 250, 115));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox_3->setPalette(palette1);
        groupBox_3->setFont(font);
        Button_fahren_hin = new QPushButton(groupBox_3);
        Button_fahren_hin->setObjectName(QStringLiteral("Button_fahren_hin"));
        Button_fahren_hin->setGeometry(QRect(25, 25, 200, 40));
        Button_fahren_hin->setFont(font);
        Button_fahren_hin->setStyleSheet(QStringLiteral("background-color: white;"));
        Button_fahren_weg = new QPushButton(groupBox_3);
        Button_fahren_weg->setObjectName(QStringLiteral("Button_fahren_weg"));
        Button_fahren_weg->setGeometry(QRect(25, 65, 200, 40));
        Button_fahren_weg->setFont(font);
        Button_fahren_weg->setStyleSheet(QStringLiteral("background-color: white;"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(15, 180, 250, 115));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox_2->setPalette(palette2);
        groupBox_2->setFont(font);
        Button_Rind = new QPushButton(groupBox_2);
        Button_Rind->setObjectName(QStringLiteral("Button_Rind"));
        Button_Rind->setGeometry(QRect(25, 25, 200, 40));
        Button_Rind->setFont(font);
        Button_Rind->setStyleSheet(QStringLiteral("background-color: white;"));
        Button_Schwein = new QPushButton(groupBox_2);
        Button_Schwein->setObjectName(QStringLiteral("Button_Schwein"));
        Button_Schwein->setGeometry(QRect(25, 65, 200, 40));
        Button_Schwein->setFont(font);
        Button_Schwein->setStyleSheet(QStringLiteral("background-color: white;"));
        widget = new Status_Anzeige(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 439, 200, 200));
        Visualisierung_Grill->setCentralWidget(centralWidget);
        Temp_Verlauf->raise();
        Aussentemperatur->raise();
        Button_Start->raise();
        Button_Einstellungen->raise();
        groupBox->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        widget->raise();
        Spiessposition->raise();
        Kerntemperatur->raise();

        retranslateUi(Visualisierung_Grill);

        QMetaObject::connectSlotsByName(Visualisierung_Grill);
    } // setupUi

    void retranslateUi(QMainWindow *Visualisierung_Grill)
    {
        Visualisierung_Grill->setWindowTitle(QApplication::translate("Visualisierung_Grill", "Visualisierung_Grill", 0));
        Button_Start->setText(QApplication::translate("Visualisierung_Grill", "Start", 0));
        Button_Einstellungen->setText(QApplication::translate("Visualisierung_Grill", "Einstellungen", 0));
        groupBox->setTitle(QApplication::translate("Visualisierung_Grill", "Betriebsart", 0));
        Button_Hand->setText(QApplication::translate("Visualisierung_Grill", "Hand", 0));
        Button_Automatik->setText(QApplication::translate("Visualisierung_Grill", "Automatik", 0));
        groupBox_3->setTitle(QApplication::translate("Visualisierung_Grill", "Handbetrieb", 0));
        Button_fahren_hin->setText(QApplication::translate("Visualisierung_Grill", "Fahren Hin", 0));
        Button_fahren_weg->setText(QApplication::translate("Visualisierung_Grill", "Fahren Weg", 0));
        groupBox_2->setTitle(QApplication::translate("Visualisierung_Grill", "Temperaturvorwahl", 0));
        Button_Rind->setText(QApplication::translate("Visualisierung_Grill", "Rind", 0));
        Button_Schwein->setText(QApplication::translate("Visualisierung_Grill", "Schwein", 0));
    } // retranslateUi

};

namespace Ui {
    class Visualisierung_Grill: public Ui_Visualisierung_Grill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALISIERUNG_GRILL_H
