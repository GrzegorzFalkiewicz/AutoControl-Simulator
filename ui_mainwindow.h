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
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QVBoxLayout *verticalLayoutUchyb;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *spinBoxAmplituda;
    QDoubleSpinBox *spinBoxOkres;
    QDoubleSpinBox *spinBoxWypelnienie;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxTi;
    QDoubleSpinBox *spinBoxK;
    QDoubleSpinBox *spinBoxTd;
    QLabel *label_7;
    QComboBox *signalTypeComboBox;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayoutPID;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *label_11;
    QSpinBox *spinBoxCzas;
    QDoubleSpinBox *spinBoxA3;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxA1;
    QDoubleSpinBox *spinBoxA2;
    QLabel *label_3;
    QLabel *label_12;
    QDoubleSpinBox *spinBoxB1;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxB2;
    QDoubleSpinBox *spinBoxB3;
    QLabel *label_13;
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
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName("gridLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(0, 100));
        startButton->setMaximumSize(QSize(16777215, 300));
        startButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumSize(QSize(0, 100));
        stopButton->setMaximumSize(QSize(16777215, 300));
        stopButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(stopButton);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setMinimumSize(QSize(0, 100));
        resetButton->setMaximumSize(QSize(16777215, 300));
        resetButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(resetButton);


        gridLayout_5->addLayout(horizontalLayout, 4, 0, 1, 1);

        verticalLayoutUchyb = new QVBoxLayout();
        verticalLayoutUchyb->setObjectName("verticalLayoutUchyb");

        gridLayout_5->addLayout(verticalLayoutUchyb, 3, 2, 2, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        spinBoxAmplituda = new QDoubleSpinBox(centralwidget);
        spinBoxAmplituda->setObjectName("spinBoxAmplituda");
        spinBoxAmplituda->setMinimumSize(QSize(134, 23));
        spinBoxAmplituda->setMaximum(10.000000000000000);
        spinBoxAmplituda->setSingleStep(0.100000000000000);
        spinBoxAmplituda->setValue(1.000000000000000);

        gridLayout_3->addWidget(spinBoxAmplituda, 1, 0, 1, 1);

        spinBoxOkres = new QDoubleSpinBox(centralwidget);
        spinBoxOkres->setObjectName("spinBoxOkres");
        spinBoxOkres->setMinimumSize(QSize(135, 23));
        spinBoxOkres->setMinimum(0.100000000000000);
        spinBoxOkres->setMaximum(100.000000000000000);
        spinBoxOkres->setSingleStep(0.100000000000000);
        spinBoxOkres->setValue(1.000000000000000);

        gridLayout_3->addWidget(spinBoxOkres, 1, 1, 1, 1);

        spinBoxWypelnienie = new QDoubleSpinBox(centralwidget);
        spinBoxWypelnienie->setObjectName("spinBoxWypelnienie");
        spinBoxWypelnienie->setMinimumSize(QSize(134, 23));
        spinBoxWypelnienie->setMaximum(1.000000000000000);
        spinBoxWypelnienie->setSingleStep(0.010000000000000);
        spinBoxWypelnienie->setValue(0.500000000000000);

        gridLayout_3->addWidget(spinBoxWypelnienie, 1, 2, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(134, 123));
        label_8->setMaximumSize(QSize(16777215, 300));
        label_8->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_8->setAutoFillBackground(true);
        label_8->setLineWidth(2);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(135, 123));
        label_9->setMaximumSize(QSize(16777215, 300));
        label_9->setAutoFillBackground(true);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(134, 123));
        label_10->setMaximumSize(QSize(16777215, 300));
        label_10->setAutoFillBackground(true);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_10, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 300));
        label_5->setAutoFillBackground(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(16777215, 300));
        label_6->setAutoFillBackground(true);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        spinBoxTi = new QDoubleSpinBox(centralwidget);
        spinBoxTi->setObjectName("spinBoxTi");
        spinBoxTi->setAutoFillBackground(true);
        spinBoxTi->setMinimum(-100.000000000000000);
        spinBoxTi->setMaximum(100.000000000000000);
        spinBoxTi->setSingleStep(0.100000000000000);
        spinBoxTi->setValue(1.000000000000000);

        gridLayout_2->addWidget(spinBoxTi, 1, 2, 1, 1);

        spinBoxK = new QDoubleSpinBox(centralwidget);
        spinBoxK->setObjectName("spinBoxK");
        spinBoxK->setAutoFillBackground(true);
        spinBoxK->setMinimum(-100.000000000000000);
        spinBoxK->setMaximum(100.000000000000000);
        spinBoxK->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(spinBoxK, 1, 1, 1, 1);

        spinBoxTd = new QDoubleSpinBox(centralwidget);
        spinBoxTd->setObjectName("spinBoxTd");
        spinBoxTd->setAutoFillBackground(true);
        spinBoxTd->setMinimum(-100.000000000000000);
        spinBoxTd->setMaximum(100.000000000000000);
        spinBoxTd->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(spinBoxTd, 1, 3, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(0, 50));
        label_7->setMaximumSize(QSize(16777215, 300));
        label_7->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_7->setAutoFillBackground(true);
        label_7->setFrameShape(QFrame::Shape::NoFrame);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 3, 0, 1, 1);

        signalTypeComboBox = new QComboBox(centralwidget);
        signalTypeComboBox->setObjectName("signalTypeComboBox");
        signalTypeComboBox->setAutoFillBackground(true);

        gridLayout_5->addWidget(signalTypeComboBox, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        gridLayout_5->addLayout(verticalLayout, 0, 1, 3, 2);

        verticalLayoutPID = new QVBoxLayout();
        verticalLayoutPID->setObjectName("verticalLayoutPID");

        gridLayout_5->addLayout(verticalLayoutPID, 3, 1, 2, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 300));
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label, 0, 1, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(16777215, 300));
        label_11->setAutoFillBackground(true);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_11, 0, 0, 1, 1);

        spinBoxCzas = new QSpinBox(centralwidget);
        spinBoxCzas->setObjectName("spinBoxCzas");
        spinBoxCzas->setMaximum(100);

        gridLayout_4->addWidget(spinBoxCzas, 1, 0, 1, 1, Qt::AlignmentFlag::AlignVCenter);

        spinBoxA3 = new QDoubleSpinBox(centralwidget);
        spinBoxA3->setObjectName("spinBoxA3");
        spinBoxA3->setMinimum(-99.000000000000000);
        spinBoxA3->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxA3, 1, 3, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 300));
        label_2->setAutoFillBackground(true);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        spinBoxA1 = new QDoubleSpinBox(centralwidget);
        spinBoxA1->setObjectName("spinBoxA1");
        spinBoxA1->setAutoFillBackground(true);
        spinBoxA1->setMinimum(-100.000000000000000);
        spinBoxA1->setMaximum(100.000000000000000);
        spinBoxA1->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxA1, 1, 1, 1, 1);

        spinBoxA2 = new QDoubleSpinBox(centralwidget);
        spinBoxA2->setObjectName("spinBoxA2");
        spinBoxA2->setAutoFillBackground(true);
        spinBoxA2->setMinimum(-100.000000000000000);
        spinBoxA2->setMaximum(100.000000000000000);
        spinBoxA2->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxA2, 1, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 300));
        label_3->setAutoFillBackground(true);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_3, 2, 1, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 300));
        label_12->setAutoFillBackground(true);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_12, 0, 3, 1, 1);

        spinBoxB1 = new QDoubleSpinBox(centralwidget);
        spinBoxB1->setObjectName("spinBoxB1");
        spinBoxB1->setAutoFillBackground(true);
        spinBoxB1->setMinimum(-100.000000000000000);
        spinBoxB1->setMaximum(100.000000000000000);
        spinBoxB1->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxB1, 3, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 300));
        label_4->setAutoFillBackground(true);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_4, 2, 2, 1, 1);

        spinBoxB2 = new QDoubleSpinBox(centralwidget);
        spinBoxB2->setObjectName("spinBoxB2");
        spinBoxB2->setAutoFillBackground(true);
        spinBoxB2->setMinimum(-100.000000000000000);
        spinBoxB2->setMaximum(100.000000000000000);
        spinBoxB2->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxB2, 3, 2, 1, 1);

        spinBoxB3 = new QDoubleSpinBox(centralwidget);
        spinBoxB3->setObjectName("spinBoxB3");
        spinBoxB3->setMinimum(-99.000000000000000);
        spinBoxB3->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(spinBoxB3, 3, 3, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setMaximumSize(QSize(16777215, 300));
        label_13->setAutoFillBackground(true);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label_13, 2, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 2, 0, 1, 1);

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
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "AMPLITUDA", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "OKRES", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "WYPELNIENIE", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "k", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "A1", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "k", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "A2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "B1", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "A3", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "B2", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "B3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
