/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *nazwiskoInput;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *wiekInput;
    QSpinBox *punktyInput;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(366, 202);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        nazwiskoInput = new QLineEdit(Dialog);
        nazwiskoInput->setObjectName("nazwiskoInput");

        formLayout->setWidget(0, QFormLayout::FieldRole, nazwiskoInput);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label = new QLabel(Dialog);
        label->setObjectName("label");

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        wiekInput = new QSpinBox(Dialog);
        wiekInput->setObjectName("wiekInput");
        wiekInput->setMaximum(99);

        formLayout->setWidget(1, QFormLayout::FieldRole, wiekInput);

        punktyInput = new QSpinBox(Dialog);
        punktyInput->setObjectName("punktyInput");

        formLayout->setWidget(2, QFormLayout::FieldRole, punktyInput);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Nazwisko:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Wiek: ", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Liczba punkt\303\263w: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
