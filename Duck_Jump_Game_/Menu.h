#include "Gra.h"
#pragma once

class Menu
{
	Text menu[4];
	Font czcionka;
	Text tytul;
	const int Ilosc_Napisow = 4;
	int wybrany_obiekt=0;
	Texture tekstura_tla;
	Sprite tlo;
public:
	Menu();
	virtual~Menu();
	void rysuj_menu(RenderWindow &okno);
	void ruch_do_gory();
	void ruch_w_dol();
};

