#include <iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <chrono> // bibloteka czasowa

using namespace sf;
using namespace std;
#pragma once
class Menu;
class Ustawienia;
class Zasady;
class Postacie_sklep;
class Graj;
class Kaczuszka;
class Baza_Danych;
class Wyniki;
class Nazwa_gracza;
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
	Baza_Danych* baza_danych = nullptr;
	Wyniki* wyniki = nullptr;
	Nazwa_gracza* nazwa_gracza = nullptr;
public:
	RenderWindow* wskdookna() const; //wskaznik do okna
	Gra(); //tworzymy w nim okienko
	virtual~Gra();
	const bool czyGraOtwarta() const; //potrzebne do petli w main, zwraca czy okno jest otwarte
	void aktualizuj(); //pozwala zamykac okno iksem i klawiszem esc
	void ustaw(Menu* menu, Ustawienia* ustawienia, Zasady* zasady, Postacie_sklep* postacie_sklep, Graj* graj, Kaczuszka* kaczuszka,Baza_Danych* baza_danych,Wyniki* wyniki, Nazwa_gracza* nazwa_gracza);

};

