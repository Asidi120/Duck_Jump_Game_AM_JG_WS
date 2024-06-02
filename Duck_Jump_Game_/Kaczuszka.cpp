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
	float przemieszczenie_x = 6.f;
	float x= kaczuszka.getPosition().x, y= kaczuszka.getPosition().y;
	
	if (kierunek_x == 1)
	{	
		if (x >= 605)
		{
			x=0.f-(kaczuszka.getSize().x);
		}
		x+= przemieszczenie_x;
	}
	if (kierunek_x == -1 && kierunek_y == 0)
	{
		if (x <= (0-kaczuszka.getSize().x)+35)
		{
			x=650.f;
		}
		x -= przemieszczenie_x;
	}
	if (kierunek_x == 0 && kierunek_y == 1)
	{
		if (x <= (0 - kaczuszka.getSize().x) + 40)
		{
			kaczuszka.setPosition(Vector2f(650.f, kaczuszka.getPosition().y));
		}
	}
	kaczuszka.setPosition(x, y);
}

bool Kaczuszka::czy_jest_na_ziemi()
{
	if (kaczuszka.getPosition().x == 1) //tu ma byc podloga i klocki
	{
		czy_na_ziemi = 1;
	}
	else
	{
		czy_na_ziemi = 0;
	}

	return czy_na_ziemi;
}
