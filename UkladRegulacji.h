#pragma once
#include "RegulatorPID.h"
#include "SprzezenieZwrotne.h"
#include "Generator.h"
#include "ModelARX.h"

class UkladRegulacji {
private:
    RegulatorPID regulator;
    ModelARX model;
    SprzezenieZwrotne sprzezenieZwrotne;
    Generator generator;
    double czas;
    double wyjscieModelu; // Ostatnie wyjœcie modelu ARX

public:
    UkladRegulacji(double kp, double ti, double td, const std::vector<double>& a, const std::vector<double>& b, int opoznienie, double amplituda, double okres, double wypelnienie);
    void krokSymulacji(double dt);
    double pobierzWyjscieModelu() const;
};