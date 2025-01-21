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
#include <QtWidgets/QGridLayout>
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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayoutPID;
    QPushButton *resetPIDButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxTi;
    QDoubleSpinBox *spinBoxK;
    QDoubleSpinBox *spinBoxTd;
    QLabel *label_7;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *spinBoxAmplituda;
    QDoubleSpinBox *spinBoxOkres;
    QLabel *label_11;
    QDoubleSpinBox *spinBoxWypelnienie;
    QLabel *label_8;
    QSpinBox *spinBoxCzas;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *signalTypeComboBox;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxA1;
    QDoubleSpinBox *spinBoxA2;
    QDoubleSpinBox *spinBoxB1;
    QDoubleSpinBox *spinBoxB2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(3840, 2160));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(440, 20, 821, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(440, 390, 821, 291));
        verticalLayoutPID = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayoutPID->setObjectName("verticalLayoutPID");
        verticalLayoutPID->setContentsMargins(0, 0, 0, 0);
        resetPIDButton = new QPushButton(centralwidget);
        resetPIDButton->setObjectName("resetPIDButton");
        resetPIDButton->setGeometry(QRect(140, 480, 251, 41));
        resetPIDButton->setAutoFillBackground(true);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 410, 371, 71));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setAutoFillBackground(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setAutoFillBackground(true);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        spinBoxTi = new QDoubleSpinBox(gridLayoutWidget);
        spinBoxTi->setObjectName("spinBoxTi");
        spinBoxTi->setAutoFillBackground(true);
        spinBoxTi->setMinimum(-100.000000000000000);
        spinBoxTi->setMaximum(100.000000000000000);
        spinBoxTi->setSingleStep(0.100000000000000);
        spinBoxTi->setValue(1.000000000000000);

        gridLayout_2->addWidget(spinBoxTi, 1, 2, 1, 1);

        spinBoxK = new QDoubleSpinBox(gridLayoutWidget);
        spinBoxK->setObjectName("spinBoxK");
        spinBoxK->setAutoFillBackground(true);
        spinBoxK->setMinimum(-100.000000000000000);
        spinBoxK->setMaximum(100.000000000000000);
        spinBoxK->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(spinBoxK, 1, 1, 1, 1);

        spinBoxTd = new QDoubleSpinBox(gridLayoutWidget);
        spinBoxTd->setObjectName("spinBoxTd");
        spinBoxTd->setAutoFillBackground(true);
        spinBoxTd->setMinimum(-100.000000000000000);
        spinBoxTd->setMaximum(100.000000000000000);
        spinBoxTd->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(spinBoxTd, 1, 3, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_7->setAutoFillBackground(true);
        label_7->setFrameShape(QFrame::Shape::NoFrame);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 3, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 20, 371, 91));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        spinBoxAmplituda = new QDoubleSpinBox(gridLayoutWidget_2);
        spinBoxAmplituda->setObjectName("spinBoxAmplituda");
        spinBoxAmplituda->setMaximum(10.000000000000000);
        spinBoxAmplituda->setSingleStep(0.100000000000000);
        spinBoxAmplituda->setValue(1.000000000000000);

        gridLayout_3->addWidget(spinBoxAmplituda, 1, 0, 1, 1);

        spinBoxOkres = new QDoubleSpinBox(gridLayoutWidget_2);
        spinBoxOkres->setObjectName("spinBoxOkres");
        spinBoxOkres->setMinimum(0.100000000000000);
        spinBoxOkres->setMaximum(100.000000000000000);
        spinBoxOkres->setSingleStep(0.100000000000000);
        spinBoxOkres->setValue(1.000000000000000);

        gridLayout_3->addWidget(spinBoxOkres, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName("label_11");
        label_11->setAutoFillBackground(true);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_11, 0, 3, 1, 1);

        spinBoxWypelnienie = new QDoubleSpinBox(gridLayoutWidget_2);
        spinBoxWypelnienie->setObjectName("spinBoxWypelnienie");
        spinBoxWypelnienie->setMaximum(1.000000000000000);
        spinBoxWypelnienie->setSingleStep(0.010000000000000);
        spinBoxWypelnienie->setValue(0.500000000000000);

        gridLayout_3->addWidget(spinBoxWypelnienie, 1, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName("label_8");
        label_8->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_8->setAutoFillBackground(true);
        label_8->setLineWidth(2);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        spinBoxCzas = new QSpinBox(gridLayoutWidget_2);
        spinBoxCzas->setObjectName("spinBoxCzas");
        spinBoxCzas->setMaximum(100);

        gridLayout_3->addWidget(spinBoxCzas, 1, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setAutoFillBackground(true);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName("label_10");
        label_10->setAutoFillBackground(true);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_10, 0, 2, 1, 1);

        signalTypeComboBox = new QComboBox(centralwidget);
        signalTypeComboBox->setObjectName("signalTypeComboBox");
        signalTypeComboBox->setGeometry(QRect(20, 120, 371, 16));
        signalTypeComboBox->setAutoFillBackground(true);
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(20, 180, 371, 91));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget_3);
        label_2->setObjectName("label_2");
        label_2->setAutoFillBackground(true);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName("label_3");
        label_3->setAutoFillBackground(true);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName("label");
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName("label_4");
        label_4->setAutoFillBackground(true);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_4, 0, 3, 1, 1);

        spinBoxA1 = new QDoubleSpinBox(gridLayoutWidget_3);
        spinBoxA1->setObjectName("spinBoxA1");
        spinBoxA1->setAutoFillBackground(true);
        spinBoxA1->setMinimum(-100.000000000000000);
        spinBoxA1->setMaximum(100.000000000000000);
        spinBoxA1->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxA1, 1, 0, 1, 1);

        spinBoxA2 = new QDoubleSpinBox(gridLayoutWidget_3);
        spinBoxA2->setObjectName("spinBoxA2");
        spinBoxA2->setAutoFillBackground(true);
        spinBoxA2->setMinimum(-100.000000000000000);
        spinBoxA2->setMaximum(100.000000000000000);
        spinBoxA2->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxA2, 1, 1, 1, 1);

        spinBoxB1 = new QDoubleSpinBox(gridLayoutWidget_3);
        spinBoxB1->setObjectName("spinBoxB1");
        spinBoxB1->setAutoFillBackground(true);
        spinBoxB1->setMinimum(-100.000000000000000);
        spinBoxB1->setMaximum(100.000000000000000);
        spinBoxB1->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxB1, 1, 2, 1, 1);

        spinBoxB2 = new QDoubleSpinBox(gridLayoutWidget_3);
        spinBoxB2->setObjectName("spinBoxB2");
        spinBoxB2->setAutoFillBackground(true);
        spinBoxB2->setMinimum(-100.000000000000000);
        spinBoxB2->setMaximum(100.000000000000000);
        spinBoxB2->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxB2, 1, 3, 1, 1);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 550, 371, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(horizontalLayoutWidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(0, 100));
        startButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumSize(QSize(0, 100));
        stopButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(stopButton);

        resetButton = new QPushButton(horizontalLayoutWidget);
        resetButton->setObjectName("resetButton");
        resetButton->setMinimumSize(QSize(0, 100));
        resetButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(resetButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 19));
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
        resetPIDButton->setText(QCoreApplication::translate("MainWindow", "RESET Ti, Td", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "k", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "OPOZNIENIE", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "AMPLITUDA", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "OKRES", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "WYPELNIENIE", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "A2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "B1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "A1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "B2", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
