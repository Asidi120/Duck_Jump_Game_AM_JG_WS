#include "Menu.h"
#include "Gra.h"

Menu::Menu()
{
	if (!czcionka.loadFromFile("arial.ttf"))
	{
		cout << "Error" << endl;
	}

	menu[0].setFont(czcionka);
	menu[0].setColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setPosition(Vector2f(800 / 2, 600 / (Ilosc_Napisow + 1) * 1));

	menu[1].setFont(czcionka);
	menu[1].setColor(Color::White);
	menu[1].setString("Postacie");
	menu[1].setPosition(Vector2f(800 / 2, 600 / (Ilosc_Napisow + 1) * 2));

	menu[2].setFont(czcionka);
	menu[2].setColor(Color::White);
	menu[2].setString("Ustawienia");
	menu[2].setPosition(Vector2f(800 / 2, 600 / (Ilosc_Napisow + 1) * 3));

	menu[3].setFont(czcionka);
	menu[3].setColor(Color::White);
	menu[3].setString("Wyjdz");
	menu[3].setPosition(Vector2f(800 / 2, 600 / (Ilosc_Napisow + 1) * 4));
}

Menu::~Menu()
{
}

void Menu::rysuj_menu()
{
	for (int i = 0; i < Ilosc_Napisow; i++)
	{
		game.window->draw(menu[i]);
	}
}

void Menu::ruch_do_gory()
{
}

void Menu::ruch_w_dol()
{
}
