// TU includy:

#include <iostream>
#include <iomanip>
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "ProstyUAR.h"

#define DEBUG  // ustaw na MAIN aby skompilować program docelowy / ustaw na DEBUG aby skompilować program testujacy 

#ifdef DEBUG

//Funkcje pomocnicze dla testów:

void raportBleduSekwencji(std::vector<double>& spodz, std::vector<double>& fakt)
{
	constexpr size_t PREC = 3;
	std::cerr << std::fixed << std::setprecision(PREC);
	std::cerr << "  Spodziewany:\t";
	for (auto& el : spodz)
		std::cerr << el << ", ";
	std::cerr << "\n  Faktyczny:\t";
	for (auto& el : fakt)
		std::cerr << el << ", ";
	std::cerr << std::endl << std::endl;
}

bool porownanieSekwencji(std::vector<double>& spodz, std::vector<double>& fakt)
{
	constexpr double TOL = 1e-3;	// tolerancja dla porównań zmiennoprzecinkowych
	bool result = fakt.size() == spodz.size();
	for (int i = 0; result && i < fakt.size(); i++)
		result = fabs(fakt[i] - spodz[i]) < TOL;
	return result;
}

void test_UAR_1_brakPobudzenia()
{
	//Sygnatura testu:
	std::cerr << "UAR_1 -> test zerowego pobudzenia: ";
	try
	{
		// Przygotowanie danych:
		RegulatorPID testPID(0.5, 5.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 });
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja UAR:

		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		myAssert(spodzSygWy, faktSygWy);
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_UAR_1_skokJednostkowy()
{
	//Sygnatura testu:
	std::cerr << "UAR_1 -> test skoku jednostkowego: ";
	try
	{
		// Przygotowanie danych:
		RegulatorPID testPID(0.5, 5.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 });
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.0, 0.54, 0.756, 0.6708, 0.64008, 0.729, 0.810437, 0.834499,
			           0.843338, 0.8664, 0.8936, 0.911886, 0.923312, 0.93404, 0.944929,
			           0.954065, 0.961042, 0.966815, 0.971965, 0.97642, 0.980096, 0.983143,
			           0.985741, 0.987964, 0.989839, 0.991411, 0.992739, 0.993865, 0.994818 
		             };

		// Symulacja UAR:

		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		myAssert(spodzSygWy, faktSygWy);
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_UAR_2_skokJednostkowy()
{
	//Sygnatura testu:
	std::cerr << "UAR_2 (k = 2) -> test skoku jednostkowego: ";
	try
	{
		// Przygotowanie danych:
		RegulatorPID testPID(0.5, 5.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 }, 2);
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.0, 0.0, 0.54, 0.756, 0.9624, 0.87336, 0.841104, 0.771946, 0.821644,
			           0.863453, 0.93272, 0.952656, 0.965421, 0.954525, 0.955787, 0.957472,
			           0.969711, 0.978075, 0.985968, 0.987821, 0.989149, 0.989053, 0.990645,
			           0.992248, 0.994403, 0.995707, 0.996677, 0.997024, 0.997388
		             };
		// Symulacja UAR:

		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		myAssert(spodzSygWy, faktSygWy);
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_UAR_3_skokJednostkowy()
{
	//Sygnatura testu:
	std::cerr << "UAR_3 (kP=1.0,Ti=2.0) -> test skoku jednostkowego: ";
	try
	{
		// Przygotowanie danych:
		RegulatorPID testPID(1.0, 2.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 }, 1);
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.0, 1.02, 1.608, 1.1028, 0.41736, 0.546648, 1.20605, 1.43047,
			           0.999176, 0.615056, 0.799121, 1.21304, 1.26025, 0.939289, 0.748507,
			           0.927166, 1.17292, 1.14155, 0.921616, 0.843258, 0.990018, 1.12577,
			           1.068, 0.927024, 0.908125, 1.01702, 1.08484, 1.02618, 0.941508
		             };
		// Symulacja UAR:

		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		myAssert(spodzSygWy, faktSygWy);
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}


int main()
{
	test_UAR_1_brakPobudzenia();
	test_UAR_1_skokJednostkowy();
	test_UAR_2_skokJednostkowy();
	test_UAR_3_skokJednostkowy();
}

#endif


#ifdef MAIN


int main()
{
	//Twój program
}

#endif

