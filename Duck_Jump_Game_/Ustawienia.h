#include "Gra.h"
#include "Menu.h"
#define IloscNapisowUstawienia 2

#pragma once
class Ustawienia:public Menu
{
	Text ustawienia_napisy[IloscNapisowUstawienia];
	bool muzyka=1;
	Event event_muzyka;
public:
	Ustawienia();
	virtual ~Ustawienia();
	void rysuj_ustawienia(RenderWindow &okno);
	void wylacz_wlacz_muzyka(RenderWindow& okno);
};

