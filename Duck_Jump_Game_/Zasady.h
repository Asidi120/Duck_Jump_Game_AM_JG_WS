#pragma once
#include "Gra.h"
#include "Menu.h"
#define IloscNapisowZasady 10

class Zasady : public Menu
{
	Text zasady_tekst[IloscNapisowZasady]{};
	Event event_zasady{};
	int wysokosc=350;
public:
	int wybrany_obiekt_zasady = 0;
	bool czy_zasady_wlaczone = 0;
	Zasady();
	virtual ~Zasady();
	void rysuj_zasady(RenderWindow& okno);
	void co_sie_dzieje_w_zasadach(RenderWindow& okno);
};

