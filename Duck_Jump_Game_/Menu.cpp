#include "Menu.h"
#include "Gra.h"

Menu::Menu()
{
	if (!czcionka.loadFromFile("Asul-Regular.ttf"))
	{
		cout << "Blad czcionki" << endl;
	}
	if (!tekstura_tla.loadFromFile("rybka.png", IntRect(0, 0, 1000, 1000)))
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
	menu[0].setFillColor(Color::Cyan);
	menu[0].setString("Graj");
	menu[0].setCharacterSize(28);
	menu[0].setPosition(Vector2f(300,350));

	menu[1].setFont(czcionka);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Postacie");
	menu[1].setPosition(Vector2f(270,450));

	menu[2].setFont(czcionka);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Ustawienia");
	menu[2].setPosition(Vector2f(255,550));

	menu[3].setFont(czcionka);
	menu[3].setFillColor(Color::White);
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

void Menu::ruch_do_gory() 
{
	if (wybrany_obiekt - 1 >= 0)
	{
		menu[wybrany_obiekt].setFillColor(Color::White);
		wybrany_obiekt--;
		menu[wybrany_obiekt].setFillColor(Color::Cyan);
		cout << "do gory";
	}
	else
	{
		menu[3].setFillColor(Color::Cyan);
		menu[wybrany_obiekt].setFillColor(Color::White);
		wybrany_obiekt=3;
	}
}
void Menu::ruch_w_dol() 
{
	if (wybrany_obiekt + 1 <= 3)
	{
		menu[wybrany_obiekt].setFillColor(Color::White);
		wybrany_obiekt++;
		menu[wybrany_obiekt].setFillColor(Color::Cyan);
	}
	else
	{
		menu[0].setFillColor(Color::Cyan);
		menu[wybrany_obiekt].setFillColor(Color::White);
		wybrany_obiekt = 0;
	}
}
