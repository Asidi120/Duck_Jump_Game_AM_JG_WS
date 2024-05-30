#include "Gra.h"
#pragma once

class Menu : public Gra
{
	
	Font czcionka;
public:
	const int Ilosc_Napisow = 4;
	Menu();
	virtual~Menu();
	Text menu[];
	friend void rysuj_menu(Menu);
	void ruch_do_gory();
	void ruch_w_dol();
};

