#include "SprzezenieZwrotne.h"

SprzezenieZwrotne::SprzezenieZwrotne(ModelARX* model, RegulatorPID* regulator, Generator* generator)
    : model(model), regulator(regulator), generator(generator), poprzedniaWartosc(0.0) {
}
double SprzezenieZwrotne::symuluj(int krok) {
    double wartoscZadana = generator->generuj(krok);
    double uchyb = wartoscZadana - poprzedniaWartosc;
    double sterowanie = regulator->symuluj(uchyb);
    double aktualnaWartosc = model->symuluj(sterowanie);
    poprzedniaWartosc = aktualnaWartosc;
    return aktualnaWartosc;
}
