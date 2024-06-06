#include "Kaczuszka.h"
#define Ilosc_klockow 4

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
	
	if (kierunek_x == 1)
	{	
		if (x >= 605)
		{
			x=0-(kaczuszka.getSize().x);
		}
		x+= przemieszczenie_x;
	}
	if (kierunek_x == -1 )
	{
		if (x <= (0-kaczuszka.getSize().x)+35)
		{
			x=650;
		}
		x -= przemieszczenie_x;
	}
	if (czy_na_ziemi && kierunek_y == 1) // Zainicjuj skok
	{
		czy_na_ziemi = false;
	}
	kaczuszka.setPosition(x, y);
}

bool Kaczuszka::czy_jest_na_ziemi(Klocki* kloce)
{
	czy_na_ziemi = 0;
	for (int i = 1; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			wsp_klockow[i][j] = kloce->klocki[i][j].getPosition();
			if (kaczuszka.getPosition().y+kaczuszka.getSize().y == wsp_klockow[i][j].y && (wsp_klockow[i][j].x+kloce->rozmiar_klockow.x>=kaczuszka.getPosition().x && wsp_klockow[i][j].x-rozmiary_kaczuszki.x<=kaczuszka.getPosition().x))
			{
				czy_na_ziemi = 1;
				break;
			}
		}
	}
	cout<<"y: " << kloce->klocki[0][0].getPosition().y << "x: " << kloce->klocki[0][0].getPosition().x<<endl;
	return czy_na_ziemi;
}

void Kaczuszka::skok_kaczuchy()
{
		skok_aktuala_poz = skok_aktuala_poz + skok_stopien * skok_kierunek ;// zwiekszam pozycje skoku
		if (skok_aktuala_poz >= skok_wysokosc_skoku) // szczyt skok i nastepuje zmiana kierunku y
		{
			skok_kierunek =  -1;
		}
		if (skok_aktuala_poz <= 0) // koniec skoku i nastepuje zmiana kierunku y oraz zatrzymanie skoku
		{
			skok_kierunek = 1;
			czy_skok = false;
		}
		// zmiana szybkosci skoku wraz z jego przebiegiem
		skok_stopien = ((skok_wysokosc_skoku / 10) - (skok_aktuala_poz / 10)) + 1;
		float y = kaczuszka.getPosition().y - skok_stopien * skok_kierunek;
		kaczuszka.setPosition(kaczuszka.getPosition().x, y);
}