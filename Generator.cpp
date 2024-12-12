#include "Generator.h"

Generator::Generator(double amplituda, double okres, double wypelnienie)
    : amplituda(amplituda), okres(okres), czas(0.0), wypelnienie(wypelnienie) {}

void Generator::setAmplituda(double amp) {
    amplituda = amp;
}

void Generator::setOkres(double okr) {
    okres = okr;
}

void Generator::setWypelnienie(double wyp) {
    wypelnienie = wyp;
}

double Generator::Generuj(TypSygnalu typ, double czas) {
    switch (typ) {
    case SKOK:
        return amplituda; 
    case SINUS:
        return amplituda * sin(2 * 3.14 * czas / okres);
    }
   //case PROSTOKAT:
}