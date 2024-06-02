#pragma once
#include "Gra.h"
class Kaczuszka
{
	RectangleShape kaczuszka;
	Texture tekstura_kaczuszka;
	Vector2u wysokosc_kaczuszki;
	bool czy_na_ziemi=1;
public:
	Kaczuszka();
	virtual ~Kaczuszka();
	void rysuj_gracza(RenderWindow& okno);
};

