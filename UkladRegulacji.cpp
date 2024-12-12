#include "UkladRegulacji.h"

UkladRegulacji::UkladRegulacji(Generator* gen, ModelARX* model, RegulatorPID* regulator)
    : generator(gen),
    modelARX(model),
    regulatorPID(regulator) {
    sprzezenieZwrotne = new SprzezenieZwrotne(modelARX, regulatorPID, generator);
}

UkladRegulacji::~UkladRegulacji() {
    delete sprzezenieZwrotne;
    delete generator;
    delete modelARX;
    delete regulatorPID;
}

void UkladRegulacji::setParametryRegulatora(double k, double ti, double td) {
    delete regulatorPID;
    regulatorPID = new RegulatorPID(k, ti, td);
    delete sprzezenieZwrotne;
    sprzezenieZwrotne = new SprzezenieZwrotne(modelARX, regulatorPID, generator);
}

void UkladRegulacji::setParametryModelu(std::vector<double> wspA, std::vector<double> wspB, int opoznienie, double zaklocenie) {
    delete modelARX;
    modelARX = new ModelARX(wspA, wspB, opoznienie, zaklocenie);
    delete sprzezenieZwrotne;
    sprzezenieZwrotne = new SprzezenieZwrotne(modelARX, regulatorPID, generator);
}

void UkladRegulacji::setParametryGeneratora(double amplituda, double okres, double wypelnienie) {
    generator->setAmplituda(amplituda);
    generator->setOkres(okres);
    generator->setWypelnienie(wypelnienie);
}

double UkladRegulacji::getWartoscZadana(double czas, TypSygnalu typ) {
    return generator->Generuj(typ, czas);
}