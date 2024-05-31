#include "Gra.h"
#include "Menu.h"
#define IloscNapisowUstawienia 2

#pragma once
class Ustawienia:public Menu
{
	Text ustawienia[IloscNapisowUstawienia];
public:
	Ustawienia();
	virtual ~Ustawienia();
	void rysuj_ustawienia(RenderWindow &okno);
};

