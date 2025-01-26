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
    void on_signalTypeComboBox_currentIndexChanged(int index);
    void updateSimulation();

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
