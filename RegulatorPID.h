#pragma once

const double suma_uchybu = 0.0;
class RegulatorPID {
private:
    double k, ti, td;
    double suma_uchybu;
    double poprzedniBladaWart;

public:
    RegulatorPID(double k, double ti = 0.0, double td = 0.0);
    double symuluj(double blad);
    double symulujProporcjonalny(double blad);
    double symulujCalkujacy(double blad);
    double symulujRozniczkujacy(double blad);
    void resetujCzlonCalkujacy();
    void resetujCzlonRozniczkujacy();
};
