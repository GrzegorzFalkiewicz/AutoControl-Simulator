#include "Symuluj.h"
#include <iostream>

Symuluj::Symuluj() : uklad(nullptr), krokCzasu(0.1), iteracje(100) {}

Symuluj::~Symuluj() {
    if (uklad) {
        delete uklad;
    }
}

void Symuluj::konfiguruj(double kp, double ti, double td, const std::vector<double>& a, const std::vector<double>& b, int opoznienie, double amplituda, double okres, double wypelnienie) {
    if (uklad) {
        delete uklad;
    }

    uklad = new UkladRegulacji(kp, ti, td, a, b, opoznienie, amplituda, okres, wypelnienie);
}

void Symuluj::ustawParametrySymulacji(double krokCzasu, int iteracje) {
    this->krokCzasu = krokCzasu;
    this->iteracje = iteracje;
}

void Symuluj::uruchom() {
    if (!uklad) {
        throw std::runtime_error("Uk³ad regulacji nie zosta³ skonfigurowany.");
    }

    daneWyjsciowe.clear();
    for (int i = 0; i < iteracje; ++i) {
        uklad->krokSymulacji(krokCzasu);
        daneWyjsciowe.push_back(uklad->pobierzWyjscieModelu());
    }
}

const std::vector<double>& Symuluj::pobierzDaneWyjsciowe() const {
    return daneWyjsciowe;
}
