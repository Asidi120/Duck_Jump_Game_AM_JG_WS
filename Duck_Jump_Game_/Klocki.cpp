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
	for (int k = 0; k < 10; k++)
	{
		for (int i=0; i < Ilosc_Klockow_wys; i++)
		{
			klocki[i][k].move(0, 0.5);
			podloga.move(0, 0.025);
		}
	}
	
}

void Klocki::rys_klocki(RenderWindow& okno, Graj& graj)
{
	if (j < 10)
	{
		losowanie = rand() % 5;
		if (losowanie==4)
		{
			ile = 2;
		}
		else
		{
			ile = 1;
		}
		klocki[0][j].setPosition(static_cast<float>(rand() % static_cast<int>(650 - rozmiar_klockow.x + 1)), 0.f);
		for(int i = 1; i < ile; i++)
		{
			klocki[i][j].setPosition(static_cast<float>(rand() % static_cast<int>(650 - rozmiar_klockow.x + 1)), 0.f);
			while (abs(klocki[i][j].getPosition().x -klocki[i -1][j].getPosition().x)<=rozmiar_klockow.x)
			{
				klocki[i][j].setPosition(static_cast<float>(rand() % static_cast<int>(650 - rozmiar_klockow.x + 1)), 0.f);
			}
		}
		graj.czy_rysowac_klocki = 0;
	}
	else
	{
		j = 0;
	}
}

void Klocki::rys_podloga(RenderWindow& okno)
{
	okno.draw(podloga);
}
