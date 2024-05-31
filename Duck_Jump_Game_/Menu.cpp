#include "Menu.h"
#include "Gra.h"

Menu::Menu(): wybrany_obiekt(0)
{
	if (!czcionka.loadFromFile("GloriaHallelujah-Regular.ttf"))
	{
		cout << "Blad czcionki" << endl;
	}
	if (!tekstura_tla.loadFromFile("chmurki2.png", IntRect(0, 0, 1000, 1000)))
	{
		cout << "Blad ladowania tla" << endl;
	}
	tekstura_tla.isSmooth();
	tlo.setTexture(tekstura_tla);
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("Duck Jump");
	tytul.setCharacterSize(60);
	tytul.setPosition(Vector2f(180,150));

	menu[0].setFont(czcionka);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setCharacterSize(38);
	menu[0].setPosition(Vector2f(300,350));

	menu[1].setFont(czcionka);
	menu[1].setFillColor(Color::Black);
	menu[1].setString("Postacie");
	menu[1].setPosition(Vector2f(270,450));

	menu[2].setFont(czcionka);
	menu[2].setFillColor(Color::Black);
	menu[2].setString("Ustawienia");
	menu[2].setPosition(Vector2f(255,550));

	menu[3].setFont(czcionka);
	menu[3].setFillColor(Color::Black);
	menu[3].setString("Wyjdz");
	menu[3].setPosition(Vector2f(290,650));
}
Menu::~Menu() {}
void Menu::rysuj_menu(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(tytul);
	for (int i = 0; i < Ilosc_Napisow; i++)
	{
		okno.draw(menu[i]);
	}
}

void Menu::ruch_do_gory(int ilosc_linijek)
{
	if (wybrany_obiekt - 1 >= 0)
	{
		menu[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt--;
		menu[wybrany_obiekt].setFillColor(Color::Red);
	}
	else
	{
		menu[ilosc_linijek-1].setFillColor(Color::Red);
		menu[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt= ilosc_linijek - 1;
	}
}
void Menu::ruch_w_dol(int ilosc_linijek) 
{
	if (wybrany_obiekt + 1 <= (ilosc_linijek-1))
	{
		menu[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt++;
		menu[wybrany_obiekt].setFillColor(Color::Red);
	}
	else
	{
		menu[0].setFillColor(Color::Red);
		menu[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt = 0;
	}
}

int Menu::ktory_teraz()
{
	return wybrany_obiekt;
}
