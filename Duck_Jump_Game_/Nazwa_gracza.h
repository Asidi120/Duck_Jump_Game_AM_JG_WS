#include "Menu.h"
#include "Graj.h"
#pragma once

class Baza_Danych;
class Graj;
class Nazwa_gracza : public Menu
{
	Event nazwa_gracza_event;
public:
	void zmiana_nazwy(Graj* graj);
	string nazwa_gracza_zmiana{};
	string nowa_nazwa_gracza{};
	Text nazwa_gracza_tekst[3];
	bool czy_nazwa_gracza_wlaczone = 0;
	Nazwa_gracza();
	virtual ~Nazwa_gracza();
	void rysuj_nazwa_gracza(RenderWindow& okno);
	void co_sie_dzieje_w_nazwa_gracza(RenderWindow& okno);
	string ustaw_nazwe_gracza(Baza_Danych* baza_danych); 
};

