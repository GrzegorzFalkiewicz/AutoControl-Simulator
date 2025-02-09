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

    connect(ui->spinBoxA1, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxA1_valueChanged);
    connect(ui->spinBoxA2, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxA2_valueChanged);
    connect(ui->spinBoxA3, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxA3_valueChanged);
    connect(ui->spinBoxB1, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxB1_valueChanged);
    connect(ui->spinBoxB2, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxB2_valueChanged);
    connect(ui->spinBoxB3, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxB3_valueChanged);

    connect(ui->spinBoxK, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxK_valueChanged);
    connect(ui->spinBoxTi, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxTi_valueChanged);
    connect(ui->spinBoxTd, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxTd_valueChanged);

    connect(ui->spinBoxAmplituda, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxAmplituda_valueChanged);
    connect(ui->spinBoxOkres, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_spinBoxOkres_valueChanged);

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
    axisY = new QValueAxis();
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
    int opoznienie = ui->spinBoxCzas->value();
    if (ti == 0.0) {
        ti = 0.1;
    }
    uklad = new UkladRegulacji(wspA, wspB,opoznienie, k, ti, td, typSygnalu, amplituda, okres, wypelnienie);
    ui->startButton->hide();
}

void MainWindow::on_wznowButton_clicked()
{
    timer->start(100);
}

void MainWindow::updateSimulation()
{
    if (uklad) {
        double wartoscZadana = uklad->getGenerator().generuj(krok);
        double wynik = uklad->symuluj(krok);
        double uchyb = wartoscZadana - wynik;
        double wyjP = uklad->getRegulator().getWyjP();
        double wyjI = uklad->getRegulator().getWyjI();
        double wyjD = uklad->getRegulator().getWyjD();

        series->append(krok, wynik);
        seriesSetpoint->append(krok, wartoscZadana);
        seriesP->append(krok, wyjP);
        seriesI->append(krok, wyjI);
        seriesD->append(krok, wyjD);
        seriesUchyb->append(krok, uchyb);

        int windowSize = 100;
        int startX = (krok / windowSize) * windowSize;
        int endX = startX + windowSize;

        axisX->setRange(startX, endX);
        axisXPID->setRange(startX, endX);
        axisXUchyb->setRange(startX, endX);

        auto calculateYRange = [](const QLineSeries* series) {
            int minY = std::numeric_limits<int>::max();
            int maxY = std::numeric_limits<int>::min();
            for (const QPointF& point : series->points()) {
                minY = std::min(minY, static_cast<int>(std::floor(point.y())));
                maxY = std::max(maxY, static_cast<int>(std::ceil(point.y())));
            }
            return std::make_pair(minY, maxY);
        };

        auto [minY, maxY] = calculateYRange(series);
        auto [minYSetpoint, maxYSetpoint] = calculateYRange(seriesSetpoint);
        minY = std::min(minY, minYSetpoint);
        maxY = std::max(maxY, maxYSetpoint);
        minY = std::min(minY, 0);
        maxY = std::max(maxY, 0);
        axisY->setRange(minY - 1, maxY + 1);
        axisY->setLabelFormat("%d");
        auto [minP, maxP] = calculateYRange(seriesP);
        auto [minI, maxI] = calculateYRange(seriesI);
        auto [minD, maxD] = calculateYRange(seriesD);
        int minPID = std::min({minP, minI, minD});
        int maxPID = std::max({maxP, maxI, maxD});
        minPID = std::min(minPID, 0);
        maxPID = std::max(maxPID, 0);
        axisYPID->setRange(minPID - 1, maxPID + 1);
        axisYPID->setLabelFormat("%d");
        auto [minUchyb, maxUchyb] = calculateYRange(seriesUchyb);
        minUchyb = std::min(minUchyb, 0);
        maxUchyb = std::max(maxUchyb, 0);
        axisYUchyb->setRange(minUchyb - 1, maxUchyb + 1);
        axisYUchyb->setLabelFormat("%d");
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
        axisY->setRange(-10, 10);
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
    ui->spinBoxA1->setValue(-0.4);
    ui->spinBoxA2->setValue(0.0);
    ui->spinBoxA3->setValue(0.0);
    ui->spinBoxB1->setValue(0.6);
    ui->spinBoxB2->setValue(0.0);
    ui->spinBoxB3->setValue(0.0);
    ui->spinBoxK->setValue(0.5);
    ui->spinBoxTi->setValue(5.0);
    ui->spinBoxTd->setValue(0.2);
    ui->spinBoxAmplituda->setValue(5.0);
    ui->spinBoxOkres->setValue(20.0);
    ui->spinBoxWypelnienie->setValue(0.5);
    ui->spinBoxCzas->setValue(1);
    ui->signalTypeComboBox->setCurrentIndex(0);
    ui->startButton->show();
}
void MainWindow::on_signalTypeComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0: typSygnalu = TypSygnalu::SkokJednostkowy; break;
    case 1: typSygnalu = TypSygnalu::Prostokatny; break;
    case 2: typSygnalu = TypSygnalu::Sinusoidalny; break;
    default: typSygnalu = TypSygnalu::SkokJednostkowy; break;
    }
    if (uklad) {
        uklad->getGenerator().setTypSygnalu(typSygnalu);
    }
}
void MainWindow::on_spinBoxA1_valueChanged(double value) {
    if (uklad) {
        auto wspA = uklad->getModel().getWspA();
        wspA[0] = value;
        uklad->getModel().setWspA(wspA);
    }
}
void MainWindow::on_spinBoxA2_valueChanged(double value) {
    if (uklad) {
        auto wspA = uklad->getModel().getWspA();
        wspA[1] = value;
        uklad->getModel().setWspA(wspA);
    }
}
void MainWindow::on_spinBoxA3_valueChanged(double value) {
    if (uklad) {
        auto wspA = uklad->getModel().getWspA();
        wspA[2] = value;
        uklad->getModel().setWspA(wspA);
    }
}
void MainWindow::on_spinBoxB1_valueChanged(double value) {
    if (uklad) {
        auto wspB = uklad->getModel().getWspB();
        wspB[0] = value;
        uklad->getModel().setWspB(wspB);
    }
}
void MainWindow::on_spinBoxB2_valueChanged(double value) {
    if (uklad) {
        auto wspB = uklad->getModel().getWspB();
        wspB[1] = value;
        uklad->getModel().setWspB(wspB);
    }
}
void MainWindow::on_spinBoxB3_valueChanged(double value) {
    if (uklad) {
        auto wspB = uklad->getModel().getWspB();
        wspB[2] = value;
        uklad->getModel().setWspB(wspB);
    }
}
void MainWindow::on_spinBoxK_valueChanged(double value) {
    if (uklad) {
        uklad->getRegulator().setK(value);
    }
}
void MainWindow::on_spinBoxTi_valueChanged(double value) {
    if (uklad) {
        uklad->getRegulator().setTi(value);
    }
}
void MainWindow::on_spinBoxTd_valueChanged(double value) {
    if (uklad) {
        uklad->getRegulator().setTd(value);
    }
}
void MainWindow::on_spinBoxAmplituda_valueChanged(double value) {
    if (uklad) {
        uklad->getGenerator().setAmplituda(value);
    }
}
void MainWindow::on_spinBoxOkres_valueChanged(double value) {
    if (uklad) {
        uklad->getGenerator().setOkres(value);
    }
}
void MainWindow::on_spinBoxWypelnienie_valueChanged(double value) {
    if (uklad) {
        uklad->getGenerator().setWypelnienie(value);
    }
}
