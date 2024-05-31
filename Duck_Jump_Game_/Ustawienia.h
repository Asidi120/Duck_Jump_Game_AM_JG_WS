#include "Gra.h"
#include "Menu.h"
#define IloscNapisowUstawienia 2

#pragma once
class Ustawienia:public Menu
{
	Text ustawienia_napisy[IloscNapisowUstawienia];
public:
	Ustawienia();
	virtual ~Ustawienia();
	void rysuj_ustawienia(RenderWindow &okno);
	void wylacz_wlacz_muzyka();
};

