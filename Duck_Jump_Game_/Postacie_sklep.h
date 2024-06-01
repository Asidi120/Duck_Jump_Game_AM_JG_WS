#pragma once
#include "Gra.h"
#include "Menu.h"
#define IloscNapisowPostacie 3
class Postacie_sklep: public Menu
{
	Text postacie_sklep_tekst[IloscNapisowPostacie]{};
	Event event_postacie{};
	float wysokosc = 350;
public:
	bool czy_postacie_sklep_wlaczone = 0;
	Postacie_sklep();
	virtual ~Postacie_sklep();
	void rysuj_postacie_sklep(RenderWindow& okno);
	void co_sie_dzieje_w_sklepie(RenderWindow& okno);
};

