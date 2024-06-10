#include "Chlebek.h"
#include "Gra.h"

Chlebek::Chlebek() 
{
	chlebek.setSize(Vector2f(45.0f, 30.0f));
	rozmiary_chlebek = chlebek.getSize();
	tekstura_chlebek.loadFromFile("chlebek_tekst.png");
	chlebek.setTexture(&tekstura_chlebek);
	chlebek.setPosition(650.f,900.f);

}

Chlebek::~Chlebek() {}

void Chlebek::rys_chlebek(RenderWindow& okno)
{
	okno.draw(chlebek);
}
