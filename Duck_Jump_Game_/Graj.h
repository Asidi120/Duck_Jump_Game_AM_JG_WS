#pragma once
#include "Gra.h"
#include "Menu.h"
#include "Klocki.h"
class Kaczuszka;
class Klocki;
class Graj: public Menu
{
	Time czas{};
	Event event_gra{};
	long long czas_przycisku = 0; // czas przerwy miedzy przyciskami
	long long czas_czekania = 0; // czas nieokreslony
public:
	Klocki kloce;
	Clock czas_gry{};
	bool czy_rysowac_klocki=1;
	Graj();
	virtual ~Graj();
	bool czy_graj_wlaczone = 0;
	void rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka, Graj *graj);
	void co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka);
	long long czas_milisekundy();
	int ustaw_czas();
	bool czy_pryspieszyc();
};

