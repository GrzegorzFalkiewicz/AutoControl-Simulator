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
    Generator(TypSygnalu typ, double amplituda, double okres, double wypelnienie, int czasAktywacji);
    double generuj(int krok);
    void setAmplituda(double nowaAmplituda);
    void setOkres(double nowyOkres);
    void setWypelnienie(double noweWypelnienie);
    void setTypSygnalu(TypSygnalu nowyTyp);
    double getAmplituda() const;
    double getOkres() const;
    double getWypelnienie() const;
    TypSygnalu getTypSygnalu() const;
};
