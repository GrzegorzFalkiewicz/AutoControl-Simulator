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
    std::default_random_engine generator;
    std::normal_distribution<double> zaklocenie;
public:
    ModelARX(std::vector<double> wspA, std::vector<double> wspB, int opoznienie = 0);
    ~ModelARX();

    double symuluj(double wejscie);

    void setWspA(const std::vector<double>& noweA);
    void setWspB(const std::vector<double>& noweB);
    void setOpoznienie(int noweOpoznienie);

    std::vector<double> getWspA() const;
    std::vector<double> getWspB() const;
    int getOpoznienie() const;
};
