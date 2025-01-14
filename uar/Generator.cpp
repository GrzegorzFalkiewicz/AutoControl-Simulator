#include "Generator.h"

Generator::Generator(TypSygnalu typ, double amplituda, double okres, double wypelnienie, int czasAktywacji)
    : typ(typ), amplituda(amplituda), okres(okres), wypelnienie(wypelnienie), czasAktywacji(czasAktywacji) {
}

double Generator::generuj(int krok) {
    switch (typ) {
    case TypSygnalu::SkokJednostkowy:
        return krok >= czasAktywacji ? amplituda : 0.0;

    case TypSygnalu::Prostokatny:
        return ((krok % static_cast<int>(okres)) < (wypelnienie * okres)) ? amplituda : 0.0;

    case TypSygnalu::Sinusoidalny:
        return amplituda * sin(2 * M_PI * krok / okres);

    default:
        return 0.0;
    }
}
