#include "SprzezenieZwrotne.h"

SprzezenieZwrotne::SprzezenieZwrotne(ModelARX* model, RegulatorPID* regulator, Generator* generator)
    : model(model), regulator(regulator), generator(generator) {
}

double SprzezenieZwrotne::symuluj(int krok) {
    double wartoscZadana = generator->generuj(krok);
    double wartoscModelu = model->symuluj(0);  // Model powinien startować od zera
    double uchyb = wartoscZadana - wartoscModelu;
    double sterowanie = regulator->symuluj(uchyb);
    return model->symuluj(sterowanie);  // Sterowanie tylko raz trafia do modelu
}
