#include "Graj.h"
#include "Kaczuszka.h"
#include "Klocki.h"
Graj::Graj() //ustawia napis gra
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("GRA");
	tytul.setCharacterSize(40);
}

Graj::~Graj() {}

void Graj::rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka,Graj* graj)
{
	okno.draw(tlo); //rysuje tlo, tytul i podloge
	okno.draw(tytul);
	kloce.rys_podloga(okno);
	kaczuszka->punkty_liczenie(&kloce);
	if(czy_rysowac_klocki) 
	{
		kloce.rys_klocki(okno,*graj); //ustawia pozycje klockow
	}
	for (int k = 0; k < 10; k++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (kloce.klocki[i][k].getPosition().y <= 900) //rysuje klocki
			{
				okno.draw(kloce.klocki[i][k]);
			}
		}
	}
	kloce.ruch_klockow(*graj); //ruch klockow
	kaczuszka->ruch_gdy_na_ziemi(okno,&kloce,graj);
	if (205 <= kloce.klocki[0][kloce.j].getPosition().y)
	{
		czy_rysowac_klocki = 1;
		kloce.j++;
	}
	kaczuszka->przesuwanie_o_50_pikseli_w_dol(okno, &kloce, graj);
	kaczuszka->czy_jest_na_ziemi(&kloce);
	kaczuszka->liczenie_punktow(&kloce);
	kaczuszka->rysuj_gracza(okno);
	
	if (kaczuszka->kaczuszka.getPosition().y >= 900) //koniec gry gdy kaczucha spadnie
	{
		cout << "GAME OVER";
		czy_graj_wlaczone = 0;
		//czy_wyniki_wlaczone=1;
	}
}

void Graj::co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka)
{
	while (okno.pollEvent(event_gra))
	{
		if (event_gra.type == Event::Closed) //przycisk x zamyka gre
		{
			okno.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) //przycisk esc pozwala wrocic do menu
		{
			czy_graj_wlaczone = 0;
			break;
		}
	}
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) //ruch w lewo
		{
			kaczuszka->ruch(-1, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) //ruch w prawo
		{
			kaczuszka->ruch(1,0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space)) && (czas_milisekundy() - czas_przycisku>200)) //skok przy czym nie wykryje kolejnego nacisniecia przez 200milisekund
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
	int sekundy = static_cast<int>(czas.asSeconds()); //sekundy w grze
	return sekundy;
}

bool Graj::czy_pryspieszyc()
{
	if (ustaw_czas() % 4 == 0)
	{
		return true;
	}
	return false;
}
