#include "SprzezenieZwrotne.h"
#include <iostream>

SprzezenieZwrotne::SprzezenieZwrotne(RegulatorPID* regulator, double wartoscZadana)
    : regulator(regulator), wartoscZadana(wartoscZadana), wartoscMierzona(0.0) {}

void SprzezenieZwrotne::ustawWartoscZadana(double wartosc) {
    wartoscZadana = wartosc;
}

double SprzezenieZwrotne::pobierzWartoscZadana() const {
    return wartoscZadana;
}

double SprzezenieZwrotne::symuluj(double nowaWartoscMierzona, double czas) {
    wartoscMierzona = nowaWartoscMierzona;
    double blad = wartoscZadana - wartoscMierzona;
    return regulator->symuluj(blad); // Poprawiono liczbê argumentów
}