#include "ModelARX.h"
#include <stdexcept>

ModelARX::ModelARX(std::vector<double> wspA, std::vector<double> wspB, int Opozninie, double Zaklocenie)
    : Zaklocenie(Zaklocenie), Opozninie(Opozninie), WspolczynnikA(wspA), WspolczynnikB(wspB) {
    BufforWyj = std::deque<double>(wspA.size() + Opozninie, 0.0); // Inicjalizacja buforu wyj
    BufforWej = std::deque<double>(wspB.size() + Opozninie, 0.0); // Inicjalizacja buforu wej
}

double ModelARX::symuluj(double wejscie) {
    // Aktualizacja buforu wej
    BufforWej.push_front(wejscie);
    BufforWej.pop_back();

    double wyjscie = 0.0;

    // Obliczenie odpowiedzi systemu
    for (size_t i = 0; i < WspolczynnikB.size(); i++) {
        wyjscie += WspolczynnikB[i] * BufforWej[i + Opozninie]; 
    }
    for (size_t i = 0; i < WspolczynnikA.size(); i++) {
        wyjscie -= WspolczynnikA[i] * BufforWyj[i]; 
    }

    // Aktualizacja buforu wyj
    BufforWyj.push_front(wyjscie);
    BufforWyj.pop_back();

    return wyjscie;
}

ModelARX::~ModelARX() {
}