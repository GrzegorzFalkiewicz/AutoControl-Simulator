#include "Symuluj.h"
#include <iostream>

int main() {
    try {
        Symuluj symulacja;

        // Konfiguracja układu regulacji
        symulacja.konfiguruj(0.1, 0.01, 0.05, { 1.0, -0.5 }, { 0.2, 0.1 }, 2, 1.0, 2.0, 0.5);

        // Ustawienie parametrów symulacji
        symulacja.ustawParametrySymulacji(0.1, 100);

        // Uruchomienie symulacji
        symulacja.uruchom();
    }
    catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << std::endl;
    }
    return 0;
}
