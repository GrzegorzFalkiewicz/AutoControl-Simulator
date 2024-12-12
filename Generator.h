#pragma once
#include <cmath>

enum TypSygnalu { 
    SKOK, 
    SINUS, 
    PROSTOKAT 
};

class Generator {
private:
    double amplituda;
    double okres;
    double czas;
    double wypelnienie; // dla sygna�u prostok�tnego
   
public:
    

    Generator(double amplituda = 1.0, double okres = 1.0, double wypelnienie = 0.5);
    double Generuj(TypSygnalu typ, double czas);

    // Ustawienia generatora
    void setAmplituda(double amp);
    void setOkres(double okr);
    void setWypelnienie(double wyp);
};