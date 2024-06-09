#pragma once
#include "Gra.h"
class Chlebek
{
protected:
	Texture tekstura_chlebek;
	Vector2f rozmiary_chlebek{};
	RectangleShape chlebek;
	float predkosc_chlebka = 0.5;
	int ilosc_zdobytych_chlebkow{};
public:
	Chlebek();
	int losowanie{};
	virtual ~Chlebek();
	void rys_chlebek(RenderWindow& okno);
};

