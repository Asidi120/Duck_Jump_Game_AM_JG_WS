#include "Gra.h"
#pragma once
#define Ilosc_Napisow 6

class Menu
{
protected:
	Font czcionka;
	Text tytul;
	Texture menu_tekst;
	Sprite warstwa;
public:
	string nazwa_gracza{};
	Texture tekstura_tla;
	Sprite tlo;
	Text menu[Ilosc_Napisow];
	bool czy_menu_otwarte = 1;
	int wybrany_obiekt = 0;
	Menu();
	virtual~Menu();
	void rysuj_menu(RenderWindow &okno);
	int ktory_teraz();
	int ruch_do_gory(int, Text[], int);
	int ruch_w_dol(int, Text[], int);
};

