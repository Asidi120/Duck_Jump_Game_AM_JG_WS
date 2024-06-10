#pragma once
#include "Gra.h"
#include "Graj.h"
class Kaczuszka;
class Animacja
{
public:
	float czas_zmiany=0.f;
	const int ilosc_obrazkow=6, wysokosc_obrazka=30, szerokosc_obrazka=20;
	int i{};
	Animacja();
	virtual ~Animacja();
	bool czy_zmienic(Graj& graj);
};

