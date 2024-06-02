#pragma once
#include "Gra.h"
#define Ilosc_Klockow 4
class Klocki
{
	RectangleShape podloga;
	Texture tekstura_podloga;
	Vector2f rozmiary_podlogi{};
	RectangleShape klocki[4];
	Vector2f rozmiar_klockow;
public:
	Klocki();
	virtual ~Klocki();
	void ruch_klockow();
};

