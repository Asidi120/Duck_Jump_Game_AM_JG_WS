#pragma once
#include "Gra.h"
#include "Graj.h"
class Kaczuszka;
class Animacja
{
public:
	int aktualna_klatka_tlo{};
	int ilosc_obrazkow_tlo = 180, wysokosc_obrazka_tlo = 10;
	int ilosc_obrazkow=3, wysokosc_obrazka=23, szerokosc_obrazka=17;
	int i{};
	int aktualna_klatka{};
	Clock czas_zmiany;
	Animacja();
	virtual ~Animacja();
	bool czy_zmienic(Graj& graj);
};

