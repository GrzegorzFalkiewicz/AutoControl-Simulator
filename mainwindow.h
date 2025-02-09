#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QComboBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include "UkladRegulacji.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_resetButton_clicked();
    void on_wznowButton_clicked();
    void on_signalTypeComboBox_currentIndexChanged(int index);
    void updateSimulation();

    void on_spinBoxA1_valueChanged(double value);
    void on_spinBoxA2_valueChanged(double value);
    void on_spinBoxA3_valueChanged(double value);
    void on_spinBoxB1_valueChanged(double value);
    void on_spinBoxB2_valueChanged(double value);
    void on_spinBoxB3_valueChanged(double value);
    void on_spinBoxK_valueChanged(double value);
    void on_spinBoxTi_valueChanged(double value);
    void on_spinBoxTd_valueChanged(double value);
    void on_spinBoxAmplituda_valueChanged(double value);
    void on_spinBoxOkres_valueChanged(double value);
    void on_spinBoxWypelnienie_valueChanged(double value);
private:
    int krok = 0;
    Ui::MainWindow *ui;
    UkladRegulacji *uklad;
    QTimer *timer;
    TypSygnalu typSygnalu;

    QChart *chart;
    QChartView *chartView;
    QLineSeries *series;
    QLineSeries *seriesSetpoint;
    QValueAxis *axisX;
    QValueAxis *axisY;

    QChart *chartPID;
    QChartView *chartViewPID;
    QLineSeries *seriesP;
    QLineSeries *seriesI;
    QLineSeries *seriesD;
    QValueAxis *axisXPID;
    QValueAxis *axisYPID;

    QChart *chartUchyb;
    QChartView *chartViewUchyb;
    QLineSeries *seriesUchyb;
    QValueAxis *axisXUchyb;
    QValueAxis *axisYUchyb;
};
#endif // MAINWINDOW_H
