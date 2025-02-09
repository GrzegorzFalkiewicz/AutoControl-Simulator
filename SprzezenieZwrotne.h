#pragma once

#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"

class SprzezenieZwrotne {
private:
    ModelARX* model;
    RegulatorPID* regulator;
    Generator* generator;
    double poprzedniaWartosc;
public:
    SprzezenieZwrotne(ModelARX* model, RegulatorPID* regulator, Generator* generator);
    double symuluj(int krok);
    void reset();
};
