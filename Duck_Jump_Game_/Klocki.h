#pragma once
#include "Gra.h"
#include "Chlebek.h"
#define Ilosc_Klockow 2
class Klocki
{
	Texture tekstura_podloga;
	Texture tekstura_klocki;
	int Ilosc_Klockow_wys=2;
	Clock czas_przyspieszania{};
	int losowanie{};
	float koordynaty_y = 0;
	float koordynaty_x = 0;
public:
	Chlebek chlebek;
	float predkosc_klockow = 0.5;
	float ktory_teraz = -1;
	bool pierwszy_rzad=1;
	Vector2f rozmiary_podlogi{};
	Vector2f rozmiar_klockow;
	RectangleShape podloga;
	int j = 0;
	RectangleShape klocki[2][10];
	Klocki();
	int ile{};
	virtual ~Klocki();
	void ruch_klockow(Graj& graj);
	void rys_klocki(RenderWindow& okno,Graj& graj);
	void rys_podloga(RenderWindow& okno);
};

