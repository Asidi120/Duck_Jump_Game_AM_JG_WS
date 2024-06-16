#include "Gra.h"
#pragma once
#include "Kaczuszka.h"
#include "Klocki.h"

class Kaczuszka;
class Klocki;
class Wyniki : public Menu
{
	Text tekst_wyniki[4]{};
	int wysokosc = 350;
public:
	Wyniki();
	virtual ~Wyniki();
	//void wypisz_punkty(Kaczuszka* kaczuszka);
	void rysuj_wyniki(RenderWindow& okno);
};

