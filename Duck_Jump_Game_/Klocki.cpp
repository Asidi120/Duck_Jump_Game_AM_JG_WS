#include "Klocki.h"

Klocki::Klocki()
{
	podloga.setSize(Vector2f(120.0f, 135.0f));
	rozmiary_podlogi = podloga.getSize();
	podloga.setPosition(Vector2f(static_cast<float>((650 - rozmiary_podlogi.x) / 2), float(900 - rozmiary_podlogi.y - 150)));
	podloga.setFillColor(Color::Black);
}

Klocki::~Klocki() {}

void Klocki::ruch_klockow() {}
