#include "Gra.h"
#pragma once

class Menu : public Gra
{
	const int Ilosc_Napisow = 4;
	Font czcionka;
public:
	Menu();
	virtual~Menu();
	Text menu[];
	void rysuj_menu();
	void ruch_do_gory();
	void ruch_w_dol();
};

