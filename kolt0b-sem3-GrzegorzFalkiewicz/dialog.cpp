#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->punktyInput->setMinimum(1);
    ui->wiekInput->setMinimum(1);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getNazwisko() {
    return ui->nazwiskoInput->text();
}

int Dialog::getWiek() {
    return ui->wiekInput->value();
}

int Dialog::getPunkty() {
    return ui->punktyInput->value();
}
