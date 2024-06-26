#include "Graj.h"
#include "Kaczuszka.h"
#include "Klocki.h"
#include "Animacja.h"
#include "Baza_Danych.h"
#include "Wyniki.h"
#include "Nazwa_gracza.h"
Graj::Graj() //ustawia napis gra
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Black);
	tytul.setString("Punkty: 0");
	tytul.setCharacterSize(40);
	tekstura_tla.setRepeated(1);

	tekst_ilosc_chlebkow.setFont(czcionka);
	tekst_ilosc_chlebkow.setFillColor(Color::Black);
	tekst_ilosc_chlebkow.setCharacterSize(40);
	tekst_ilosc_chlebkow.setPosition(450,0);
}

Graj::~Graj() {}

//tutaj odbywa rysowanie sie calej gry
void Graj::rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka,Graj* graj,Baza_Danych* baza_danych,Wyniki* wyniki)
{
	okno.draw(tlo); //rysuje tlo, tytul i podloge
	okno.draw(tytul);
	tekst_ilosc_chlebkow.setString("Chlebki: " + to_string(kloce.chlebek.ilosc_zdobytych_chlebkow));
	okno.draw(tekst_ilosc_chlebkow);
	tytul.setString("Punkty: "+ to_string(int(kaczuszka->punkty_liczenie(&graj->kloce))));
	
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
	if (kloce.chlebek.czy_rysowac)
	{
		kloce.chlebek.rys_chlebek(okno);
		kaczuszka->czy_dotyka_chlebka(&kloce);
	}
	kloce.ruch_klockow(*graj, *kaczuszka); //ruch klockow
	kaczuszka->ruch_gdy_na_ziemi(okno,&kloce,graj);
	if (205 <= kloce.klocki[0][kloce.j].getPosition().y)
	{
		czy_rysowac_klocki = 1;
		kloce.j++;
	}
	kaczuszka->przesuwanie_o_50_pikseli_w_dol(okno, &kloce, graj);
	kaczuszka->czy_jest_na_ziemi(&kloce);
	kaczuszka->liczenie_punktow(&kloce);
	kaczuszka->zmiana_obrazka(*graj);
	kaczuszka->rysuj_gracza(okno);
	
	if (kaczuszka->kaczuszka.getPosition().y >= 900) //koniec gry gdy kaczucha spadnie
	{
		cout << "GAME OVER";
		czy_graj_wlaczone = 0;
		wyniki->czy_wyniki_wlaczone = 1;
		baza_danych->wstawLubAktualizujDane(nazwa_gracza, kaczuszka->punkty_liczenie(&kloce), kloce.chlebek.ilosc_zdobytych_chlebkow);
		cout << "Top 10 najlepszych wynikow:" << endl;
		baza_danych->wypiszTop10();
	}
}
//sprawdza czy cos sie dzieje w grze (przyciski)
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
			if (kaczuszka->ktora_tekstura==0)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_lewo);
			}
			if (kaczuszka->ktora_tekstura == 1)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_lewo_A);
			}
			if (kaczuszka->ktora_tekstura == 2)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_lewo_K);
			}
			if (kaczuszka->ktora_tekstura == 3)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_lewo_W);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) //ruch w prawo
		{
			kaczuszka->ruch(1,0);
			kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka);
			if (kaczuszka->ktora_tekstura == 0)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka);
			}
			if (kaczuszka->ktora_tekstura == 1)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_A);
			}
			if (kaczuszka->ktora_tekstura == 2)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_K);
			}
			if (kaczuszka->ktora_tekstura == 3)
			{
				kaczuszka->kaczuszka.setTexture(&kaczuszka->tekstura_kaczuszka_W);
			}
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
//czas przysiskania przycisku
long long Graj::czas_milisekundy()
{
	auto teraz = chrono::system_clock::now();
	auto trwanie = teraz.time_since_epoch();
	auto milisekundy = chrono::duration_cast<chrono::milliseconds>(trwanie).count();
	return milisekundy;

}
//czas gry potrzebny do przyspieszania blokow i animacji
int Graj::ustaw_czas()
{
	czas = czas_gry.getElapsedTime();
	int sekundy = static_cast<int>(czas.asSeconds()); //sekundy w grze
	return sekundy;
}
//przyspieszanie blokow
bool Graj::czy_pryspieszyc()
{
	if (ustaw_czas() % 4 == 0)
	{
		return true;
	}
	return false;
}
