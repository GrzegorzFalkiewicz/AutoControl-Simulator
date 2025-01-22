#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Zawodnik {
    QString nazwisko;
    int wiek;
    int punkty;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dodajZawodnikaButton_clicked();
    void on_wyswietlPodiumButton_clicked();

private:
    void aktualizujListe();

    std::vector<Zawodnik> listaZawodnikow;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
