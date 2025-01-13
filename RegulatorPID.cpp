#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double k, double ti, double td)
    : k(k), ti(ti), td(td), suma_uchybu(0.0), poprzedniBladaWart(0.0) {}

double RegulatorPID::symuluj(double blad) {

    // Czlon proporcjonalny
    double wyj_p = k * blad;

    // Czlon calkujacy
    double wyj_i = 0.0;
    if (ti != 0.0) {
        suma_uchybu += blad;
        wyj_i = suma_uchybu / ti;
    }

    // Czlon rozniczkujacy
    double wyj_d = 0.0;
    wyj_d = td * (blad - poprzedniBladaWart);
    poprzedniBladaWart = blad;

    double wyj = wyj_p + wyj_i + wyj_d;
    return wyj;
}