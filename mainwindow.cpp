#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    uklad(nullptr),
    timer(new QTimer(this)),
    currentSignalType(TypSygnalu::SkokJednostkowy)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSimulation);

    // Dodanie opcji do ComboBoxa
    ui->signalTypeComboBox->addItem("Skok jednostkowy");
    ui->signalTypeComboBox->addItem("Sygnał prostokątny");
    ui->signalTypeComboBox->addItem("Sygnał sinusoidalny");
    connect(ui->signalTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_signalTypeComboBox_currentIndexChanged);

    // Wykres dla wyniku symulacji
    chart = new QChart();
    series = new QLineSeries();
    series->setName("Wynik symulacji");

    seriesSetpoint = new QLineSeries();
    seriesSetpoint->setName("Wartość zadana");
    seriesSetpoint->setColor(Qt::red);

    chart->addSeries(series);
    chart->addSeries(seriesSetpoint);

    axisX = new QValueAxis();
    axisX->setTitleText("Krok symulacji");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(10);
    axisX->setRange(0, 50);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Wartość sygnału");
    axisY->setLabelFormat("%.2f");
    axisY->setRange(-10, 10);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    seriesSetpoint->attachAxis(axisX);
    seriesSetpoint->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);

    // Wykres dla składowych PID
    chartPID = new QChart();
    seriesP = new QLineSeries();
    seriesP->setName("Składowa P");
    seriesP->setColor(Qt::blue);

    seriesI = new QLineSeries();
    seriesI->setName("Składowa I");
    seriesI->setColor(Qt::green);

    seriesD = new QLineSeries();
    seriesD->setName("Składowa D");
    seriesD->setColor(Qt::magenta);

    seriesError = new QLineSeries();
    seriesError->setName("Uchyb");
    seriesError->setColor(Qt::darkRed);

    chartPID->addSeries(seriesP);
    chartPID->addSeries(seriesI);
    chartPID->addSeries(seriesD);
    chartPID->addSeries(seriesError);

    axisXPID = new QValueAxis();
    axisXPID->setTitleText("Krok symulacji");
    axisXPID->setLabelFormat("%d");
    axisXPID->setTickCount(10);
    axisXPID->setRange(0, 50);

    axisYPID = new QValueAxis();
    axisYPID->setTitleText("Wartość sygnału");
    axisYPID->setLabelFormat("%.2f");
    axisYPID->setRange(-10, 10);

    chartPID->addAxis(axisXPID, Qt::AlignBottom);
    chartPID->addAxis(axisYPID, Qt::AlignLeft);
    seriesP->attachAxis(axisXPID);
    seriesP->attachAxis(axisYPID);
    seriesI->attachAxis(axisXPID);
    seriesI->attachAxis(axisYPID);
    seriesD->attachAxis(axisXPID);
    seriesD->attachAxis(axisYPID);
    seriesError->attachAxis(axisXPID);
    seriesError->attachAxis(axisYPID);

    chartViewPID = new QChartView(chartPID);
    chartViewPID->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayoutPID->addWidget(chartViewPID);
}
MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::on_startButton_clicked()
{
    std::vector<double> wspA = {ui->spinBoxA1->value(), ui->spinBoxA2->value()};
    std::vector<double> wspB = {ui->spinBoxB1->value(), ui->spinBoxB2->value()};
    double k = ui->spinBoxK->value();
    double ti = ui->spinBoxTi->value();
    double td = ui->spinBoxTd->value();
    double amplituda = ui->spinBoxAmplituda->value();
    double okres = ui->spinBoxOkres->value();
    double wypelnienie = ui->spinBoxWypelnienie->value();
    int czasAktywacji = ui->spinBoxCzas->value();

    if (ti == 0.0) {
        std::cerr << "Błąd: Czas całkowania (Ti) nie może być równy 0." << std::endl;
        return;
    }
    uklad = new UkladRegulacji(wspA, wspB,1, k, ti, td, currentSignalType, amplituda, okres, wypelnienie, czasAktywacji);
    timer->start(100);
}
void MainWindow::updateSimulation()
{
    if (uklad) {
        double wartoscZadana = uklad->getGenerator().generuj(krok);
        double wynik = uklad->symuluj(krok);

        // Pobranie składowych PID
        double uchyb = wartoscZadana - wynik;
        double wyjP = uklad->getRegulator().symulujProporcjonalny(uchyb);
        double wyjI = uklad->getRegulator().symulujCalkujacy(uchyb);
        double wyjD = uklad->getRegulator().symulujRozniczkujacy(uchyb);

        // Aktualizacja głównego wykresu
        series->append(krok, wynik);
        seriesSetpoint->append(krok, wartoscZadana);

        // Aktualizacja wykresu PID
        seriesP->append(krok, wyjP);
        seriesI->append(krok, wyjI);
        seriesD->append(krok, wyjD);


        if (krok > axisX->max()) {
            axisX->setMax(axisX->max() + 10);
            axisXPID->setMax(axisXPID->max() + 10);
        }
        krok++;
    }
}
void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

void MainWindow::on_resetButton_clicked()
{
    if (uklad) {
        krok = 0;
        timer->stop();
        series->clear();
        seriesSetpoint->clear();
        axisX->setRange(0, 50);
        std::cout << "Symulacja zresetowana." << std::endl;
        seriesP->clear();
        seriesI->clear();
        seriesD->clear();
        axisXPID->setRange(0, 50);
        axisYPID->setRange(-10, 10);
    }
    delete uklad;
    uklad = nullptr;
    ui->spinBoxA1->setValue(0.0);
    ui->spinBoxA2->setValue(0.0);
    ui->spinBoxB1->setValue(0.0);
    ui->spinBoxB2->setValue(0.0);
    ui->spinBoxK->setValue(0.0);
    ui->spinBoxTi->setValue(1.0);
    ui->spinBoxTd->setValue(0.0);
    ui->spinBoxAmplituda->setValue(1.0);
    ui->spinBoxOkres->setValue(1.0);
    ui->spinBoxWypelnienie->setValue(0.5);
    ui->spinBoxCzas->setValue(0);
    ui->signalTypeComboBox->setCurrentIndex(0);
    series->clear();
    seriesSetpoint->clear();
}
void MainWindow::on_signalTypeComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        currentSignalType = TypSygnalu::SkokJednostkowy;
        break;
    case 1:
        currentSignalType = TypSygnalu::Prostokatny;
        break;
    case 2:
        currentSignalType = TypSygnalu::Sinusoidalny;
        break;
    default:
        currentSignalType = TypSygnalu::SkokJednostkowy;
        break;
    }
    std::cout << "Zmieniono typ sygnału na: " << index << std::endl;
}
