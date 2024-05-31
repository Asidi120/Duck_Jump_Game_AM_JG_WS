#include "Ustawienia.h"


Ustawienia::Ustawienia()
{
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Ustawienia");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 150));
	ustawienia_napisy[0].setString("Muzyka: <TAK>");
	ustawienia_napisy[0].setFillColor(Color::White);
	ustawienia_napisy[0].setCharacterSize(28);
	ustawienia_napisy[0].setPosition(Vector2f(300, 350));
	ustawienia_napisy[0].setFont(czcionka);

	ustawienia_napisy[1].setString("Wyjscie do menu");
	ustawienia_napisy[1].setFillColor(Color::White);
	ustawienia_napisy[1].setCharacterSize(28);
	ustawienia_napisy[1].setPosition(Vector2f(200, 450));
	ustawienia_napisy[1].setFont(czcionka);

	wybrany_obiekt = 0;
}

Ustawienia::~Ustawienia() {}

void Ustawienia::rysuj_ustawienia(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < IloscNapisowUstawienia; i++)
	{
		okno.draw(ustawienia_napisy[i]);
	}
}

void Ustawienia::wylacz_wlacz_muzyka()
{

}

