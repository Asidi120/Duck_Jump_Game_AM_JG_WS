#pragma once
#include "Gra.h"
#define Ilosc_Klockow 3
class Klocki
{
	RectangleShape podloga;
	Texture tekstura_podloga;
	Texture tekstura_klocki;
	Vector2f rozmiary_podlogi{};
	RectangleShape klocki[3][10];
	Vector2f rozmiar_klockow;
	int Ilosc_Klockow_wys=3;
	Clock czas_gen{};
	Clock czas_przyspieszania{};
	int j = 0;
public:
	Klocki();
	virtual ~Klocki();
	void ruch_klockow();
	void rys_klocki(RenderWindow& okno,Graj& graj);
	void rys_podloga(RenderWindow& okno);
};

