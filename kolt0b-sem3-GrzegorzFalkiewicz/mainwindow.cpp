#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dodajZawodnikaButton_clicked()
{
    Dialog dialog;
    if (dialog.exec() == QDialog::Accepted) {
        Zawodnik zawodnik = {dialog.getNazwisko(), dialog.getWiek(), dialog.getPunkty()};
        listaZawodnikow.push_back(zawodnik);
        std::sort(listaZawodnikow.begin(), listaZawodnikow.end(), [](const Zawodnik &a, const Zawodnik &b) {
            return a.punkty > b.punkty;
        });
        aktualizujListe();
    }
}

void MainWindow::on_wyswietlPodiumButton_clicked()
{
    QString podium;
    int count = std::min(3, static_cast<int>(listaZawodnikow.size()));
    for (int i = 0; i < count; ++i) {
        podium += QString("%1. %2 (Punkty: %3)\n").arg(i + 1).arg(listaZawodnikow[i].nazwisko).arg(listaZawodnikow[i].punkty);
    }
    QMessageBox::information(this, "Podium", podium);
}

void MainWindow::aktualizujListe()
{
    ui->tabelaZawodnikow->setRowCount(0);
    for (const auto &zawodnik : listaZawodnikow) {
        int row = ui->tabelaZawodnikow->rowCount();
        ui->tabelaZawodnikow->insertRow(row);
        ui->tabelaZawodnikow->setItem(row, 0, new QTableWidgetItem(QString::number(zawodnik.wiek)));
        ui->tabelaZawodnikow->setItem(row, 1, new QTableWidgetItem(zawodnik.nazwisko));
        ui->tabelaZawodnikow->setItem(row, 2, new QTableWidgetItem(QString::number(zawodnik.punkty)));
    }
}
