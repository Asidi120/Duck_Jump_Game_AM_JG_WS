#pragma once
#include "Gra.h"
#include "Graj.h"
#include "Klocki.h"
class Klocki;
class Kaczuszka
{
	RectangleShape kaczuszka;
	Texture tekstura_kaczuszka;
	Vector2f rozmiary_kaczuszki{};
	bool czy_na_ziemi=1;
	bool czy_glowa_w_prawo = 1;
	float rob = false;
	int skok_wysokosc_skoku = 220, skok_aktuala_poz = 0, skok_stopien = 15, skok_kierunek=1;
	Vector2f wsp_klockow[2][10]{}; //pozycja klockow
public:
	bool czy_skok = false;
	Kaczuszka();
	virtual ~Kaczuszka();
	void rysuj_gracza(RenderWindow& okno);
	void ruch(float kierunek_x,float kierunek_y);
	bool czy_jest_na_ziemi(Klocki* kloce);
	void skok_kaczuchy();
};

