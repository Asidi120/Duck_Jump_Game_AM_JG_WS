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
class Menu;
class Ustawienia;
class Zasady;
class Postacie_sklep;
class Graj;
class Kaczuszka;
class Gra
{
	Event evnt{};
	RenderWindow* okno=nullptr;
	Menu* menu = nullptr;
	Ustawienia* ustawienia = nullptr;
	Zasady* zasady = nullptr;
	Postacie_sklep* postacie_sklep = nullptr;
	Graj* graj = nullptr;
	Kaczuszka* kaczuszka = nullptr;
public:
	RenderWindow* wskdookna() const; //wskaznik do okna
	Gra(); //tworzymy w nim okienko
	virtual~Gra();
	const bool czyGraOtwarta() const; //potrzebne do petli w main, zwraca czy okno jest otwarte
	void aktualizuj(); //pozwala zamykac okno iksem i klawiszem esc
	void ustaw(Menu* menu, Ustawienia* ustawienia, Zasady* zasady, Postacie_sklep* postacie_sklep, Graj* graj, Kaczuszka* kaczuszka);

};

