#include "Generator.h"
#include "qmath.h"

Generator::Generator(TypSygnalu typ, double amplituda, double okres, double wypelnienie, int czasAktywacji)
    : typ(typ), amplituda(amplituda), okres(okres), wypelnienie(wypelnienie), czasAktywacji(czasAktywacji) {}

double Generator::generuj(int krok) {
    switch (typ) {
    case TypSygnalu::SkokJednostkowy:
        return (krok >= czasAktywacji) ? amplituda : 0.0;
    case TypSygnalu::Prostokatny:
        return ((krok % static_cast<int>(okres)) < (wypelnienie * okres)) ? amplituda : 0.0;
    case TypSygnalu::Sinusoidalny:
        return amplituda * sin(2 * M_PI * krok / okres);
    default:
        return 0.0;
    }
}

void Generator::setAmplituda(double nowaAmplituda) { amplituda = nowaAmplituda; }
void Generator::setOkres(double nowyOkres) { okres = nowyOkres; }
void Generator::setWypelnienie(double noweWypelnienie) { wypelnienie = noweWypelnienie; }
void Generator::setTypSygnalu(TypSygnalu nowyTyp) { typ = nowyTyp; }
double Generator::getAmplituda() const { return amplituda; }
double Generator::getOkres() const { return okres; }
double Generator::getWypelnienie() const { return wypelnienie; }
TypSygnalu Generator::getTypSygnalu() const { return typ; }
