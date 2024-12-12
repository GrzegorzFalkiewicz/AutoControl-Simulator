#pragma once
#include "RegulatorPID.h"

class SprzezenieZwrotne {
private:
    RegulatorPID* regulator;
    double wartoscZadana;
    double wartoscMierzona;

public:
    SprzezenieZwrotne(RegulatorPID* regulator, double wartoscZadana);
    void ustawWartoscZadana(double wartosc);
    double pobierzWartoscZadana() const;
    double symuluj(double nowaWartoscMierzona, double czas);
};