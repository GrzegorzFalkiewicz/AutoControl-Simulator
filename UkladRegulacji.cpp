#include "UkladRegulacji.h"
#include <iostream>

UkladRegulacji::UkladRegulacji(double kp, double ti, double td, const std::vector<double>& a, const std::vector<double>& b, int opoznienie, double amplituda, double okres, double wypelnienie)
    : regulator(kp, ti, td),
    model(a, b, opoznienie, 0.0), // Dodano parametr zak³ócenia
    sprzezenieZwrotne(&regulator, 0.0),
    generator(amplituda, okres, wypelnienie),
    czas(0.0),
    wyjscieModelu(0.0) {}

void UkladRegulacji::krokSymulacji(double dt) {
    czas += dt;

    // Generowanie wartoœci zadanej
    double wartoscZadana = generator.generuj(Generator::SINUS, czas);
    sprzezenieZwrotne.ustawWartoscZadana(wartoscZadana);

    // Symulacja modelu ARX
    double sygnalSterowania = sprzezenieZwrotne.symuluj(wyjscieModelu, czas);
    wyjscieModelu = model.symuluj(sygnalSterowania);

    // Debugowanie
    std::cout << "Czas: " << czas
        << ", Wartosc Zadana: " << wartoscZadana
        << ", Sterowanie: " << sygnalSterowania
        << ", Wyjscie Modelu: " << wyjscieModelu
        << std::endl;
}

double UkladRegulacji::pobierzWyjscieModelu() const {
    return wyjscieModelu;
}