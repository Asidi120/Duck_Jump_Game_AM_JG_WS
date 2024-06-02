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
	float przemieszczenie_x = 12.f;
	if (kierunek_x == 1 && kierunek_y == 0)
	{
		if (kaczuszka.getPosition().x >= 610)
		{
			kaczuszka.setPosition(Vector2f((0.f-(kaczuszka.getSize().x)), kaczuszka.getPosition().y));
			kaczuszka.move(przemieszczenie_x, 0.f);
		}
		else
		{
			kaczuszka.move(przemieszczenie_x, 0.f);
		}
	}
	if (kierunek_x == -1 && kierunek_y == 0)
	{
		if (kaczuszka.getPosition().x <= (0-kaczuszka.getSize().x)+40)
		{
			kaczuszka.setPosition(Vector2f(650.f, kaczuszka.getPosition().y));
		}
		kaczuszka.move(-przemieszczenie_x, 0.f);
	}
}