#include <iostream>
#include <vector>
#include <cassert>
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"
#include "SprzezenieZwrotne.h"
#include "UkladRegulacji.h"

void testModelARX() {
    std::vector<double> wspA = { -0.8 };  // Wzmocnienie zmniejszone dla stabilnoœci
    std::vector<double> wspB = { 0.2 };
    ModelARX model(wspA, wspB, 1);
    double wynik = model.symuluj(1.0);
    assert(wynik == 0.0);
    std::cout << "Test ModelARX przeszedl pomyslnie." << std::endl;
}

void testRegulatorPID() {
    RegulatorPID regulator(0.2, 5.0, 0.01);  // Zmniejszone K, zwiêkszone Ti, zmniejszone Td
    double wynik = regulator.symuluj(0.5);
    assert(wynik != 0.0);
    std::cout << "Test RegulatorPID przeszedl pomyslnie." << std::endl;
}

void testGenerator() {
    Generator generator(TypSygnalu::SkokJednostkowy, 1.0, 10, 0.5, 2);
    double wynik = generator.generuj(3);
    assert(wynik == 1.0);
    std::cout << "Test Generator przeszedl pomyslnie." << std::endl;
}

void testSprzezenieZwrotne() {
    std::vector<double> wspA = { -0.8 };
    std::vector<double> wspB = { 0.2 };
    ModelARX model(wspA, wspB, 1);
    RegulatorPID regulator(0.2, 5.0, 0.01);
    Generator generator(TypSygnalu::SkokJednostkowy, 1.0, 10, 0.5, 2);
    SprzezenieZwrotne petla(&model, &regulator, &generator);
    double wynik = petla.symuluj(3);
    assert(wynik != 0.0);
    std::cout << "Test SprzezenieZwrotne przeszedl pomyslnie." << std::endl;
}

void testWartosciZadaneIOczekiwane() {
    std::vector<double> wspA = { -0.8 };
    std::vector<double> wspB = { 0.2 };
    UkladRegulacji uklad(wspA, wspB, 1, 0.2, 5.0, 0.01, TypSygnalu::Prostokatny, 1.0, 10, 0.5, 2);

    std::cout << "Krok | Wartoœæ zadana | Wartoœæ modelu | Wartoœæ regulacji" << std::endl;
    for (int krok = 0; krok < 1000; ++krok) {
        double wartoscZadana = uklad.getGenerator().generuj(krok);
        double wartoscModelu = uklad.getModel().symuluj(wartoscZadana);
        double uchyb = wartoscZadana - wartoscModelu;
        double sterowanie = uklad.getRegulator().symuluj(uchyb);
        double wartoscRegulacji = uklad.getModel().symuluj(sterowanie);

        std::cout << krok << "     | " << wartoscZadana << "            | " << wartoscModelu << "            | " << wartoscRegulacji << std::endl;
    }
}

int main() {
    try {
        testModelARX();
        testRegulatorPID();
        testGenerator();
        testSprzezenieZwrotne();
        testWartosciZadaneIOczekiwane();
        std::cout << "Wszystkie testy jednostkowe przebiegly pomyslnie." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Blad podczas testow: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Nieznany blad podczas testow." << std::endl;
        return 1;
    }
    return 0;
}
