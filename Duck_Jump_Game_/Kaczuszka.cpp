#include "Kaczuszka.h"


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
	float wysokosc_skok=100,dy=0;
	float podloga = 900-150;
	float grawitacja = 0.2;
	float skok_y = 0;
	int skok_kier = -1;
	long long przerwa = 0;
	
	if (kierunek_x == 1)
	{	
		if (x >= 605)
		{
			x=0-(kaczuszka.getSize().x);
		}
		x+= przemieszczenie_x;
	}
	if (kierunek_x == -1 && kierunek_y == 0)
	{
		if (x <= (0-kaczuszka.getSize().x)+35)
		{
			x=650;
		}
		x -= przemieszczenie_x;
	}
	if (czy_na_ziemi && kierunek_y == 1) // Zainicjuj skok
	{
		czas_skoku = 0.00001;
		rob = true;
		czy_na_ziemi = false;
		//y = 0.001;
	}

	if(rob) // Wykonaj skok
	{
		//cout << y;
		
		
		
		
		
	}

	//if (czy_jest_na_ziemi()==1 && kierunek_y == 1)
	//{
	//	if (y + 0.2 <= podloga)
	//	{
	//		czy_na_ziemi = 0;
	//		if (wysokosc_skok > y)
	//		{
	//			dy -= 0.2;
	//			y -= dy;
	//		}
	//	}
	//	if (y>=podloga)
	//	{
	//		czy_na_ziemi = 1;
	//	}
	//}
	kaczuszka.setPosition(x, y);
}

bool Kaczuszka::czy_jest_na_ziemi()
{
	//if (kaczuszka.getPosition().x == ) //tu ma byc podloga i klocki
	//{
		//czy_na_ziemi = 1;
	//}
	//else
	//{
		//czy_na_ziemi = 0;
	//}

	return czy_na_ziemi;
}

long long Kaczuszka::czas_milisekundy()
{
	// Get the current time from the system clock
	auto now = chrono::system_clock::now();
	// Convert the current time to time since epoch
	auto duration = now.time_since_epoch();
	// Convert duration to milliseconds
	auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
	return milliseconds;

}

void Kaczuszka::skok_kaczuchy()
{
	if (czy_skok)
	{
		skok_aktuala_poz = skok_aktuala_poz + skok_kierunek;// zwiekszam pozycje skoku
		if (skok_aktuala_poz >= skok_wysokosc) // szczyt skok
		{
			skok_kierunek = skok_kierunek * -1;
		}
		if (skok_aktuala_poz <= 0) // koniec skoku
		{
			skok_kierunek = skok_kierunek * -1;
			czy_skok = false;
		}
		float y = kaczuszka.getPosition().y - skok_kierunek;
		//cout << "poz y= " << skok_aktuala_poz  << " y= "<< y << endl;
		kaczuszka.setPosition(kaczuszka.getPosition().x, y);

	}


}