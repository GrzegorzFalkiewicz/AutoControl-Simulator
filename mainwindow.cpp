#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    uklad(nullptr),
    timer(new QTimer(this)),
    typSygnalu(TypSygnalu::SkokJednostkowy)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSimulation);
    ui->signalTypeComboBox->addItem("Skok jednostkowy");
    ui->signalTypeComboBox->addItem("Sygnał prostokątny");
    ui->signalTypeComboBox->addItem("Sygnał sinusoidalny");
    connect(ui->signalTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_signalTypeComboBox_currentIndexChanged);

    chart = new QChart();
    series = new QLineSeries();
    series->setName("Wartość regulowana");
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
    chartPID->addSeries(seriesP);
    chartPID->addSeries(seriesI);
    chartPID->addSeries(seriesD);
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
    chartViewPID = new QChartView(chartPID);
    chartViewPID->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayoutPID->addWidget(chartViewPID);

    chartUchyb = new QChart();
    seriesUchyb = new QLineSeries();
    seriesUchyb->setName("Uchyb");
    seriesUchyb->setColor(Qt::darkRed);
    chartUchyb->addSeries(seriesUchyb);
    axisXUchyb = new QValueAxis();
    axisXUchyb->setTitleText("Krok symulacji");
    axisXUchyb->setLabelFormat("%d");
    axisXUchyb->setTickCount(10);
    axisXUchyb->setRange(0, 50);
    axisYUchyb = new QValueAxis();
    axisYUchyb->setTitleText("Wartość sygnału");
    axisYUchyb->setLabelFormat("%.2f");
    axisYUchyb->setRange(-10, 10);
    chartUchyb->addAxis(axisXUchyb, Qt::AlignBottom);
    chartUchyb->addAxis(axisYUchyb, Qt::AlignLeft);
    seriesUchyb->attachAxis(axisXUchyb);
    seriesUchyb->attachAxis(axisYUchyb);
    chartViewUchyb = new QChartView(chartUchyb);
    chartViewUchyb->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayoutUchyb->addWidget(chartViewUchyb);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    std::vector<double> wspA = {ui->spinBoxA1->value(), ui->spinBoxA2->value(), ui->spinBoxA3->value()};
    std::vector<double> wspB = {ui->spinBoxB1->value(), ui->spinBoxB2->value(), ui->spinBoxB3->value()};
    double k = ui->spinBoxK->value();
    double ti = ui->spinBoxTi->value();
    double td = ui->spinBoxTd->value();
    double amplituda = ui->spinBoxAmplituda->value();
    double okres = ui->spinBoxOkres->value();
    double wypelnienie = ui->spinBoxWypelnienie->value();
    int czasAktywacji = ui->spinBoxCzas->value();
    if (ti == 0.0) {
        ti = 0.1;
    }
    uklad = new UkladRegulacji(wspA, wspB,1, k, ti, td, typSygnalu, amplituda, okres, wypelnienie, czasAktywacji);
    timer->start(100);
}

void MainWindow::updateSimulation()
{
    if (uklad) {
        double wartoscZadana = uklad->getGenerator().generuj(krok);
        double wynik = uklad->symuluj(krok);

        double uchyb = wartoscZadana - wynik;
        double wyjP = uklad->getRegulator().symulujProporcjonalny(uchyb);
        double wyjI = uklad->getRegulator().symulujCalkujacy(uchyb);
        double wyjD = uklad->getRegulator().symulujRozniczkujacy(uchyb);

        series->append(krok, wynik);
        seriesSetpoint->append(krok, wartoscZadana);

        seriesP->append(krok, wyjP);
        seriesI->append(krok, wyjI);
        seriesD->append(krok, wyjD);
        seriesUchyb->append(krok,uchyb);

        if (krok > axisX->max()) {
            axisX->setMax(axisX->max() + 10);
            axisXPID->setMax(axisXPID->max() + 10);
            axisXUchyb->setMax(axisXUchyb->max() + 10);
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
        seriesP->clear();
        seriesI->clear();
        seriesD->clear();
        axisXPID->setRange(0, 50);
        axisYPID->setRange(-10, 10);
        seriesUchyb->clear();
        axisXUchyb->setRange(0,50);
        axisYUchyb->setRange(-10,10);
    }
    delete uklad;
    uklad = nullptr;
    ui->spinBoxA1->setValue(0.0);
    ui->spinBoxA2->setValue(0.0);
    ui->spinBoxA3->setValue(0.0);
    ui->spinBoxB1->setValue(0.0);
    ui->spinBoxB2->setValue(0.0);
    ui->spinBoxB3->setValue(0.0);
    ui->spinBoxK->setValue(0.5);
    ui->spinBoxTi->setValue(1.0);
    ui->spinBoxTd->setValue(0.2);
    ui->spinBoxAmplituda->setValue(1.0);
    ui->spinBoxOkres->setValue(1.0);
    ui->spinBoxWypelnienie->setValue(0.5);
    ui->spinBoxCzas->setValue(0);
    ui->signalTypeComboBox->setCurrentIndex(0);
}

void MainWindow::on_signalTypeComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        typSygnalu = TypSygnalu::SkokJednostkowy;
        break;
    case 1:
        typSygnalu = TypSygnalu::Prostokatny;
        break;
    case 2:
        typSygnalu = TypSygnalu::Sinusoidalny;
        break;
    default:
        typSygnalu = TypSygnalu::SkokJednostkowy;
        break;
    }
}
