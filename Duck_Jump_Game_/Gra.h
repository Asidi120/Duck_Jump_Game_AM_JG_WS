#include <iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


using namespace sf;
using namespace std;
#pragma once

class Gra
{
	Event evnt;
	void tworzOkno(); // tworzy nam okienko
public:
	RenderWindow* okno = nullptr;
	VideoMode videomode;
	Gra();
	virtual~Gra();

	const bool czyGraOtwarta() const; //potrzebne do petli w main, zwraca czy okno jest otwarte
	void petlaOkna(); //pozwala zamykac okno iksem i klawiszem esc
	void aktualizuj(); //odpowiada za rzeczy ktore dzieja sie w oknie
	void rysuj(); //rysuje rzeczy w oknie
};

