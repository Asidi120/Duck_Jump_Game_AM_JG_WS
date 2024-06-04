#pragma once
#include "Gra.h"
#include "Menu.h"
#include "Klocki.h"
class Kaczuszka;
class Klocki;
class Graj: public Menu
{
	Time czas{};
	Clock czas_gen{};
	Clock czas_przyspieszania{};
	Event event_gra{};
	//Kaczuszka kaczuszka;
	long long czas_przycisku = 0; // czas przerwy miedzy przyciskami
	long long czas_czekania = 0; // czas nieokreslony
	Klocki kloce;
public:
	Clock czas_gry{};
	Graj();
	virtual ~Graj();
	bool czy_graj_wlaczone = 0;
	void rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka);
	void co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka);
	long long czas_milisekundy();
	void ustaw_czas();
};

