#include "Menu.h"
#include "Gra.h"

Menu::Menu()
{
	if (!czcionka.loadFromFile("Asul-Regular.ttf"))
	{
		cout << "Error" << endl;
	}
	//menu[0].setFont(czcionka);
	//menu[0].setFillColor(Color::Red);
	Text description("graj", czcionka, 20);
	menu[0].("graj", czcionka, 20);
	description.setPosition(10, 530);
	description.setFillColor(sf::Color(80, 80, 80));
	description
	//menu[0].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 1));

	//menu[1].setFont(czcionka);
	//menu[1].setFillColor(Color::White);
	//menu[1].setString("Postacie");
	//menu[1].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 2));

	//menu[2].setFont(czcionka);
	//menu[2].setFillColor(Color::White);
	//menu[2].setString("Ustawienia");
	//menu[2].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 3));
	//menu[3].setFont(czcionka);
	//menu[3].setFillColor(Color::White);
	//menu[3].setString("Wyjdz");
	//menu[3].setPosition(Vector2f(650 / 2, 900 / (Ilosc_Napisow + 1) * 4));
}

Menu::~Menu()
{
}

void rysuj_menu(Menu kook)
{
	kook.okno->draw(kook.);
	//for (int i = 0; i < kook.Ilosc_Napisow; i++)
	//{
		//kook.okno->draw(kook.menu[i]);
	//}
}

void Menu::ruch_do_gory()
{
}

void Menu::ruch_w_dol()
{
}
