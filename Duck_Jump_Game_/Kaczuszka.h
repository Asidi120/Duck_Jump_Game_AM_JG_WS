#pragma once
#include "Gra.h"
class Kaczuszka
{
	RectangleShape kaczuszka;
	Texture tekstura_kaczuszka;
	Vector2f rozmiary_kaczuszki{};
	bool czy_na_ziemi=1;
	bool czy_glowa_w_prawo = 1;
	float rob = false;
	bool faza1=1;
public:
	Kaczuszka();
	virtual ~Kaczuszka();
	void rysuj_gracza(RenderWindow& okno);
	void ruch(float kierunek_x,float kierunek_y);
	bool czy_jest_na_ziemi();
};

