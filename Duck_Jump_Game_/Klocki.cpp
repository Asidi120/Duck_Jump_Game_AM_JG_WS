#include "Klocki.h"
#include "Graj.h"
class Graj;
Klocki::Klocki()
{
	podloga.setSize(Vector2f(650.f, 175.0f));
	rozmiary_podlogi = podloga.getSize();
	podloga.setPosition(Vector2f(static_cast<float>((650 - rozmiary_podlogi.x) / 2), float(900 - rozmiary_podlogi.y+8)));
	podloga.setFillColor(Color::Black);
	tekstura_podloga.loadFromFile("podloga_tekst.png");
	tekstura_podloga.setSmooth(1);
	podloga.setTexture(&tekstura_podloga);
	tekstura_klocki.loadFromFile("materac_testura.png");
	for (int k = 0; k < 10; k++)
	{
		for (int i = 0; i < Ilosc_Klockow; i++)
		{
		klocki[i][k].setSize(Vector2f(140.0f, 50.0f));
		klocki[i][k].setTexture(&tekstura_klocki);
		}
	}
	
	rozmiar_klockow = klocki[0][0].getSize();
}

Klocki::~Klocki() {}

void Klocki::ruch_klockow() 
{
	for (int i=0; i < Ilosc_Klockow_wys; i++)
	{
		klocki[i][j].move(0, -1);
	}
}

void Klocki::rys_klocki(RenderWindow& okno, Graj& graj)
{
	//while(j<10)
	{
		for(int i = 0; i < Ilosc_Klockow_wys; i++)
		{
			klocki[i][j].setPosition(static_cast<float>(rand() % static_cast<int>(650 - rozmiar_klockow.x + 1)), 50.f);
			okno.draw(klocki[i][j]);
		}
		graj.czy_rysowac_klocki = 0;
		if (200 <= klocki[0][j].getPosition().y)
		{
			j++;
		}
	}
}

void Klocki::rys_podloga(RenderWindow& okno)
{
	okno.draw(podloga);
}
