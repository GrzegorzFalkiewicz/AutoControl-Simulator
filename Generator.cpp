#include "Generator.h"

Generator::Generator(double amplituda, double okres, double wypelnienie)
    : amplituda(amplituda), okres(okres), czas(0.0), wypelnienie(wypelnienie) {}

void Generator::ustawAmplitude(double amp) {
    amplituda = amp;
}

void Generator::ustawOkres(double okr) {
    okres = okr;
}

void Generator::ustawWypelnienie(double wyp) {
    wypelnienie = wyp;
}

double Generator::generuj(TypSygna�u typ, double czas) {
    switch (typ) {
    case SKOK:
        return amplituda; // Skok jednostkowy jest sta�y
    case SINUS:
        return amplituda * sin(2 * 3.14 * czas / okres);
    case PROSTOKAT:
        return (fmod(czas, okres) < wypelnienie * okres) ? amplituda : 0.0;
    default:
        return 0.0;
    }
}