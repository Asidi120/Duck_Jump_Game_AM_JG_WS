#include "Chlebek.h"

Chlebek::Chlebek() 
{
	chlebek.setSize(Vector2f(20.0f, 20.0f));
	rozmiary_chlebek = chlebek.getSize();
	tekstura_chlebek.loadFromFile("chlebek_tekst.png");
	chlebek.setTexture(&tekstura_chlebek);
}

Chlebek::~Chlebek() {}
