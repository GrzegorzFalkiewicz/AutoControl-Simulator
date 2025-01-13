#include "Generator.h"

Generator::Generator(TypSygnalu typ, double amplituda, double okres, double wypelnienie, int czasAktywacji)
    : typ(typ), amplituda(amplituda), okres(okres), wypelnienie(wypelnienie), czasAktywacji(czasAktywacji) {
}

double Generator::generuj(int krok) {
    if (typ == TypSygnalu::SkokJednostkowy) {
        if (krok >= czasAktywacji) {
            return amplituda;
        }
        else {
            return 0.0;
        }
    }
    else if (typ == TypSygnalu::Prostokatny) {
        if ((krok % static_cast<int>(okres)) < (wypelnienie * okres)) {
            return amplituda;
        }
        else {
            return 0.0;
        }
    }
    else if (typ == TypSygnalu::Sinusoidalny) {
        return amplituda * sin(2 * 3.14 * krok / okres);
    }
    else {
        return 0.0;
    }
}
