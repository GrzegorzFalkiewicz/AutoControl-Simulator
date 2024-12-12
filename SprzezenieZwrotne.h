#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"

class SprzezenieZwrotne {
private:
    ModelARX* model;
    RegulatorPID* regulator;
    Generator* WartoscZadana; 

public:
    // Konstruktor
    SprzezenieZwrotne(ModelARX* model, RegulatorPID* regulator, Generator* wartoscZadana);

    // Metoda symulacji jednego kroku uk³adu
    double symuluj(double czas);

    // Ustawienie nowej wartosci zadanej
    void setWartoscZadana(Generator* nowaWartoscZadana);
};