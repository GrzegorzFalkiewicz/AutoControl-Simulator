#pragma once

class RegulatorPID {
private:
    double kp, ti, td;
    double akumulator;
    double poprzedniBladaWart;
    double ostatniCzas;

public:
    RegulatorPID(double kp, double ti = 0.0, double td = 0.0);
    double symuluj(double blad, double czas); // Funkcja symuluj z poprawnym krokiem czasu
};