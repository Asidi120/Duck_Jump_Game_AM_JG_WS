#include "Ustawienia.h"


Ustawienia::Ustawienia()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Ustawienia");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 150));
	if (!buformuzyki.loadFromFile("muzyka_menu.wav"))
	{
		cout << "Blad ladowania muzyki" << endl;
	}
	dzwiek_menu.setBuffer(buformuzyki);
	if (muzyka == 1)
	{
		ustawienia_napisy[0].setString("Muzyka: <TAK>");
		dzwiek_menu.play();
	}
	else
	{
		ustawienia_napisy[0].setString("Muzyka: <NIE>");
		dzwiek_menu.pause();
	}
	ustawienia_napisy[0].setFillColor(Color::Black);
	ustawienia_napisy[0].setCharacterSize(28);
	ustawienia_napisy[0].setPosition(Vector2f(300, 350));
	ustawienia_napisy[0].setFont(czcionka);

	ustawienia_napisy[1].setString("Wyjscie do menu");
	ustawienia_napisy[1].setFillColor(Color::Black);
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

void Ustawienia::wylacz_wlacz_muzyka(RenderWindow& okno)
{
	while (okno.pollEvent(event_muzyka))
	{
		if (event_muzyka.type == Event::KeyPressed)
		{
			if (event_muzyka.key.code == Keyboard::Right)
			{
				if (muzyka == 1)
				{
					muzyka = 0;
					ustawienia_napisy[0].setString("Muzyka: <NIE>");
					dzwiek_menu.pause();
				}
				else
				{
					muzyka = 1;
					ustawienia_napisy[0].setString("Muzyka: <TAK>");
					dzwiek_menu.play();
				}
			}
			if (event_muzyka.key.code == Keyboard::Left)
			{
				if (muzyka == 1)
				{
					muzyka = 0;
					ustawienia_napisy[0].setString("Muzyka: <NIE>");
					dzwiek_menu.pause();
				}
				else
				{
					muzyka = 1;
					ustawienia_napisy[0].setString("Muzyka: <TAK>");
					dzwiek_menu.play();
				}
			}
			if (event_muzyka.key.code == Keyboard::Escape)
			{
				czy_ustawienia_wlaczone = 0;
				break;
			}
		}
	}
}

