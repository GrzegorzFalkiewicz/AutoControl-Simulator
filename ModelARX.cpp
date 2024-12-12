#include "ModelARX.h"
#include <stdexcept>

ModelARX::ModelARX(std::vector<double> wspA, std::vector<double> wspB, int Opozninie, double Zaklocenie)
    : Zaklocenie(Zaklocenie), Opozninie(Opozninie), WspolcznynnikA(wspA), WspolczynnikB(wspB) {
    BufforWyj = std::deque<double>(wspA.size() + Opozninie, 0.0); // Inicjalizacja bufora wyj�ciowego z op�nieniem
    BufforWej = std::deque<double>(wspB.size() + Opozninie, 0.0); // Inicjalizacja bufora wej�ciowego z op�nieniem
}

double ModelARX::symuluj(double input) {
    // Aktualizacja bufora wej�ciowego
    BufforWej.push_front(input);
    BufforWej.pop_back();

    double output = 0.0;

    // Obliczenie odpowiedzi systemu
    for (size_t i = 0; i < WspolczynnikB.size(); i++) {
        output += WspolczynnikB[i] * BufforWej[i + Opozninie]; // Uwzgl�dnienie op�nienia
    }
    for (size_t i = 0; i < WspolcznynnikA.size(); i++) {
        output -= WspolcznynnikA[i] * BufforWyj[i]; // Uwzgl�dnienie op�nienia
    }

    // Aktualizacja bufora wyj�ciowego
    BufforWyj.push_front(output);
    BufforWyj.pop_back();

    return output;
}

ModelARX::~ModelARX() {
    // Opcjonalne czyszczenie zasob�w
}