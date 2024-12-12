#pragma once

const double suma_uchybu = 0.0;
class RegulatorPID {
private:
    double k, ti, td;
    double suma_uchybu;
    double poprzedniBladaWart;
    double ostatniCzas;

public:
    RegulatorPID(double k, double ti = 0.0, double td = 0.0);
    double symuluj(double blad, double czas); 
};