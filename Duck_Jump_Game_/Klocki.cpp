#include "Klocki.h"

Klocki::Klocki()
{
	podloga.setSize(Vector2f(650.f, 175.0f));
	rozmiary_podlogi = podloga.getSize();
	podloga.setPosition(Vector2f(static_cast<float>((650 - rozmiary_podlogi.x) / 2), float(900 - rozmiary_podlogi.y+8)));
	podloga.setFillColor(Color::Black);
	tekstura_podloga.loadFromFile("podloga_tekst.jpg");
	tekstura_podloga.setSmooth(1);
	podloga.setTexture(&tekstura_podloga);
	
	for (int i = 0; i < Ilosc_Klockow; i++)
	{
		klocki[i].setSize(Vector2f(130.0f, 50.0f));
		klocki[i].setFillColor(Color::Black);
	}
	rozmiar_klockow = klocki[0].getSize();
}

Klocki::~Klocki() {}

void Klocki::ruch_klockow() 
{
	for (int i=0; i < Ilosc_Klockow_wys; i++)
	{
		klocki[i].move(0,-1);
	}
}

void Klocki::rys_klocki(RenderWindow& okno)
{
	
	klocki[0].setPosition(300, 50.f);
	//static_cast<float>(rand() % static_cast<int>(900))
	okno.draw(klocki[0]);
}

void Klocki::rys_podloga(RenderWindow& okno)
{
	okno.draw(podloga);
}
