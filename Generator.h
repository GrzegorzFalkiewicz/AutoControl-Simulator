#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <deque>

enum class TypSygnalu {
    SkokJednostkowy,
    Prostokatny,
    Sinusoidalny
};

class Generator {
private:
    TypSygnalu typ;
    double amplituda;
    double okres;
    double wypelnienie;
    int czasAktywacji;

public:
    Generator(TypSygnalu typ, double amplituda, double okres = 1.0, double wypelnienie = 0.5, int czasAktywacji = 0);
    double generuj(int krok);
};
