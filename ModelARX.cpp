#include "ModelARX.h"
#include <stdexcept>

ModelARX::ModelARX(std::vector<double> wspA, std::vector<double> wspB, int Opozninie, double Zaklocenie)
    : Zaklocenie(Zaklocenie), Opozninie(Opozninie), WspolcznynnikA(wspA), WspolczynnikB(wspB)  {
    BufforWyj = std::deque<double>(wspA.size() + Opozninie, 0.0); // Inicjalizacja bufora wyjœciowego z opóŸnieniem
    BufforWej = std::deque<double>(wspB.size() + Opozninie, 0.0); // Inicjalizacja bufora wejœciowego z opóŸnieniem
}

double ModelARX::symuluj(double input) {
    // Aktualizacja bufora wejœciowego
    BufforWej.push_front(input);
    BufforWej.pop_back();

    double output = 0.0;

    // Obliczenie odpowiedzi systemu
    for (size_t i = 0; i < WspolczynnikB.size(); i++) {
        output += WspolczynnikB[i] * BufforWej[i + Opozninie]; // Uwzglêdnienie opóŸnienia
    }
    for (size_t i = 0; i < WspolcznynnikA.size(); i++) {
        output -= WspolcznynnikA[i] * BufforWyj[i]; // Uwzglêdnienie opóŸnienia
    }

    // Aktualizacja bufora wyjœciowego
    BufforWyj.push_front(output);
    BufforWyj.pop_back();

    return output;
}

ModelARX::~ModelARX() {
    // Opcjonalne czyszczenie zasobów
}