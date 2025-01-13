#pragma once

#include <vector>
#include <deque>

class ModelARX {
private:
    double zaklocenie = 0.0;
    int opoznienie;
    std::vector<double> wspolczynnikA;
    std::vector<double> wspolczynnikB;
    std::deque<double> bufforWyj;
    std::deque<double> bufforWej;

public:
    ModelARX(std::vector<double> wspA, std::vector<double> wspB, int opoznienie = 0);
    double symuluj(double wejscie);
    ~ModelARX();
};