#include "ModelARX.h"

ModelARX::ModelARX(std::vector<double> wspA, std::vector<double> wspB, int opoznienie)
    : opoznienie(opoznienie), wspolczynnikA(wspA), wspolczynnikB(wspB) {
    bufforWyj = std::deque<double>(wspA.size() + opoznienie, 0.0);
    bufforWej = std::deque<double>(wspB.size() + opoznienie, 0.0);
}

double ModelARX::symuluj(double wejscie) {
    bufforWej.push_front(wejscie);
    bufforWej.pop_back();

    double wyjscie = 0.0;

    for (size_t i = 0; i < wspolczynnikB.size(); i++) {
        wyjscie += wspolczynnikB[i] * bufforWej[i + opoznienie];
    }
    for (size_t i = 0; i < wspolczynnikA.size(); i++) {
        wyjscie -= wspolczynnikA[i] * bufforWyj[i];
    }

    bufforWyj.push_front(wyjscie);
    bufforWyj.pop_back();

    return wyjscie;
}

ModelARX::~ModelARX() {}