#pragma once
class RegulatorPID {
private:
    double kp, ti, td;
    double integralna;
    double poprzedniaBladaTime, poprzedniaBladaWart;
public:
    RegulatorPID(double kp, double ti = 0.0, double td = 0.0);
    double symuluj(double wejscie);
};
