#include "Kaczuszka.h"
#define Ilosc_klockow 4

void Kaczuszka::zmiana_obrazka(Graj& graj)
{
	if (animacja.czy_zmienic(graj))
	{
		animacja.aktualna_klatka = (animacja.aktualna_klatka + 1) % animacja.ilosc_obrazkow;
		if (ktora_tekstura == 2)
		{
			animacja.wysokosc_obrazka = 29;
			kaczuszka.setTextureRect(IntRect(animacja.aktualna_klatka * animacja.szerokosc_obrazka,0, animacja.szerokosc_obrazka, animacja.wysokosc_obrazka));
			kaczuszka.setSize(Vector2f(60, 96));
		}
		else if(ktora_tekstura == 1)
		{
			animacja.wysokosc_obrazka = 29;
			kaczuszka.setTextureRect(IntRect(animacja.aktualna_klatka * animacja.szerokosc_obrazka, 0, animacja.szerokosc_obrazka, animacja.wysokosc_obrazka));
			kaczuszka.setSize(Vector2f(60, 96));
		}
		else if (ktora_tekstura == 3)
		{
			animacja.wysokosc_obrazka = 23;
			kaczuszka.setTextureRect(IntRect(animacja.aktualna_klatka * (animacja.szerokosc_obrazka + 1), 6, animacja.szerokosc_obrazka + 1, animacja.wysokosc_obrazka));
			kaczuszka.setSize(Vector2f(60, 80));
		}
		else
		{
			animacja.wysokosc_obrazka = 23;
			kaczuszka.setTextureRect(IntRect(animacja.aktualna_klatka * (animacja.szerokosc_obrazka), 6, animacja.szerokosc_obrazka, animacja.wysokosc_obrazka));
			kaczuszka.setSize(Vector2f(60, 80));
		}
		//animacja.i++;
	}
}

Kaczuszka::Kaczuszka()
{
	kaczuszka.setSize(Vector2f(60.0f,80.0f));
	rozmiary_kaczuszki = kaczuszka.getSize();
	kaczuszka.setPosition(Vector2f(static_cast<float>((650-rozmiary_kaczuszki.x)/2),float(900-rozmiary_kaczuszki.y-150)));
	tekstura_kaczuszka.loadFromFile("kaczucha_prawo.png");
	tekstura_kaczuszka_lewo.loadFromFile("kaczucha.png");
	tekstura_kaczuszka_K.loadFromFile("kaczucha_prawo_Kuba.png");
	tekstura_kaczuszka_lewo_K.loadFromFile("kaczucha_Kuba.png");
	tekstura_kaczuszka_W.loadFromFile("kaczucha_prawo_Weronika.png");
	tekstura_kaczuszka_lewo_W.loadFromFile("kaczucha_Weronika.png");
	tekstura_kaczuszka_A.loadFromFile("kaczucha_prawo_Agnieszka.png");
	tekstura_kaczuszka_lewo_A.loadFromFile("kaczucha_Agnieszka.png");
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

bool Kaczuszka::kaczuszka_y(int i, int j) //wykrywa kiedy kaczuszka jest na klockach wzgl y
{
	bool wynik;
	float dolna_krawedz_kaczuszki = kaczuszka.getPosition().y + kaczuszka.getSize().y;
	float gorna_krawedz_klocka = wsp_klockow[i][j].y+20;
	wynik=(dolna_krawedz_kaczuszki >= gorna_krawedz_klocka - eps) && (dolna_krawedz_kaczuszki <= gorna_krawedz_klocka + eps);
	if (wynik == 1)
	{
		kaczuszka.setPosition(kaczuszka.getPosition().x, gorna_krawedz_klocka-kaczuszka.getSize().y);
	}
	return wynik;
}
bool Kaczuszka::kaczuszka_x(int i, int j, Klocki* kloce) //wykrywa kiedy kaczuszka jest na klockach wzgl x
{
	bool wynik;
	wynik = wsp_klockow[i][j].x + kloce->rozmiar_klockow.x >= kaczuszka.getPosition().x+20 && wsp_klockow[i][j].x - rozmiary_kaczuszki.x <= kaczuszka.getPosition().x-20;
	return wynik;
}

bool Kaczuszka::czy_podloga(Klocki* kloce) //wykrywa kiedy kaczuszka jest na podlodze z tolerancja 
{
	bool wynik;
	float dolna_krawedz_kaczuszki = kaczuszka.getPosition().y + kaczuszka.getSize().y;
	float gorna_krawedz_podlogi = kloce->podloga.getPosition().y + 20;
	wynik = (dolna_krawedz_kaczuszki >= gorna_krawedz_podlogi - (eps+8)) && (dolna_krawedz_kaczuszki <= gorna_krawedz_podlogi + (eps+8));
	if (wynik == 1)
	{
		kaczuszka.setPosition(kaczuszka.getPosition().x, gorna_krawedz_podlogi - kaczuszka.getSize().y);
	}
	return wynik;
}

void Kaczuszka::liczenie_punktow(Klocki* kloce)
{
		if (czy_na_ziemi && czy_podloga(kloce) == 0)
		{
			if (ktory_rzad == 0)
			{
				for (int k = 1; k < 6; k++)
				{
					czy_mozna_liczyc_rzad_pkt[k] = 1;
				}
			}
			if (ktory_rzad == 5)
			{
				for (int k = 6; k < 10; k++)
				{
					czy_mozna_liczyc_rzad_pkt[k] = 1;
				}
				czy_mozna_liczyc_rzad_pkt[0] = 1;
			}
			if (czy_mozna_liczyc_rzad_pkt[ktory_rzad] == 1)
			{
				czy_mozna_liczyc_rzad_pkt[ktory_rzad] = 0;
				kloce->ktory_teraz++;
			}
		}

}

bool Kaczuszka::czy_jest_na_ziemi(Klocki* kloce) //wykrywa kiedy kaczuszka jest na klockach tylko wtedy jak spada z tolerancja
{
	czy_na_ziemi = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			wsp_klockow[i][j] = kloce->klocki[i][j].getPosition();
			if (((kaczuszka_x(i,j,kloce) && kaczuszka_y(i,j) && skok_kierunek==-1) || (kaczuszka_x(i, j, kloce) && kaczuszka_y(i, j) && czy_skok==false)) || czy_podloga(kloce)) //spada || nie skacze || jest na podlodze
			{
				czy_na_ziemi = 1;
				ktory_rzad = j;
				break;
			}
		}
	}
	return czy_na_ziemi;
}

