#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double k, double ti, double td)
    : k(k), ti(ti), td(td), suma_uchybu(0.0), poprzedniBladaWart(0.0) {}

double RegulatorPID::symuluj(double blad) {
    double wyj_p = k * blad;

    double wyj_i = 0.0;
    const double I_MAX = 20.0;
    const double I_MIN = -20;

    if (ti != 0.0) {
        suma_uchybu += blad;
        if (suma_uchybu > I_MAX) suma_uchybu = I_MAX;
        if (suma_uchybu < I_MIN) suma_uchybu = I_MIN;
        wyj_i = suma_uchybu / ti;
    }

    double wyj_d = td * (blad - poprzedniBladaWart);
    poprzedniBladaWart = blad;

    return wyj_p + wyj_i + wyj_d;
}
double RegulatorPID::symulujProporcjonalny(double blad) {
    return k * blad;
}

double RegulatorPID::symulujCalkujacy(double blad) {
    if (ti != 0.0) {
        suma_uchybu += blad;
        return suma_uchybu / ti;
    }
    return 0.0;
}

double RegulatorPID::symulujRozniczkujacy(double blad) {
    double wyj_d = td * (blad - poprzedniBladaWart);
    poprzedniBladaWart = blad;
    return wyj_d;
}
