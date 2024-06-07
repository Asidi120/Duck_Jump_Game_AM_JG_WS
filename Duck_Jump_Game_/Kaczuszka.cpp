#include "Kaczuszka.h"
#define Ilosc_klockow 4

Kaczuszka::Kaczuszka()
{
	kaczuszka.setSize(Vector2f(60.0f,80.0f));
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

bool Kaczuszka::kaczuszka_y(int i, int j)
{
	bool wynik;
	float dolna_krawedz_kaczuszki = kaczuszka.getPosition().y + kaczuszka.getSize().y;
	float gorna_krawedz_klocka = wsp_klockow[i][j].y+20;
	wynik=(dolna_krawedz_kaczuszki >= gorna_krawedz_klocka - eps) && (dolna_krawedz_kaczuszki <= gorna_krawedz_klocka + eps);
	//cout << "Kaczuszka y: "<<wynik<<endl;
	return wynik;
}
bool Kaczuszka::kaczuszka_x(int i, int j, Klocki* kloce)
{
	bool wynik;
	wynik = wsp_klockow[i][j].x + kloce->rozmiar_klockow.x >= kaczuszka.getPosition().x && wsp_klockow[i][j].x - rozmiary_kaczuszki.x <= kaczuszka.getPosition().x;
	//cout << "Kaczuszka x: " << wynik<<endl;
	return wynik;
}

bool Kaczuszka::czy_podloga(Klocki* kloce)
{
	bool wynik;
	float dolna_krawedz_kaczuszki = kaczuszka.getPosition().y + kaczuszka.getSize().y;
	float gorna_krawedz_podlogi = kloce->podloga.getPosition().y + 20;
	wynik = (dolna_krawedz_kaczuszki >= gorna_krawedz_podlogi - (eps+8)) && (dolna_krawedz_kaczuszki <= gorna_krawedz_podlogi + (eps+8));
	return wynik;
}

bool Kaczuszka::czy_jest_na_ziemi(Klocki* kloce)
{
	czy_na_ziemi = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			wsp_klockow[i][j] = kloce->klocki[i][j].getPosition();
			if (((kaczuszka_x(i,j,kloce) && kaczuszka_y(i,j) && skok_kierunek==-1) || (kaczuszka_x(i, j, kloce) && kaczuszka_y(i, j) && czy_skok==false)) || czy_podloga(kloce))
			{
				czy_na_ziemi = 1;
				break;
			}
		}
	}
	//cout <<"Czy na ziemi: "<< czy_na_ziemi<<endl;
	return czy_na_ziemi;
}

void Kaczuszka::skok_kaczuchy()
{
		if (skok_aktuala_poz >= skok_wysokosc_skoku) // szczyt skok i nastepuje zmiana kierunku y
		{
			skok_kierunek =  -1;
		}
		if ((czy_na_ziemi == 1 && skok_kierunek == -1)) // koniec skoku i nastepuje zmiana kierunku y oraz zatrzymanie skoku
		{
			skok_kierunek = 1;
			czy_skok = false;
			skok_aktuala_poz = -20;
		}
		skok_aktuala_poz = skok_aktuala_poz + skok_stopien * skok_kierunek ;// zwiekszam pozycje skoku
		if ((skok_stopien <= 21 && skok_kierunek==-1) || skok_kierunek==1)
		{
			skok_stopien = ((skok_wysokosc_skoku / 10) - (skok_aktuala_poz / 10)) + 1;// zmiana szybkosci skoku wraz z jego przebiegiem
		}
		if (czy_skok == false && czy_na_ziemi == 1)
		{
			kaczuszka.move(0, skok_stopien * skok_kierunek);
		}
		kaczuszka.move(0, -skok_stopien * skok_kierunek);
}

void Kaczuszka::ruch_gdy_na_ziemi(RenderWindow& okno, Klocki* kloce)
{
	if (czy_jest_na_ziemi(kloce))
	{
		if (czy_podloga(kloce))
		{
			kaczuszka.move(0, 0.09);
		}
		else
		{
			kaczuszka.move(0,0.5);
		}
	}
	if (!czy_jest_na_ziemi(kloce) && czy_skok==false)
	{
		skok_aktuala_poz = 220;
		skok_stopien = 1;
		czy_skok = true;
	}
}

void Kaczuszka::przesuwanie_o_200_pikseli_w_dol(RenderWindow& okno, Klocki* kloce) //za szybko sie przesowA
{
	if (czy_na_ziemi == 1 && kaczuszka.getPosition().y + rozmiary_kaczuszki.y <= 500)
	{
		kaczuszka.move(0, 50);
		kloce->podloga.move(0, 50);
		for (int k = 0; k < 10; k++)
		{
			for (int i = 0; i < 2; i++)
			{
				kloce->klocki[i][k].move(0, 50);
			}
		}

	}
}
