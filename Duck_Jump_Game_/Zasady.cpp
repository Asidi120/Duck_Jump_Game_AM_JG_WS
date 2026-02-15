#include "Zasady.h"

Zasady::Zasady()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Red);
	tytul.setString("Zasady gry");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 145));
	for (int i = 0; i < IloscNapisowZasady; i++)
	{
		zasady_tekst[i].setFillColor(Color::Black);
		zasady_tekst[i].setCharacterSize(23);
		zasady_tekst[i].setPosition(Vector2f(10, static_cast<float>(wysokosc)));
		zasady_tekst[i].setFont(czcionka);
		wysokosc += 60;
	}
	zasady_tekst[0].setString("1.Celem gry jest osiagniecie jak najwyzszego wyniku, ");
	zasady_tekst[1].setString("skaczac w gore na roznych platformach.");
	zasady_tekst[2].setString("2.Punkty zdobywasz za kazdy pokonany dystans w gore.");
	zasady_tekst[3].setString("3.Gra konczy sie, gdy postac spadnie poza ekran na dol.");
	zasady_tekst[4].setString("4.Zdobywaj dodatkowa walute (chlebki) za ktora");
	zasady_tekst[5].setString("mozesz odblokowac nowe postacie");
	zasady_tekst[6].setString("5.Poruszasz sie szczalkami oraz skaczesz spacja");
}

Zasady::~Zasady() {}

void Zasady::rysuj_zasady(RenderWindow& okno) //rysuje zasady
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < IloscNapisowZasady; i++)
	{
		okno.draw(zasady_tekst[i]);
	}
}

void Zasady::co_sie_dzieje_w_zasadach(RenderWindow& okno) //sprawdza co sie teraz dzieje w okienku
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
