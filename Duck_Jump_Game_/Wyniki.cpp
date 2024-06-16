#include "Wyniki.h"

Wyniki::Wyniki()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Koniec gry!");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 150));
	wybrany_obiekt = 0;
	for (int i = 0; i < 2; i++)
	{
		wynik_i_naj_wynik[i].setFillColor(Color::Black);
		wynik_i_naj_wynik[i].setCharacterSize(28);
		wynik_i_naj_wynik[i].setPosition(Vector2f(200, static_cast<float>(wysokosc-100)));
		wynik_i_naj_wynik[i].setFont(czcionka);
		tekst_wyniki[i].setFillColor(Color::Black);
		tekst_wyniki[i].setCharacterSize(28);
		tekst_wyniki[i].setPosition(Vector2f(200, static_cast<float>(wysokosc+100)));
		tekst_wyniki[i].setFont(czcionka);
		wysokosc += 80;
	}
	tekst_wyniki[0].setFillColor(Color::Red);
	tekst_wyniki[0].setString("Zagraj ponownie");
	tekst_wyniki[1].setString("Wyjdz");
}

Wyniki::~Wyniki()
{

}
void Wyniki::co_sie_dzieje_w_wynikach(RenderWindow& okno,Graj* graj)
{
	while (okno.pollEvent(event_wyniki))
	{
		if (event_wyniki.type == Event::KeyPressed)
		{
				if (event_wyniki.key.code == Keyboard::Escape) //wracamy do menu przyciskiem esc
				{
					czy_wyniki_wlaczone = 0;
					break;
				}
				if (wybrany_obiekt == 0 && event_wyniki.key.code == Keyboard::Enter) //gramy ponownie przyciskiem
				{
					czy_wyniki_wlaczone = 0;
					graj->czy_graj_wlaczone = 1;
					break;
				}
				if (wybrany_obiekt == 1 && event_wyniki.key.code == Keyboard::Enter) //wracamy do menu  przyciskiem wyjdz
				{
					czy_wyniki_wlaczone = 0;
					break;
				}
				if (event_wyniki.key.code == Keyboard::Down) //podswietla napisy ruchem w dol
				{
					wybrany_obiekt = ruch_w_dol(2, tekst_wyniki, wybrany_obiekt);
				}

				if (event_wyniki.key.code == Keyboard::Up) //podswietla napisy ruchem do gory
				{
					wybrany_obiekt = ruch_do_gory(2, tekst_wyniki, wybrany_obiekt);
				}
			
		}
		if (event_wyniki.type == Event::Closed) //zamyka program przyciskiem x			
		okno.close();
	}
	
}

string Wyniki::wypisz_punkty(Kaczuszka* kaczuszka,Klocki* kloce)
{
	return to_string(int(kaczuszka->punkty_liczenie(kloce)));
}

void Wyniki::rysuj_wyniki(RenderWindow& okno,Baza_Danych* baza_danych)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < 2; i++)
	{
		okno.draw(wynik_i_naj_wynik[i]);
		okno.draw(tekst_wyniki[i]);
	}
}
