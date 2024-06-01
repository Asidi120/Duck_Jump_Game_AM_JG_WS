#include "Gra.h"
#pragma once
#define Ilosc_Napisow 5

class Menu
{
protected:
	Font czcionka;
	Text tytul;
	Texture tekstura_tla;
	Texture menu_tekst;
	Sprite tlo;
	Sprite warstwa;
public:
	Text menu[5];
	bool czy_menu_otwarte = 1;
	int wybrany_obiekt = 0;
	Menu();
	virtual~Menu();
	void rysuj_menu(RenderWindow &okno);
	int ktory_teraz();
	int ruch_do_gory(int, Text[], int);
	int ruch_w_dol(int, Text[], int);
};

