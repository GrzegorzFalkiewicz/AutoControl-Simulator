#pragma once
class RegulatorPID {
public:
    RegulatorPID(double kp, double ti = 0.0, double td = 0.0);
    double symuluj(double wejscie);

private:
    double kp, ti, td;
    double integralna;
    double poprzedniaBladaTime, poprzedniaBladaWart;
};