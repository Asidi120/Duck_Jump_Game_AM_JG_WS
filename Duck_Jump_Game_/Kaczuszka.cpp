#include "Kaczuszka.h"

Kaczuszka::Kaczuszka()
{
	kaczuszka.setSize(Vector2f(120.0f,135.0f));
	rozmiary_kaczuszki = kaczuszka.getSize();
	kaczuszka.setPosition(Vector2f(static_cast<float>((650-rozmiary_kaczuszki.x)/2),float(900-rozmiary_kaczuszki.y-150)));
	tekstura_kaczuszka.loadFromFile("kaczucha.png");
	kaczuszka.setTexture(&tekstura_kaczuszka);
}

Kaczuszka::~Kaczuszka() {}

void Kaczuszka::rysuj_gracza(RenderWindow& okno)
{
	okno.draw(kaczuszka);
}

void Kaczuszka::ruch(float kierunek_x, float kierunek_y)
{
	float przemieszczenie_x = 6;
	float x= kaczuszka.getPosition().x, y= kaczuszka.getPosition().y;
	float wysokosc_skok=200,dy=0;
	float podloga = 900-150;
	float grawitacja = 0.2;
	
	if (kierunek_x == 1)
	{	
		if (x >= 605)
		{
			x=0-(kaczuszka.getSize().x);
		}
		x+= przemieszczenie_x;
	}
	if (kierunek_x == -1 && kierunek_y == 0)
	{
		if (x <= (0-kaczuszka.getSize().x)+35)
		{
			x=650;
		}
		x -= przemieszczenie_x;
	}
	if (czy_na_ziemi && kierunek_y == 1) // Zainicjuj skok
	{
		czas_skoku = 0.00001;
		rob = true;
		czy_na_ziemi = false;
		y = y-0.001;
	}

	if(rob) // Wykonaj skok
	{
		y =y- 0.5 * przyspieszenie_ziemskie * czas_skoku*czas_skoku;
		czas_skoku += 0.01;
		if (y <= podloga)
		{
			rob = false;
			czy_na_ziemi = true;
		}
	}

	//if (czy_jest_na_ziemi()==1 && kierunek_y == 1)
	//{
	//	if (y + 0.2 <= podloga)
	//	{
	//		czy_na_ziemi = 0;
	//		if (wysokosc_skok > y)
	//		{
	//			dy -= 0.2;
	//			y -= dy;
	//		}
	//	}
	//	if (y>=podloga)
	//	{
	//		czy_na_ziemi = 1;
	//	}
	//}
	kaczuszka.setPosition(x, y);
}

bool Kaczuszka::czy_jest_na_ziemi()
{
	//if (kaczuszka.getPosition().x == ) //tu ma byc podloga i klocki
	//{
		//czy_na_ziemi = 1;
	//}
	//else
	//{
		//czy_na_ziemi = 0;
	//}

	return czy_na_ziemi;
}
