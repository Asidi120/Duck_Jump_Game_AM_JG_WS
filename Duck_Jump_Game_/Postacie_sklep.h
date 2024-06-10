#pragma once
#include "Gra.h"
#include "Menu.h"
#include "Klocki.h"
#include "Kaczuszka.h"
#define IloscNapisowPostacie 3
class Klocki;
class Kaczuszka;
class Postacie_sklep: public Menu
{
	Text postacie_sklep_tekst[IloscNapisowPostacie]{};
	Event event_postacie{};
	float wysokosc = 350;
	int ilosc_kaczuszek_do_kupienia=3;
	int wybrana = 0;
public:
	bool czy_postacie_sklep_wlaczone = 0;
	Postacie_sklep();
	virtual ~Postacie_sklep();
	void rysuj_postacie_sklep(RenderWindow& okno);
	void co_sie_dzieje_w_sklepie(RenderWindow& okno, Klocki* klocki, Kaczuszka* kaczuszka);
};

