#include "Zasady.h"

Zasady::Zasady()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Zasady gry");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 150));
	for (int i = 0; i < IloscNapisowZasady; i++)
	{
		zasady_tekst[i].setFillColor(Color::Black);
		zasady_tekst[i].setCharacterSize(28);
		zasady_tekst[i].setPosition(Vector2f(200, wysokosc));
		zasady_tekst[i].setFont(czcionka);
		wysokosc += 80;
	}
	zasady_tekst[0].setString("1. linia");
	zasady_tekst[1].setString("2. linia");
}

Zasady::~Zasady() {}

void Zasady::rysuj_zasady(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < IloscNapisowZasady; i++)
	{
		okno.draw(zasady_tekst[i]);
	}
}

void Zasady::co_sie_dzieje_w_zasadach(RenderWindow& okno)
{
	while (okno.pollEvent(event_zasady))
	{
		if (event_zasady.type == Event::KeyPressed)
		{
			if (event_zasady.key.code == Keyboard::Escape)
			{
				czy_zasady_wlaczone = 0;
				break;
			}
		}
	}
}
