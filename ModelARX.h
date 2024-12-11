#include <vector>
#include <deque>

class ModelARX {
private:
    double Zaklocenie; //Zaklocenie
    int Opozninie; // OpóŸnienie systemu
    std::vector<double> WspolcznynnikA; // Wspó³czynniki A
    std::vector<double> WspolczynnikB; // Wspó³czynniki B
    std::deque<double> BufforWyj; // Bufor dla sygna³u wyjœciowego
    std::deque<double> BufforWej; // Bufor dla sygna³u wejœciowego

public:
    ModelARX(std::vector<double> wspA, std::vector<double> wspB, int Opozninie, double Zaklocenie);
    double symuluj(double input);
    ~ModelARX();
};