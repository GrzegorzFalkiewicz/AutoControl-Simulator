#pragma once
#include "UkladRegulacji.h"
#include <vector>

class Symuluj {
private:
    UkladRegulacji* uklad;
    std::vector<double> daneWyjsciowe; // Przechowuje dane wyj�ciowe symulacji
    double krokCzasu;
    int iteracje;

public:
    Symuluj();
    ~Symuluj();

    // Konfiguracja symulacji
    void konfiguruj(double kp, double ti, double td, const std::vector<double>& a, const std::vector<double>& b, int opoznienie, double amplituda, double okres, double wypelnienie);
    void ustawParametrySymulacji(double krokCzasu, int iteracje);

    // Uruchamianie symulacji
    void uruchom();
};
