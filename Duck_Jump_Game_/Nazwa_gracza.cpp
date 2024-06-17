#include "Nazwa_gracza.h"
#include "Baza_Danych.h"


string Nazwa_gracza::ustaw_nazwe_gracza(Baza_Danych* baza_danych)
{
	nazwa_gracza = baza_danych->pobierzOstatniegoGracza();
	return nazwa_gracza;
}

Nazwa_gracza::Nazwa_gracza()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Nazwa gracza");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(210, 150));

	nazwa_gracza_tekst[0].setFillColor(Color::Red);
	nazwa_gracza_tekst[0].setCharacterSize(28);
	nazwa_gracza_tekst[0].setPosition(Vector2f(150, 350));
	nazwa_gracza_tekst[0].setFont(czcionka);

	nazwa_gracza_tekst[1].setString("Zmien nazwe gracza: ");
	nazwa_gracza_tekst[1].setFillColor(Color::Black);
	nazwa_gracza_tekst[1].setCharacterSize(28);
	nazwa_gracza_tekst[1].setPosition(Vector2f(150, 480));
	nazwa_gracza_tekst[1].setFont(czcionka);

	nazwa_gracza_tekst[2].setString("Wyjscie do menu");
	nazwa_gracza_tekst[2].setFillColor(Color::Black);
	nazwa_gracza_tekst[2].setCharacterSize(28);
	nazwa_gracza_tekst[2].setPosition(Vector2f(200, 610));
	nazwa_gracza_tekst[2].setFont(czcionka);
}

Nazwa_gracza::~Nazwa_gracza()
{

}

void Nazwa_gracza::rysuj_nazwa_gracza(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < 3; i++)
	{
		okno.draw(nazwa_gracza_tekst[i]);
	}
}

void Nazwa_gracza::co_sie_dzieje_w_nazwa_gracza(RenderWindow& okno)
{
	while (okno.pollEvent(nazwa_gracza_event))
	{
		if (nazwa_gracza_event.type == Event::KeyPressed)
		{
			if (nazwa_gracza_event.key.code == Keyboard::Escape) //wracamy do menu przyciskiem esc
			{
				czy_nazwa_gracza_wlaczone = 0;
				break;
			}
			
			if (wybrany_obiekt == 1 && nazwa_gracza_event.key.code == Keyboard::Enter) //zmienia nazwe gracza
			{
				/*czy_nazwa_gracza_wlaczone = 0;*/
				break;
			}
			if (wybrany_obiekt == 2 && nazwa_gracza_event.key.code == Keyboard::Enter) //wracamy do menu  przyciskiem wyjdz
			{
				czy_nazwa_gracza_wlaczone = 0;
				break;
			}
			if (nazwa_gracza_event.key.code == Keyboard::Down) //podswietla napisy ruchem w dol
			{
				wybrany_obiekt = ruch_w_dol(3, nazwa_gracza_tekst, wybrany_obiekt);
			}

			if (nazwa_gracza_event.key.code == Keyboard::Up) //podswietla napisy ruchem do gory
			{
				wybrany_obiekt = ruch_do_gory(3, nazwa_gracza_tekst, wybrany_obiekt);
			}

		}
		if (nazwa_gracza_event.type == Event::Closed) //zamyka program przyciskiem x			
			okno.close();
	}

}






//void ustawienia_sie_rysuja(RenderWindow& okno, Ustawienia* ustawienia)
//{
//    ustawienia->czy_ustawienia_wlaczone = 1;
//    ustawienia->wybrany_obiekt = 0;
//    while (ustawienia->czy_ustawienia_wlaczone == 1)
//    {
//        okno.clear();
//        ustawienia->rysuj_ustawienia(okno);
//        ustawienia->co_sie_dzieje_w_ustawieniach(okno);
//        okno.display();
//    }
//}