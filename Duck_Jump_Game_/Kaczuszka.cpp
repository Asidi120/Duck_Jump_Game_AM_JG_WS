#include "Kaczuszka.h"

Kaczuszka::Kaczuszka()
{
	kaczuszka.setSize(Vector2f(200.0f,200.0f));
	kaczuszka.setPosition(Vector2f(static_cast<float>(650/2),float(900-200)));
	kaczuszka.setFillColor(Color::Red);
}

Kaczuszka::~Kaczuszka() {}

void Kaczuszka::rysuj_gracza(RenderWindow& okno)
{
	okno.draw(kaczuszka);
}
