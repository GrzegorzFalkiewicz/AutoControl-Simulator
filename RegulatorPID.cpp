#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double kp, double ti, double td)
    : kp(kp), ti(ti), td(td), akumulator(0.0), poprzedniBladaWart(0.0), ostatniCzas(0.0) {}

double RegulatorPID::symuluj(double blad, double czas) {
    // Obliczanie r�nicy czasu
    double roznicaCzasu = czas - ostatniCzas;
    if (roznicaCzasu <= 0.0) {
        roznicaCzasu = 1e-6; // Minimalny krok czasu dla stabilno�ci
    }
    ostatniCzas = czas;

    // Cz�on proporcjonalny
    double wyj_p = kp * blad;

    // Cz�on ca�kuj�cy
    double wyj_i = 0.0;
    if (ti != 0.0) {
        akumulator += blad * roznicaCzasu;
        wyj_i = akumulator * (kp / ti);
    }

    // Cz�on r�niczkuj�cy
    double wyj_d = 0.0;
    if (td != 0.0) {
        wyj_d = kp * td * (blad - poprzedniBladaWart) / roznicaCzasu;
    }
    poprzedniBladaWart = blad;

    // Wynik sumaryczny
    double wyj = wyj_p + wyj_i + wyj_d;

    // Debugowanie wynik�w
    std::cout << "czas: " << czas
        << ", blad: " << blad
        << ", wyj_p: " << wyj_p
        << ", wyj_i: " << wyj_i
        << ", wyj_d: " << wyj_d
        << ", wyj: " << wyj << std::endl;

    return wyj;
}
