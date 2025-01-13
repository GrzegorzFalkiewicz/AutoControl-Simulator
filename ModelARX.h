#pragma once

#include <vector>
#include <deque>
#include <random>

class ModelARX {
private:
    int opoznienie;
    std::vector<double> wspolczynnikA;
    std::vector<double> wspolczynnikB;
    std::deque<double> bufforWyj;
    std::deque<double> bufforWej;
    std::default_random_engine generator;  // Generator losowy
    std::normal_distribution<double> zaklocenie;  // Zak³ócenie

public:
    ModelARX(std::vector<double> wspA, std::vector<double> wspB, int opoznienie = 0);
    double symuluj(double wejscie);
    ~ModelARX();
};