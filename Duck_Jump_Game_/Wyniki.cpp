#include "Wyniki.h"

Wyniki::Wyniki()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Koniec gry!");
	tytul.setCharacterSize(40);
	tytul.setPosition(Vector2f(180, 150));
	for (int i = 0; i < 4; i++)
	{
		tekst_wyniki[i].setFillColor(Color::Black);
		tekst_wyniki[i].setCharacterSize(28);
		tekst_wyniki[i].setPosition(Vector2f(200, static_cast<float>(wysokosc)));
		tekst_wyniki[i].setFont(czcionka);
		wysokosc += 80;
	}
	tekst_wyniki[0].setString("Twoj wynik: ");
	tekst_wyniki[1].setString("Najlepszy wynik: ");
	tekst_wyniki[2].setString("Zagraj ponownie");
	tekst_wyniki[3].setString("Wyjdz");
}

Wyniki::~Wyniki()
{

}

//void Wyniki::wypisz_punkty(Kaczuszka* kaczuszka)
//{
//
//}

void Wyniki::rysuj_wyniki(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < 4; i++)
	{
		okno.draw(tekst_wyniki[i]);
	}
}
