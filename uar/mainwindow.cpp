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

    // Inicjalizacja wykresu
    chart = new QChart();
    series = new QLineSeries();
    series->setName("Wynik symulacji");

    seriesSetpoint = new QLineSeries();
    seriesSetpoint->setName("Wartość zadana");
    seriesSetpoint->setColor(Qt::red);

    chart->addSeries(series);
    chart->addSeries(seriesSetpoint);

    // Poprawne podłączenie osi X i Y
    axisX = new QValueAxis();
    axisX->setTitleText("Krok symulacji");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(10);
    axisX->setRange(0, 50); // Ustawienie zakresu osi X

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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete uklad;
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
    uklad = new UkladRegulacji(wspA, wspB, 1, k, ti, td, currentSignalType, amplituda, okres, wypelnienie, czasAktywacji);
    timer->start(100);
}

void MainWindow::updateSimulation()
{
    static int krok = 0;
    if (uklad) {
        double wartoscZadana = uklad->getGenerator().generuj(krok);
        double wynik = uklad->symuluj(krok);

        series->append(krok, wynik);
        seriesSetpoint->append(krok, wartoscZadana);

        if (krok > axisX->max()) {
            axisX->setMax(axisX->max() + 10);
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
        timer->stop();
        series->clear();
        seriesSetpoint->clear();
        axisX->setRange(0, 50);
        std::cout << "Symulacja zresetowana." << std::endl;
    }
    delete uklad;
    uklad = nullptr;
    ui->spinBoxA1->setValue(0.0);
    ui->spinBoxA2->setValue(0.0);
    ui->spinBoxB1->setValue(0.0);
    ui->spinBoxB2->setValue(0.0);
    ui->spinBoxK->setValue(0.0);
    ui->spinBoxTi->setValue(0.0);
    ui->spinBoxTd->setValue(0.0);
    ui->spinBoxAmplituda->setValue(1.0);
    ui->spinBoxOkres->setValue(1.0);
    ui->spinBoxWypelnienie->setValue(0.5);
    ui->spinBoxCzas->setValue(0);
    ui->signalTypeComboBox->setCurrentIndex(0);
    series->clear();
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
