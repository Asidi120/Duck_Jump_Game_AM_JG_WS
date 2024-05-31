#include "Gra.h"
#pragma once

class Menu
{
protected:
	Text menu[4];
	Font czcionka;
	Text tytul;
	const int Ilosc_Napisow = 4;
	int wybrany_obiekt=0;
	Texture tekstura_tla;
	Texture menu_tekst;
	Sprite tlo;
	Sprite warstwa;
public:
	bool czy_menu_otwarte = 1;
	Menu();
	virtual~Menu();
	void rysuj_menu(RenderWindow &okno);
	int ktory_teraz();
	void ruch_do_gory(int);
	void ruch_w_dol(int);
};

