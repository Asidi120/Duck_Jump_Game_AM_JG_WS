#pragma once
#include "Gra.h"
#define Ilosc_Klockow 2
class Klocki
{
	Texture tekstura_podloga;
	Texture tekstura_klocki;
	int Ilosc_Klockow_wys=2;
	Clock czas_przyspieszania{};
	int losowanie{};
public:
	Vector2f rozmiary_podlogi{};
	Vector2f rozmiar_klockow;
	RectangleShape podloga;
	int j = 0;
	RectangleShape klocki[2][10];
	Klocki();
	int ile{};
	virtual ~Klocki();
	void ruch_klockow(Graj& graj);
	void rys_klocki(RenderWindow& okno,Graj& graj);
	void rys_podloga(RenderWindow& okno);
};

