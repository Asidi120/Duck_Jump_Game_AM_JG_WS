#pragma once
#include "Gra.h"
class Chlebek
{
protected:
	Texture tekstura_chlebek;
	int ilosc_zdobytych_chlebkow{};
public:
	float predkosc_chlebka = 0.5f;
	int czy_rysowac = 1;
	Vector2f rozmiary_chlebek{};
	RectangleShape chlebek;
	Chlebek();
	int losowanie{};
	virtual ~Chlebek();
	void rys_chlebek(RenderWindow& okno);
};

