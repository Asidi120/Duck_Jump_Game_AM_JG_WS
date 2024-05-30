#include "Menu.h"
#include "Gra.h"

Menu::Menu()
{
	if (!czcionka.loadFromFile("Asul-Regular.ttf"))
	{
		cout << "Error" << endl;
	}
	menu[0].setFont(czcionka);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("graj");
	menu[0].setCharacterSize(28);
	menu[0].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 1));

	menu[1].setFont(czcionka);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Postacie");
	menu[1].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 2));

	menu[2].setFont(czcionka);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Ustawienia");
	menu[2].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 3));
	menu[3].setFont(czcionka);
	menu[3].setFillColor(Color::White);
	menu[3].setString("Wyjdz");
	menu[3].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 4));
}

Menu::~Menu()
{
}

void rysuj_menu()
{
	//for (int i = 0; i < Ilosc_Napisow; i++)
	{
		//okno->draw(menu[i]);
	}
}

void Menu::ruch_do_gory()
{
}

void Menu::ruch_w_dol()
{
}
