#include "Klocki.h"
#include "Graj.h"
class Graj;
Klocki::Klocki() //ustawia podloge i klocki (wielkosc, tekstura itd)
{
	podloga.setSize(Vector2f(650.f, 175.0f));
	rozmiary_podlogi = podloga.getSize();
	podloga.setPosition(Vector2f(static_cast<float>((650 - rozmiary_podlogi.x) / 2), float(900 - rozmiary_podlogi.y+8)));
	tekstura_podloga.loadFromFile("podloga_tekst.png");
	tekstura_podloga.setSmooth(1);
	podloga.setTexture(&tekstura_podloga);
	tekstura_klocki.loadFromFile("materac_testura.png");
	for (int k = 0; k < 10; k++) //klocki to tablica dwuwymiarowa [ilosc w rzedzie 1 lub 2][10 poziomow]
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

void Klocki::ruch_klockow(Graj& graj)  //klocki oraz podloga poruszaja sie w dol
{
	for (int k = 0; k < 10; k++)
	{
		for (int i=0; i < Ilosc_Klockow_wys; i++)
		{
			klocki[i][k].move(0, 0.5);
			podloga.move(0,  0.004);
		}
	}
}

void Klocki::rys_klocki(RenderWindow& okno, Graj& graj) 
{
	if (j == 10) j = 0;
	if (j < 10)
	{
		losowanie = rand() % 5; //20% szans ze beda 2 pontony
		if (losowanie==4)
		{
			ile = 2;
		}
		else
		{
			ile = 1;
		}
		if (pierwszy_rzad)
		{
			koordynaty_y = 0.f;	
		}
		else
		{
			if (j == 0)
			{
				koordynaty_y = klocki[0][9].getPosition().y - 200.f;
			}
			else
			{
				koordynaty_y=klocki[0][j - 1].getPosition().y - 200.f;
			}
		}
		
		for(int i = 0; i < ile; i++)
		{
			koordynaty_x = static_cast<float>(rand() % static_cast<int>(650 - rozmiar_klockow.x + 1)); //losowanie pozycji x
			klocki[i][j].setPosition(koordynaty_x, koordynaty_y);

			while (i>0 && (abs(klocki[i][j].getPosition().x -klocki[i-1][j].getPosition().x)<=rozmiar_klockow.x)) //gdyby klocki nachodzily na siebie
			{
				koordynaty_x = static_cast<float>(rand() % static_cast<int>(650 - rozmiar_klockow.x + 1)); //ponowne losowanie pozycji x
				klocki[i][j].setPosition(koordynaty_x, koordynaty_y);
			}
		}
		if (j == 1) //ustawienie pierwszego rzedu od nowej dawki klockow
		{
			pierwszy_rzad = 0;
		}
		graj.czy_rysowac_klocki = 0; //he?
	}
}

void Klocki::rys_podloga(RenderWindow& okno) //rysuje podloge
{
	if (podloga.getPosition().y <= 900)
	{
		okno.draw(podloga);
	}		
}
