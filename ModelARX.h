#pragma once
#include <vector>
#include <deque>

class ModelARX {
private:
    double Zaklocenie; 
    int Opozninie; 
    std::vector<double> WspolczynnikA; 
    std::vector<double> WspolczynnikB; 
    std::deque<double> BufforWyj; 
    std::deque<double> BufforWej; 

public:
    ModelARX(std::vector<double> wspA, std::vector<double> wspB, int Opozninie, double Zaklocenie);
    double symuluj(double wejscie);
    ~ModelARX();
};