void Kaczuszka::czy_dotyka_chlebka(Klocki* kloce)
{
	bool pozycja_x = kloce->chlebek.chlebek.getPosition().x <= kaczuszka.getPosition().x + rozmiary_kaczuszki.x && kloce->chlebek.chlebek.getPosition().x + kloce->chlebek.rozmiary_chlebek.x >= kaczuszka.getPosition().x;
	bool pozycja_y = kaczuszka.getPosition().y+rozmiary_kaczuszki.y>= kloce->chlebek.chlebek.getPosition().y && kloce->chlebek.chlebek.getPosition().y+ kloce->chlebek.rozmiary_chlebek.y>= kaczuszka.getPosition().y;
	if (pozycja_x && pozycja_y && kloce->chlebek.czy_rysowac)
	{
		kloce->chlebek.czy_rysowac = 0;
		kloce->chlebek.ilosc_zdobytych_chlebkow++;
		cout << kloce->chlebek.ilosc_zdobytych_chlebkow << endl;
	}
}

void Kaczuszka::skok_kaczuchy() //kinda he
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
		if ((skok_stopien <= 12 && skok_kierunek==-1) || skok_kierunek==1)
		{
			skok_stopien = ((skok_wysokosc_skoku / 10) - (skok_aktuala_poz / 10)) + 1;// zmiana szybkosci skoku wraz z jego przebiegiem
		}
		if (czy_skok == false && czy_na_ziemi == 1)
		{
			kaczuszka.move(0, float(skok_stopien * skok_kierunek));
		}
		kaczuszka.move(0, float(- skok_stopien * skok_kierunek));
}

void Kaczuszka::ruch_gdy_na_ziemi(RenderWindow& okno, Klocki* kloce,Graj* graj)
{
	if (graj->czy_pryspieszyc())
	{
		predkosc_kaczuchy += 0.0003f;
	}
	if (czy_jest_na_ziemi(kloce))
	{
		if (czy_podloga(kloce))
		{
			kaczuszka.move(0, 0.09f); //na podlodze kaczuszka porusza sie tak jak podloga (troche wolniej od klockow)
		}
		else
		{
			kaczuszka.move(0,predkosc_kaczuchy); //kaczuszka porusza sie w dol tak jak klocki 
		}
	}
	if (!czy_jest_na_ziemi(kloce) && czy_skok==false)
	{
		skok_aktuala_poz = 220;
		skok_stopien = 1;
		czy_skok = true;
	}
}

void Kaczuszka::przesuwanie_o_50_pikseli_w_dol(RenderWindow& okno, Klocki* kloce, Graj* graj)
{
	if (czy_na_ziemi == 1 && kaczuszka.getPosition().y + rozmiary_kaczuszki.y <= 300) //przesuwanie kiedy kaczucha jest w polowie wysokosci okienka
	{
		animacja.aktualna_klatka_tlo = (animacja.aktualna_klatka_tlo + 1) % animacja.ilosc_obrazkow_tlo;
		kaczuszka.move(0, 10);
		kloce->podloga.move(0,10);
		graj->tlo.setTextureRect(IntRect(0,animacja.aktualna_klatka_tlo * (animacja.wysokosc_obrazka_tlo),650,900));
		for (int k = 0; k < 10; k++)
		{
			for (int i = 0; i < 2; i++)
			{
				kloce->klocki[i][k].move(0, 3);
			}
		}
		kloce->chlebek.chlebek.move(0, 3);
	}
}

float Kaczuszka::punkty_liczenie(Klocki* kloce)
{
	if(czy_na_ziemi==1 && ktore_j<kloce->ktory_teraz)
	{
		punkty = int(kloce->ktory_teraz+1) * 86;
	}
	ktore_j = int(kloce->ktory_teraz);
	return punkty;
}