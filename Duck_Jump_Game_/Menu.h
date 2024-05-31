#include "Gra.h"
#pragma once

class Menu
{
	Text menu[4];
	Font czcionka;
	const int Ilosc_Napisow = 4;
	int wybrany_obiekt=0;
public:
	Menu();
	virtual~Menu();
	void rysuj_menu(RenderWindow &okno);
	void ruch_do_gory();
	void ruch_w_dol();
};

