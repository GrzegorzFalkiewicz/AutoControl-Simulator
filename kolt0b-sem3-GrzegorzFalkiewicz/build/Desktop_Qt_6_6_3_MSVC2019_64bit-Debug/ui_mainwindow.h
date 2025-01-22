/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QFrame *line;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tabelaZawodnikow;
    QFrame *line_2;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *dodajZawodnikaButton;
    QPushButton *wyswietlPodiumButton;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1028, 705);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        label->setScaledContents(true);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        tabelaZawodnikow = new QTableWidget(centralwidget);
        if (tabelaZawodnikow->columnCount() < 3)
            tabelaZawodnikow->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabelaZawodnikow->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabelaZawodnikow->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabelaZawodnikow->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tabelaZawodnikow->setObjectName("tabelaZawodnikow");
        tabelaZawodnikow->setLayoutDirection(Qt::LeftToRight);
        tabelaZawodnikow->setAutoFillBackground(false);
        tabelaZawodnikow->setSortingEnabled(true);
        tabelaZawodnikow->horizontalHeader()->setVisible(true);
        tabelaZawodnikow->horizontalHeader()->setCascadingSectionResizes(false);
        tabelaZawodnikow->horizontalHeader()->setDefaultSectionSize(200);
        tabelaZawodnikow->horizontalHeader()->setHighlightSections(true);
        tabelaZawodnikow->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tabelaZawodnikow->horizontalHeader()->setStretchLastSection(true);
        tabelaZawodnikow->verticalHeader()->setVisible(true);
        tabelaZawodnikow->verticalHeader()->setCascadingSectionResizes(true);
        tabelaZawodnikow->verticalHeader()->setHighlightSections(true);
        tabelaZawodnikow->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabelaZawodnikow->verticalHeader()->setStretchLastSection(false);

        verticalLayout_5->addWidget(tabelaZawodnikow);


        verticalLayout_3->addLayout(verticalLayout_5);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName("gridLayout_8");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        gridLayout_8->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        dodajZawodnikaButton = new QPushButton(centralwidget);
        dodajZawodnikaButton->setObjectName("dodajZawodnikaButton");
        dodajZawodnikaButton->setMinimumSize(QSize(300, 0));

        verticalLayout_2->addWidget(dodajZawodnikaButton);

        wyswietlPodiumButton = new QPushButton(centralwidget);
        wyswietlPodiumButton->setObjectName("wyswietlPodiumButton");

        verticalLayout_2->addWidget(wyswietlPodiumButton);


        gridLayout_8->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        gridLayout_8->addLayout(horizontalLayout_6, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_8);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tabelaZawodnikow->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Wiek", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabelaZawodnikow->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nazwisko", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabelaZawodnikow->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Liczba punkt\303\263w", nullptr));
        dodajZawodnikaButton->setText(QCoreApplication::translate("MainWindow", "Dodaj zawodnika", nullptr));
        wyswietlPodiumButton->setText(QCoreApplication::translate("MainWindow", "Wyznacz podium", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
