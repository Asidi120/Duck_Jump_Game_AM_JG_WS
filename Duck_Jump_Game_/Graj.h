#pragma once
#include "Gra.h"
#include "Menu.h"
class Kaczuszka;
class Klocki;
class Graj: public Menu
{
	Clock czas_gry{};
	Event event_gra{};
	//Kaczuszka kaczuszka;
	long long czas_przycisku = 0; // czas przerwy miedzy przyciskami
	long long czas_czekania = 0; // czas nieokreslony
public:
	Graj();
	virtual ~Graj();
	bool czy_graj_wlaczone = 0;
	void rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka);
	void co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka);
	long long czas_milisekundy();
};

