#include "Menu.h"
#include "Gra.h"

Menu::Menu(): wybrany_obiekt(0) //tworzy menu
{
	if (!czcionka.loadFromFile("GloriaHallelujah-Regular.ttf"))
	{
		cout << "Blad czcionki" << endl;
	}
	if (!tekstura_tla.loadFromFile("tlo_tekst.png"))
	{
		cout << "Blad ladowania tla" << endl;
	}
	if (!menu_tekst.loadFromFile("menu_tekst.png", IntRect(0, 0, 1000, 1000)))
	{
		cout << "Blad ladowania tla" << endl;
	}
	tekstura_tla.isSmooth();
	tlo.setTexture(tekstura_tla);
	menu_tekst.isSmooth();
	warstwa.setTexture(menu_tekst);
	warstwa.setScale(0.6f, 0.8f);
	warstwa.setPosition(Vector2f(25, 80));

	for (int i = 0;i<Ilosc_Napisow;i++)
	{
		menu[i].setFont(czcionka);
		menu[i].setFillColor(Color::Black);
		menu[i].setCharacterSize(28);
	}

	
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setPosition(Vector2f(295,280));

	menu[1].setString("Nazwa gracza");
	menu[1].setPosition(Vector2f(245, 380));

	menu[2].setString("Postacie");
	menu[2].setPosition(Vector2f(270,480));

	menu[3].setString("Ustawienia");
	menu[3].setPosition(Vector2f(255,580));

	menu[4].setString("Zasady");
	menu[4].setPosition(Vector2f(280,680));

	menu[5].setString("Wyjdz");
	menu[5].setPosition(Vector2f(290, 780));
}
Menu::~Menu() {}

//rysuje menu
void Menu::rysuj_menu(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(warstwa);
	for (int i = 0; i < Ilosc_Napisow; i++)
	{
		okno.draw(menu[i]);
	}
}
//przesuwa kolor gry strzalka do gory
int Menu::ruch_do_gory(int ilosc_linijek, Text tekst[], int wybrany_obiekt)
{
	if (wybrany_obiekt - 1 >= 0)
	{
		tekst[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt--;
		tekst[wybrany_obiekt].setFillColor(Color::Red);
	}
	else
	{
		tekst[ilosc_linijek-1].setFillColor(Color::Red);
		tekst[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt= ilosc_linijek - 1;
	}
	return wybrany_obiekt;
}

//przesuwa kolor gry strzalka w dol
int Menu::ruch_w_dol(int ilosc_linijek, Text tekst[], int wybrany_obiekt)
{
	if (wybrany_obiekt + 1 <= (ilosc_linijek-1))
	{
		tekst[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt++;
		tekst[wybrany_obiekt].setFillColor(Color::Red);
	}
	else
	{
		tekst[0].setFillColor(Color::Red);
		tekst[wybrany_obiekt].setFillColor(Color::Black);
		wybrany_obiekt = 0;
	}
	return wybrany_obiekt;
}

//sprawdza ktory obiekt jest teraz wybrany
int Menu::ktory_teraz()
{
	return wybrany_obiekt;
}
