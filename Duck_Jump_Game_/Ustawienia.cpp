#include "Ustawienia.h"


Ustawienia::Ustawienia() //tu ustawiamy wszystkie napisy w ustawieniach
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Ustawienia");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(210, 150));
	if (!buformuzyki.loadFromFile("muzyka_menu.wav")) //wyrzuca blad na konsolce jesli muzyka sie nie zaladuje
	{
		cout << "Blad ladowania muzyki" << endl;
	}
	dzwiek_menu.setBuffer(buformuzyki);
	if (muzyka == 1) //wlaczenie muzyki
	{
		ustawienia_napisy[0].setString("Muzyka: <TAK>");
		dzwiek_menu.play();
	}
	else
	{
		ustawienia_napisy[0].setString("Muzyka: <NIE>"); //wylaczenie muzyki
		dzwiek_menu.pause();
	}
	ustawienia_napisy[0].setFillColor(Color::Red);
	ustawienia_napisy[0].setCharacterSize(28);
	ustawienia_napisy[0].setPosition(Vector2f(210, 350));
	ustawienia_napisy[0].setFont(czcionka);

	ustawienia_napisy[1].setString("Wyjscie do menu");
	ustawienia_napisy[1].setFillColor(Color::Black);
	ustawienia_napisy[1].setCharacterSize(28);
	ustawienia_napisy[1].setPosition(Vector2f(205, 480));
	ustawienia_napisy[1].setFont(czcionka);

	wybrany_obiekt = 0;
}

Ustawienia::~Ustawienia() {}

void Ustawienia::rysuj_ustawienia(RenderWindow& okno) // rysuje tlo, tytul i wszystkie napisy
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < IloscNapisowUstawienia; i++)
	{
		okno.draw(ustawienia_napisy[i]);
	}
}

void Ustawienia::co_sie_dzieje_w_ustawieniach(RenderWindow& okno) 
{
	while (okno.pollEvent(event_muzyka))
	{
		if (event_muzyka.type == Event::KeyPressed)
		{
			if (wybrany_obiekt == 0) //sprawdza czy jest ustawione na muzyce
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
						dzwiek_menu.setLoop(1);
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
			}
			if (event_muzyka.key.code == Keyboard::Escape) //wracamy do menu przyciskiem esc
			{
				czy_ustawienia_wlaczone = 0;
				break;
			}

			if (wybrany_obiekt == 1 && event_muzyka.key.code == Keyboard::Enter) //wracamy do menu przyciskiem wyjdz
			{
				czy_ustawienia_wlaczone = 0;
				break;
			}

			if (event_muzyka.key.code == Keyboard::Down) //podswietla napisy ruchem w dol
			{
				wybrany_obiekt = ruch_w_dol(2, ustawienia_napisy, wybrany_obiekt);
			}

			if (event_muzyka.key.code == Keyboard::Up) //podswietla napisy ruchem do gory
			{
				wybrany_obiekt = ruch_do_gory(2, ustawienia_napisy, wybrany_obiekt);
			}

		}
		if (event_muzyka.type == Event::Closed) //zamyka program przyciskiem x
			okno.close();
	}
}

