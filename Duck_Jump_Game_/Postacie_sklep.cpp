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

void Postacie_sklep::co_sie_dzieje_w_sklepie(RenderWindow& okno, Klocki* klocki,Kaczuszka* kaczuszka)
{
	while (okno.pollEvent(event_postacie))
	{
		if (event_postacie.type == Event::Closed) //przycisk x zamyka gre
		{
			okno.close();
		}
		if (event_postacie.type == Event::KeyPressed)
		{
			if (event_postacie.key.code == Keyboard::Escape)
			{
				czy_postacie_sklep_wlaczone = 0;
				break;
			}
			if (event_postacie.key.code == Keyboard::Right)
			{
				if (wybrana < 3)
				{
					cout << "Strzalka w prawo";
					wybrana++;
				}
			}
			if (event_postacie.key.code == Keyboard::Left)
			{
				if (wybrana > 0)
				{
					cout << "Strzlakwa w lewo";
					wybrana--;
				}
			}
			if (event_postacie.key.code == Keyboard::Enter)
			{
				if (klocki->chlebek.ilosc_zdobytych_chlebkow >= 15 && wybrana == 1)
				{
					klocki->chlebek.ilosc_zdobytych_chlebkow -= 15;
					//zmiana tesktury kaczuszka->kaczuszka.setTexture()
				}
				else if (klocki->chlebek.ilosc_zdobytych_chlebkow >= 15 && wybrana==2)
				{
					klocki->chlebek.ilosc_zdobytych_chlebkow -= 15;
					//zmiana tesktury kaczuszka->kaczuszka.setTexture()
				}
				else if (klocki->chlebek.ilosc_zdobytych_chlebkow >= 15 && wybrana == 3)
				{
					klocki->chlebek.ilosc_zdobytych_chlebkow -= 15;
					//zmiana tesktury kaczuszka->kaczuszka.setTexture()
				}
				else
				{
					cout << "Za malo monet, przykro mi\n";
				}
			}
		}
		}
	
}
