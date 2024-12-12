#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double k, double ti, double td)
    : k(k), ti(ti), td(td), suma_uchybu(0.0), poprzedniBladaWart(0.0), ostatniCzas(0.0) {}

double RegulatorPID::symuluj(double blad, double czas) {
    double roznicaCzasu = 0.0;
    if (czas != ostatniCzas)
    {
        double roznicaCzasu = (czas - ostatniCzas);
    }
    else {
        roznicaCzasu = 1.0; //1.0 jesli czas sie nie zmienia
    };
    ostatniCzas = czas;

    // Czlon proporcjonalny
    double wyj_p = k * blad;

    // Cz³on calkujacy
    double wyj_i = 0.0;
    if (ti != 0.0) {
        suma_uchybu += blad;
        wyj_i = suma_uchybu/ti;
    }

    // Cz³on rozniczkujacy
    double wyj_d = 0.0;
    wyj_d = td * (blad - poprzedniBladaWart);
    poprzedniBladaWart = blad;

    double wyj = wyj_p + wyj_i + wyj_d;
    return wyj;
}
