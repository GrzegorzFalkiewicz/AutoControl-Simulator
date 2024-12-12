#pragma once
#include "Generator.h"
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "SprzezenieZwrotne.h"

class UkladRegulacji {
private:
    Generator* generator;
    ModelARX* modelARX;
    RegulatorPID* regulatorPID;
    SprzezenieZwrotne* sprzezenieZwrotne;

public:
    UkladRegulacji(Generator* gen, ModelARX* model, RegulatorPID* regulator);

     ~UkladRegulacji();

    void setParametryRegulatora(double k, double ti, double td);
    void setParametryModelu(std::vector<double> wspA, std::vector<double> wspB, int opoznienie, double zaklocenie);
    void setParametryGeneratora(double amplituda, double okres, double wypelnienie);

    double getWartoscZadana(double czas, TypSygnalu typ);
};