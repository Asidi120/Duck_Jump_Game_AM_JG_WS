#pragma once
#include "Gra.h"
#define Ilosc_Klockow 2
class Klocki
{
	RectangleShape podloga;
	Texture tekstura_podloga;
	Texture tekstura_klocki;
	Vector2f rozmiary_podlogi{};
	Vector2f rozmiar_klockow;
	int Ilosc_Klockow_wys=2;
	Clock czas_gen{};
	Clock czas_przyspieszania{};
	int losowanie;
	int ile;
public:
	int j = 0;
	RectangleShape klocki[2][10];
	Klocki();
	virtual ~Klocki();
	void ruch_klockow();
	void rys_klocki(RenderWindow& okno,Graj& graj);
	void rys_podloga(RenderWindow& okno);
};

