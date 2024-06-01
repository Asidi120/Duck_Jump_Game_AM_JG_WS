#pragma once
#include "Gra.h"
#include "Menu.h"
class Graj: public Menu
{
	Event event_gra{};
public:
	Graj();
	virtual ~Graj();
	bool czy_graj_wlaczone = 0;
	void rysuj_gra(RenderWindow& okno);
	void co_sie_dzieje_w_grze(RenderWindow& okno);
};

