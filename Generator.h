#pragma once
#include <cmath>

class Generator {
private:
    double amplituda;
    double okres;
    double czas;
    double wypelnienie; // dla sygna�u prostok�tnego

public:
    enum TypSygna�u { SKOK, SINUS, PROSTOKAT };

    Generator(double amplituda = 1.0, double okres = 1.0, double wypelnienie = 0.5);
    double generuj(TypSygna�u typ, double czas);

    // Ustawienia generatora
    void ustawAmplitude(double amp);
    void ustawOkres(double okr);
    void ustawWypelnienie(double wyp);
};