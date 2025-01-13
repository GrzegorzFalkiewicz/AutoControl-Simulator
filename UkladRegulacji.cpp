#include "UkladRegulacji.h"
#include <iostream>

UkladRegulacji::UkladRegulacji(const std::vector<double>& wspA, const std::vector<double>& wspB, int opoznienie,
    double k, double ti, double td,
    TypSygnalu typSygnalu, double amplituda, double okres, double wypelnienie, int czasAktywacji)
    : model(wspA, wspB, opoznienie),
    regulator(k, ti, td),
    generator(typSygnalu, amplituda, okres, wypelnienie, czasAktywacji),
    petla(&model, &regulator, &generator) {
}

void UkladRegulacji::symuluj(int liczbaKrokow) {
    for (int krok = 0; krok < liczbaKrokow; ++krok) {
        double wynik = petla.symuluj(krok);
        std::cout << "Krok: " << krok << ", Wynik: " << wynik << std::endl;
    }
}
ModelARX& UkladRegulacji::getModel() {
    return model;
}

RegulatorPID& UkladRegulacji::getRegulator() {
    return regulator;
}

Generator& UkladRegulacji::getGenerator() {
    return generator;
}
