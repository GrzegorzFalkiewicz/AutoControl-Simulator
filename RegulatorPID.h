#pragma once
class RegulatorPID {
private:
    double kp, ti, td;
    double akumulator;
    double poprzedniBladaWart;
public:
    RegulatorPID(double kp, double ti = 0.0, double td = 0.0);
    double symuluj(double wejscie);
};
