#pragma once

#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"
#include "SprzezenieZwrotne.h"

class UkladRegulacji {
private:
    ModelARX model;
    RegulatorPID regulator;
    Generator generator;
    SprzezenieZwrotne petla;

public:
    UkladRegulacji(const std::vector<double>& wspA, const std::vector<double>& wspB, int opoznienie,
        double k, double ti, double td,
        TypSygnalu typSygnalu, double amplituda, double okres, double wypelnienie, int czasAktywacji);
    void symuluj(int liczbaKrokow);
    ModelARX& getModel();
    RegulatorPID& getRegulator();
    Generator& getGenerator();
};
