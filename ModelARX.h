#pragma once
#include <vector>
#include <deque>

class ModelARX {
private:
    double Zaklocenie; //Zaklocenie
    int Opozninie; // Op�nienie systemu
    std::vector<double> WspolcznynnikA; // Wsp�czynniki A
    std::vector<double> WspolczynnikB; // Wsp�czynniki B
    std::deque<double> BufforWyj; // Bufor dla sygna�u wyj�ciowego
    std::deque<double> BufforWej; // Bufor dla sygna�u wej�ciowego

public:
    ModelARX(std::vector<double> wspA, std::vector<double> wspB, int Opozninie, double Zaklocenie);
    double symuluj(double input);
    ~ModelARX();
};
