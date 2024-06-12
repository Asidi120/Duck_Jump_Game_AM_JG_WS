#pragma once
#include "Gra.h"
#include "Graj.h"
class Kaczuszka;
class Animacja
{
public:
	int ilosc_obrazkow=3, wysokosc_obrazka=23, szerokosc_obrazka=17;
	int aktualna_klatka{};
	Clock czas_zmiany;
	Animacja();
	virtual ~Animacja();
	bool czy_zmienic(Graj& graj);
};

