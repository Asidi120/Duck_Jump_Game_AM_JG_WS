#pragma once
#include "Gra.h"
#include "Graj.h"
class Kaczuszka;
class Animacja
{
public:
	const int ilosc_obrazkow=3, wysokosc_obrazka=24, szerokosc_obrazka=20;
	int i{};
	int aktualna_klatka{};
	Clock czas_zmiany;
	Animacja();
	virtual ~Animacja();
	bool czy_zmienic(Graj& graj);
};

