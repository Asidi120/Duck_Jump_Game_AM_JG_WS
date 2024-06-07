#pragma once
#include "Gra.h"
#include "Graj.h"
#include "Klocki.h"
class Klocki;
class Kaczuszka
{
	Texture tekstura_kaczuszka;
	Vector2f rozmiary_kaczuszki{};
	bool czy_na_ziemi=1;
	bool czy_glowa_w_prawo = 1;
	float rob = false;
	int skok_wysokosc_skoku = 220, skok_aktuala_poz = 0, skok_stopien = 15;
	Vector2f wsp_klockow[2][10]{}; //pozycja klockow
	float eps = 5;
public:
	RectangleShape kaczuszka;
	int skok_kierunek=1;
	bool czy_skok = false;
	Kaczuszka();
	virtual ~Kaczuszka();
	void rysuj_gracza(RenderWindow& okno);
	void ruch(float kierunek_x,float kierunek_y);
	bool kaczuszka_y(int i, int j);
	bool kaczuszka_x(int i, int j, Klocki* kloce);
	bool czy_jest_na_ziemi(Klocki* kloce);
	void skok_kaczuchy();
	void ruch_gdy_na_ziemi(RenderWindow& okno, Klocki* kloce);
	bool czy_podloga(Klocki* kloce);
};

