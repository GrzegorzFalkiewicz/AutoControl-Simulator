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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QDoubleSpinBox *spinBoxA1;
    QDoubleSpinBox *spinBoxA2;
    QDoubleSpinBox *spinBoxB1;
    QDoubleSpinBox *spinBoxB2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QComboBox *signalTypeComboBox;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxAmplituda;
    QLabel *label_9;
    QDoubleSpinBox *spinBoxOkres;
    QLabel *label_10;
    QDoubleSpinBox *spinBoxWypelnienie;
    QLabel *label_11;
    QSpinBox *spinBoxCzas;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *spinBoxK;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxTi;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxTd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(3840, 2160));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        spinBoxA1 = new QDoubleSpinBox(centralwidget);
        spinBoxA1->setObjectName("spinBoxA1");
        spinBoxA1->setGeometry(QRect(20, 360, 61, 31));
        spinBoxA1->setMinimum(-100.000000000000000);
        spinBoxA1->setMaximum(100.000000000000000);
        spinBoxA1->setSingleStep(0.100000000000000);
        spinBoxA2 = new QDoubleSpinBox(centralwidget);
        spinBoxA2->setObjectName("spinBoxA2");
        spinBoxA2->setGeometry(QRect(80, 360, 62, 31));
        spinBoxA2->setMinimum(-100.000000000000000);
        spinBoxA2->setMaximum(100.000000000000000);
        spinBoxA2->setSingleStep(0.100000000000000);
        spinBoxB1 = new QDoubleSpinBox(centralwidget);
        spinBoxB1->setObjectName("spinBoxB1");
        spinBoxB1->setGeometry(QRect(140, 360, 62, 31));
        spinBoxB1->setMinimum(-100.000000000000000);
        spinBoxB1->setMaximum(100.000000000000000);
        spinBoxB1->setSingleStep(0.100000000000000);
        spinBoxB2 = new QDoubleSpinBox(centralwidget);
        spinBoxB2->setObjectName("spinBoxB2");
        spinBoxB2->setGeometry(QRect(200, 360, 62, 31));
        spinBoxB2->setMinimum(-100.000000000000000);
        spinBoxB2->setMaximum(100.000000000000000);
        spinBoxB2->setSingleStep(0.100000000000000);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 340, 16, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 340, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 340, 49, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 340, 49, 16));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(420, 0, 861, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 161, 321));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        signalTypeComboBox = new QComboBox(verticalLayoutWidget_2);
        signalTypeComboBox->setObjectName("signalTypeComboBox");

        verticalLayout_3->addWidget(signalTypeComboBox);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName("label_8");
        label_8->setAutoFillBackground(true);

        verticalLayout_3->addWidget(label_8);

        spinBoxAmplituda = new QDoubleSpinBox(verticalLayoutWidget_2);
        spinBoxAmplituda->setObjectName("spinBoxAmplituda");
        spinBoxAmplituda->setMaximum(10.000000000000000);
        spinBoxAmplituda->setSingleStep(0.100000000000000);
        spinBoxAmplituda->setValue(1.000000000000000);

        verticalLayout_3->addWidget(spinBoxAmplituda);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setAutoFillBackground(true);

        verticalLayout_3->addWidget(label_9);

        spinBoxOkres = new QDoubleSpinBox(verticalLayoutWidget_2);
        spinBoxOkres->setObjectName("spinBoxOkres");
        spinBoxOkres->setMinimum(0.100000000000000);
        spinBoxOkres->setMaximum(100.000000000000000);
        spinBoxOkres->setSingleStep(0.100000000000000);
        spinBoxOkres->setValue(1.000000000000000);

        verticalLayout_3->addWidget(spinBoxOkres);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName("label_10");
        label_10->setAutoFillBackground(true);

        verticalLayout_3->addWidget(label_10);

        spinBoxWypelnienie = new QDoubleSpinBox(verticalLayoutWidget_2);
        spinBoxWypelnienie->setObjectName("spinBoxWypelnienie");
        spinBoxWypelnienie->setMaximum(1.000000000000000);
        spinBoxWypelnienie->setSingleStep(0.010000000000000);
        spinBoxWypelnienie->setValue(0.500000000000000);

        verticalLayout_3->addWidget(spinBoxWypelnienie);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName("label_11");
        label_11->setAutoFillBackground(true);

        verticalLayout_3->addWidget(label_11);

        spinBoxCzas = new QSpinBox(verticalLayoutWidget_2);
        spinBoxCzas->setObjectName("spinBoxCzas");
        spinBoxCzas->setMaximum(100);

        verticalLayout_3->addWidget(spinBoxCzas);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 640, 501, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(horizontalLayoutWidget);
        startButton->setObjectName("startButton");

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName("stopButton");
        stopButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(stopButton);

        resetButton = new QPushButton(horizontalLayoutWidget);
        resetButton->setObjectName("resetButton");

        horizontalLayout->addWidget(resetButton);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(160, 0, 160, 155));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName("label_5");
        label_5->setAutoFillBackground(true);

        verticalLayout_4->addWidget(label_5);

        spinBoxK = new QDoubleSpinBox(verticalLayoutWidget_3);
        spinBoxK->setObjectName("spinBoxK");
        spinBoxK->setMinimum(-100.000000000000000);
        spinBoxK->setMaximum(100.000000000000000);
        spinBoxK->setSingleStep(0.100000000000000);

        verticalLayout_4->addWidget(spinBoxK);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName("label_6");
        label_6->setAutoFillBackground(true);

        verticalLayout_4->addWidget(label_6);

        spinBoxTi = new QDoubleSpinBox(verticalLayoutWidget_3);
        spinBoxTi->setObjectName("spinBoxTi");
        spinBoxTi->setMinimum(-100.000000000000000);
        spinBoxTi->setMaximum(100.000000000000000);
        spinBoxTi->setSingleStep(0.100000000000000);
        spinBoxTi->setValue(1.000000000000000);

        verticalLayout_4->addWidget(spinBoxTi);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName("label_7");
        label_7->setAutoFillBackground(true);

        verticalLayout_4->addWidget(label_7);

        spinBoxTd = new QDoubleSpinBox(verticalLayoutWidget_3);
        spinBoxTd->setObjectName("spinBoxTd");
        spinBoxTd->setMinimum(-100.000000000000000);
        spinBoxTd->setMaximum(100.000000000000000);
        spinBoxTd->setSingleStep(0.100000000000000);

        verticalLayout_4->addWidget(spinBoxTd);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UAR - PROJEKT", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "A1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "A2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "B1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "B2", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "AMPLITUDA", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "OKRES", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "WYPELNIENIE", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "OPOZNIENIE", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "k", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
