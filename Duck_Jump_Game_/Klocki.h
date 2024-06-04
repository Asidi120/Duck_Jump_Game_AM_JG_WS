#pragma once
#include "Gra.h"
#define Ilosc_Klockow 4
class Klocki
{
	RectangleShape podloga;
	Texture tekstura_podloga;
	Vector2f rozmiary_podlogi{};
	RectangleShape klocki[4];
	Vector2f rozmiar_klockow;
	int Ilosc_Klockow_wys=4;
public:
	Klocki();
	virtual ~Klocki();
	void ruch_klockow();
	void rys_klocki(RenderWindow& okno);
	void rys_podloga(RenderWindow& okno);
};

