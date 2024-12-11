#include "ModelARX.h"
#include <stdexcept>

ModelARX::ModelARX(std::vector<double> wspA, std::vector<double> wspB, int Opozninie, double Zaklocenie)
    : Zaklocenie(Zaklocenie), Opozninie(Opozninie), WspolcznynnikA(wspA), WspolczynnikB(wspB)  {
    BufforWyj = std::deque<double>(wspA.size() + Opozninie, 0.0); // Inicjalizacja bufora wyjściowego z opóźnieniem
    BufforWej = std::deque<double>(wspB.size() + Opozninie, 0.0); // Inicjalizacja bufora wejściowego z opóźnieniem
}

double ModelARX::symuluj(double input) {
    // Aktualizacja bufora wejściowego
    BufforWej.push_front(input);
    BufforWej.pop_back();

    double output = 0.0;

    // Obliczenie odpowiedzi systemu
    for (size_t i = 0; i < WspolczynnikB.size(); i++) {
        output += WspolczynnikB[i] * BufforWej[i + Opozninie]; // Uwzględnienie opóźnienia
    }
    for (size_t i = 0; i < WspolcznynnikA.size(); i++) {
        output -= WspolcznynnikA[i] * BufforWyj[i]; // Uwzględnienie opóźnienia
    }

    // Aktualizacja bufora wyjściowego
    BufforWyj.push_front(output);
    BufforWyj.pop_back();

    return output;
}

ModelARX::~ModelARX() {
    // Opcjonalne czyszczenie zasobów
}