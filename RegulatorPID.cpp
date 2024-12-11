#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double kp, double ti, double td)
    : kp(kp), ti(ti), td(td), akumulator(0.0), poprzedniBladaWart(0.0) {}

double RegulatorPID::symuluj(double wejscie) {
    double blad = wejscie;
    double roznicaCzasu = 1.0; // 1Hz

    // Człon proporcjonalny
    double wyj_p = kp * blad;

    // Człon calkujący
    double wyj_i = 0.0;
    if (ti != 0.0) {
        akumulator += blad * roznicaCzasu; //akumulacja bledu
        wyj_i = akumulator * (kp / ti);
    }

    // Człon rozniczkujący
    double wyj_d = 0.0;
        wyj_d = kp * td * (blad - poprzedniBladaWart) / roznicaCzasu;
        poprzedniBladaWart = blad;

    // Wynik sumaryczny
    double wyj = wyj_p + wyj_i + wyj_d;

    // Wartosci do debugowania
    std::cout << std::endl << "blad: " << blad
        << ", wyj_p: " << wyj_p
        << ", wyj_i: " << wyj_i
        << ", wyj_d: " << wyj_d
        << ", wyj: " << wyj << std::endl;

    return wyj;
}
