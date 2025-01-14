#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double k, double ti, double td)
    : k(k), ti(ti), td(td), suma_uchybu(0.0), poprzedniBladaWart(0.0) {}

double RegulatorPID::symuluj(double blad) {
    double wyj_p = k * blad;

    double wyj_i = 0.0;
    if (ti != 0.0) {
        suma_uchybu += blad;

        // Ograniczenie całkowania (anti-windup)
        if (suma_uchybu > 100.0) suma_uchybu = 100.0;
        if (suma_uchybu < -100.0) suma_uchybu = -100.0;

        wyj_i = suma_uchybu / ti;
    }

    double wyj_d = td * (blad - poprzedniBladaWart);
    poprzedniBladaWart = blad;

    return wyj_p + wyj_i + wyj_d;
}
