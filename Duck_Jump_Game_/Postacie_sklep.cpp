#include "Postacie_sklep.h"

Postacie_sklep::Postacie_sklep()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Sklep postaci");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 150));
	for (int i = 0; i < IloscNapisowPostacie; i++)
	{
		postacie_sklep_tekst[i].setFillColor(Color::Black);
		postacie_sklep_tekst[i].setCharacterSize(28);
		postacie_sklep_tekst[i].setPosition(Vector2f(200,wysokosc));
		postacie_sklep_tekst[i].setFont(czcionka);
		wysokosc += 80;
	}
	postacie_sklep_tekst[0].setString("1. linia");
	postacie_sklep_tekst[1].setString("2. linia");
}

Postacie_sklep::~Postacie_sklep() {}

void Postacie_sklep::rysuj_postacie_sklep(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < IloscNapisowPostacie; i++)
	{
		okno.draw(postacie_sklep_tekst[i]);
	}
}

void Postacie_sklep::co_sie_dzieje_w_sklepie(RenderWindow& okno)
{
	while (okno.pollEvent(event_postacie))
	{
		if (event_postacie.type == Event::KeyPressed)
		{
			if (event_postacie.key.code == Keyboard::Right)
			{
				cout << "Strzalka w prawo";
			}
			if (event_postacie.key.code == Keyboard::Left)
			{
				cout << "Strzlakwa w lewo";
			}
			if (event_postacie.key.code == Keyboard::Escape)
			{
				czy_postacie_sklep_wlaczone = 0;
				break;
			}
		}
	}
}
