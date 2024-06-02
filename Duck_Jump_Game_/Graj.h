#pragma once
#include "Gra.h"
#include "Menu.h"
class Kaczuszka;
class Graj: public Menu
{
	Clock czas_gry{};
	Event event_gra{};
public:
	Graj();
	virtual ~Graj();
	bool czy_graj_wlaczone = 0;
	void rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka);
	void co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka);
};

