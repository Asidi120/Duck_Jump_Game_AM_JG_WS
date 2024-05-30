#include "Gra.h"
#pragma once

class Menu : public Gra
{
	const int Ilosc_Napisow = 4;
	Font czcionka;
	Text menu[];

public:
	Menu();
	virtual~Menu();

	void rysuj_menu();
	void ruch_do_gory();
	void ruch_w_dol();
};

