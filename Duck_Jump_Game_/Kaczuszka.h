#pragma once
#include "Gra.h"
#include "Graj.h"
class Kaczuszka
{
	RectangleShape kaczuszka;
	Texture tekstura_kaczuszka;
	Vector2f rozmiary_kaczuszki{};
	bool czy_na_ziemi=1;
	bool czy_glowa_w_prawo = 1;
	float rob = false;
	//float czas_skoku = 0;
	//float przyspieszenie_ziemskie = 0.3;
	
	int skok_wysokosc_skoku = 150, skok_aktuala_poz = 0, skok_stopien = 15, skok_kierunek=1;

public:
	bool czy_skok = false;
//	int skok_opoznienie = 4;
	Kaczuszka();
	virtual ~Kaczuszka();
	void rysuj_gracza(RenderWindow& okno);
	void ruch(float kierunek_x,float kierunek_y);
	bool czy_jest_na_ziemi();
	void skok_kaczuchy();
};

