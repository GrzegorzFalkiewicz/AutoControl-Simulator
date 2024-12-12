#include "SprzezenieZwrotne.h"

SprzezenieZwrotne::SprzezenieZwrotne(ModelARX* model, RegulatorPID* regulator, Generator* wartoscZadana)
    : model(model), regulator(regulator), WartoscZadana(wartoscZadana) {}

double SprzezenieZwrotne::symuluj(double czas) {
    // Pomiar wartosci mierzonej (y_i)
    double wartoscMierzona = model->symuluj(0.0); // Zak³adamy brak zak³óceñ wejœciowych

    // Obliczenie uchybu regulacji (e_i = w_i - y_i)
    double wartoscZadana = WartoscZadana->Generuj(TypSygnalu::SKOK,czas);
    double uchyb = wartoscZadana - wartoscMierzona;

    // Obliczenie odpowiedzi regulatora (u_i)
    double sterowanie = regulator->symuluj(uchyb, czas);

    // Podanie odpowiedzi regulatora jako wejœcia do modelu (ARX)
    double wyjscie = model->symuluj(sterowanie);

    return wyjscie;
}

void SprzezenieZwrotne::setWartoscZadana(Generator* nowaWartoscZadana) {
    WartoscZadana = nowaWartoscZadana;
}