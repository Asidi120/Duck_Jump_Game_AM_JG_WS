#pragma once
#include "Gra.h"
#include "Kaczuszka.h"
#include "Klocki.h"

class Kaczuszka;
class Klocki;
class Baza_Danych;
class Graj;
;class Wyniki : public Menu
{
	Text tekst_wyniki[2]{};
	int wysokosc = 350;
	Event event_wyniki {};
public:
	Text wynik_i_naj_wynik[2]{};
	bool czy_wyniki_wlaczone = 0;
	Wyniki();
	virtual ~Wyniki();
	void co_sie_dzieje_w_wynikach(RenderWindow& okno,Graj* graj);
	string wypisz_punkty(Kaczuszka* kaczuszka,Klocki* kloce);
	void rysuj_wyniki(RenderWindow& okno,Baza_Danych* baza_danych);
};
