#pragma once

#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"

class SprzezenieZwrotne {
private:
    ModelARX* model;
    RegulatorPID* regulator;
    Generator* generator;
public:
    SprzezenieZwrotne(ModelARX* model, RegulatorPID* regulator, Generator* generator);
    double symuluj(int krok);
};
