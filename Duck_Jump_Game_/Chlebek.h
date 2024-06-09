#pragma once
#include "Gra.h"
class Chlebek
{
protected:
	Texture tekstura_chlebek;
	Vector2f rozmiary_chlebek{};
	RectangleShape chlebek;
	int losowanie{};
	float predkosc_chlebka = 0.5;
	int ilosc_zdobytych_chlebkow{};
public:
	Chlebek();
	virtual ~Chlebek();
};

