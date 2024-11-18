// TU includy:

#include <iostream>
#include <iomanip>
#include "ModelARX.h"

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

void test_ModelARX_brakPobudzenia()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test zerowego pobudzenia: ";
	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 1, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy
	
		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);
	
		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy,faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_ModelARX_skokJednostkowy_1()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test skoku jednostkowego nr 1: ";

	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 1, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy 
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0.6, 0.84, 0.936, 0.9744, 0.98976, 0.995904, 0.998362, 0.999345, 0.999738, 0.999895, 0.999958, 0.999983, 0.999993, 0.999997, 0.999999, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_ModelARX_skokJednostkowy_2()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4 | 0.6 | 2 | 0 ) -> test skoku jednostkowego nr 2: ";

	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 2, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu, 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0, 0.6, 0.84, 0.936, 0.9744, 0.98976, 0.995904, 0.998362, 0.999345, 0.999738, 0.999895, 0.999958, 0.999983, 0.999993, 0.999997, 0.999999, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_ModelARX_skokJednostkowy_3()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4, 0.2 | 0.6, 0.3 | 2 | 0 ) -> test skoku jednostkowego nr 3: ";
	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4,0.2 }, { 0.6, 0.3 }, 2, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu, 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0, 0.6, 1.14, 1.236, 1.1664, 1.11936, 1.11446, 1.12191, 1.12587, 1.12597, 1.12521, 1.12489, 1.12491, 1.12499, 1.12501, 1.12501, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Weryfikacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

int main()
{
	test_ModelARX_brakPobudzenia();
	test_ModelARX_skokJednostkowy_1();
	test_ModelARX_skokJednostkowy_2();
	test_ModelARX_skokJednostkowy_3();
}

#endif


#ifdef MAIN


int main()
{
	//Twój program
}

#endif

