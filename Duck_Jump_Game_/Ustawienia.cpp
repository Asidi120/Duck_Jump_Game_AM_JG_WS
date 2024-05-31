#include "Ustawienia.h"


Ustawienia::Ustawienia()
{
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Ustawienia");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 150));
	wybrany_obiekt = 0;
}

Ustawienia::~Ustawienia() {}

void Ustawienia::rysuj_ustawienia(RenderWindow& okno)
{
	okno.draw(tytul);
}

