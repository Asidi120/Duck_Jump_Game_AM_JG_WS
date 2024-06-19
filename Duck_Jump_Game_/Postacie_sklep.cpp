#include "Postacie_sklep.h"

Postacie_sklep::Postacie_sklep()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Sklep postaci");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(190, 150));
	tekstury_kaczki[0].loadFromFile("Agnieszka_Sklep.png");
	tekstury_kaczki[1].loadFromFile("Kuba_Sklep.png");
	tekstury_kaczki[2].loadFromFile("Weronika_Sklep.png");
	tekstury_kaczki_swiatlo[0].loadFromFile("Agnieszka_Sklep_Swiatlo.png");
	tekstury_kaczki_swiatlo[1].loadFromFile("Kuba_Sklep_Swiatlo.png");
	tekstury_kaczki_swiatlo[2].loadFromFile("Weronika_Sklep_Swiatlo.png");
	postacie_sklep_tekst[0].setTexture(&tekstury_kaczki_swiatlo[0]);
	for (int i = 0; i < IloscNapisowPostacie; i++)
	{
		postacie_sklep_tekst[i].setSize(Vector2f(120.f,140.f));
		postacie_sklep_tekst[i].setPosition(Vector2f(szerokosc, 400));
		postacie_sklep_tekst[i].setTexture(&tekstury_kaczki[i]);
		szerokosc += 200;
	}
}

Postacie_sklep::~Postacie_sklep() {}


//rysuje sklep postaci
void Postacie_sklep::rysuj_postacie_sklep(RenderWindow& okno, Baza_Danych* baza_danych)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < IloscNapisowPostacie; i++)
	{
		okno.draw(postacie_sklep_tekst[i]);
	}
}

//sprawdza co sie dzieje w sklepie postaci (ktora postac sie wybralo itp)
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
				postacie_sklep_tekst[0].setTexture(&tekstury_kaczki[2]);
				postacie_sklep_tekst[1].setTexture(&tekstury_kaczki[1]);
				postacie_sklep_tekst[2].setTexture(&tekstury_kaczki[2]);
				break;
			}
			if (event_postacie.key.code == Keyboard::Right)
			{
				if (wybrana < 2)
				{
					wybrana++;
					if (wybrana == 0)
					{
						postacie_sklep_tekst[0].setTexture(&tekstury_kaczki_swiatlo[0]);
						postacie_sklep_tekst[1].setTexture(&tekstury_kaczki[1]);
						postacie_sklep_tekst[2].setTexture(&tekstury_kaczki[2]);
					}
					if (wybrana == 1)
					{
						postacie_sklep_tekst[1].setTexture(&tekstury_kaczki_swiatlo[1]);
						postacie_sklep_tekst[0].setTexture(&tekstury_kaczki[0]);
						postacie_sklep_tekst[2].setTexture(&tekstury_kaczki[2]);
					}
					if (wybrana == 2)
					{
						postacie_sklep_tekst[2].setTexture(&tekstury_kaczki_swiatlo[2]);
						postacie_sklep_tekst[0].setTexture(&tekstury_kaczki[0]);
						postacie_sklep_tekst[1].setTexture(&tekstury_kaczki[1]);
					}
				}
			}
			if (event_postacie.key.code == Keyboard::Left)
			{
				if (wybrana > 0)
				{
					wybrana--;
					if (wybrana == 0)
					{
						postacie_sklep_tekst[0].setTexture(&tekstury_kaczki_swiatlo[0]);
						postacie_sklep_tekst[1].setTexture(&tekstury_kaczki[1]);
						postacie_sklep_tekst[2].setTexture(&tekstury_kaczki[2]);
					}
					if (wybrana == 1)
					{
						postacie_sklep_tekst[1].setTexture(&tekstury_kaczki_swiatlo[1]);
						postacie_sklep_tekst[0].setTexture(&tekstury_kaczki[0]);
						postacie_sklep_tekst[2].setTexture(&tekstury_kaczki[2]);
					}
					if (wybrana == 2)
					{
						postacie_sklep_tekst[2].setTexture(&tekstury_kaczki_swiatlo[2]);
						postacie_sklep_tekst[0].setTexture(&tekstury_kaczki[0]);
						postacie_sklep_tekst[1].setTexture(&tekstury_kaczki[1]);
					}
				}
			}
			if (event_postacie.key.code == Keyboard::Enter)
			{
				if (wybrana == 0)
				{
					kaczuszka->ktora_tekstura = 1;
					kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_A);
				}
				else if (wybrana==1)
				{
					kaczuszka->ktora_tekstura = 2;
					kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_K);
				}
				else if (wybrana == 2)
				{
					kaczuszka->ktora_tekstura = 3;
					kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_W);
				}
			}
		}
		}
	
}
