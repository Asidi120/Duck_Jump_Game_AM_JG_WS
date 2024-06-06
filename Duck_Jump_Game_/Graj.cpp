#include "Graj.h"
#include "Kaczuszka.h"
#include "Klocki.h"
Graj::Graj()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("GRA");
	tytul.setCharacterSize(40);
}

Graj::~Graj() {}

void Graj::rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka,Graj* graj)
{
	okno.draw(tlo);
	okno.draw(tytul);
	kloce.rys_podloga(okno);
	if(czy_rysowac_klocki) //czemu do cholery rysuje sie jeden dodatkowy klocek, trzeba poprawic
	{
		kloce.rys_klocki(okno,*graj);
	}
	okno.draw(kloce.klocki[0][0]);
	for (int k = 0; k < 10; k++)
	{
		for (int i = 0; i < 2; i++)
		{
			okno.draw(kloce.klocki[i][k]);
		}
	}
	kloce.ruch_klockow();
	if (205 <= kloce.klocki[0][kloce.j].getPosition().y)
	{
		czy_rysowac_klocki = 1;
		kloce.j++;
	}
	kaczuszka->czy_jest_na_ziemi(&kloce);
	kaczuszka->rysuj_gracza(okno);
}

void Graj::co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka)
{
	while (okno.pollEvent(event_gra))
	{
		if (event_gra.type == Event::Closed)
		{
			okno.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			czy_graj_wlaczone = 0;
			break;
		}
	}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			kaczuszka->ruch(-1, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			kaczuszka->ruch(1,0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space)) && (czas_milisekundy() - czas_przycisku>200))
		{
			czas_przycisku = czas_milisekundy();
			kaczuszka->czy_skok = true;
		}	

		if (kaczuszka->czy_skok)
		{
				kaczuszka->skok_kaczuchy();
		}
}

long long Graj::czas_milisekundy()
{
	// Get the current time from the system clock
	auto now = chrono::system_clock::now();
	// Convert the current time to time since epoch
	auto duration = now.time_since_epoch();
	// Convert duration to milliseconds
	auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
	return milliseconds;

}

int Graj::ustaw_czas()
{
	czas = czas_gry.getElapsedTime();
	int minuty = static_cast<int>(czas.asSeconds()) / 60; //sekundy
	int sekundy = static_cast<int>(czas.asSeconds()) % 60; //minuty
	int mikrosekundy = static_cast<int>(czas.asMicroseconds());
	//cout << "czas: min:"<<minuty<<" czas sec: "<<sekundy<<endl;
	return mikrosekundy;
}
