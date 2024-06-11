#pragma once
#include "Gra.h"
#include "Graj.h"
#include "Klocki.h"
#include "Animacja.h"
class Klocki;
class Animacja;
class Kaczuszka
{
	Vector2f rozmiary_kaczuszki{};
	bool czy_na_ziemi=1;
	bool czy_glowa_w_prawo = 1;
	float rob = false;
	int skok_wysokosc_skoku = 220, skok_aktuala_poz = 0, skok_stopien = 15;
	Vector2f wsp_klockow[2][10]{}; //pozycja klockow
	float eps = 8;
	int ktore_j = 0;
	Vector2f wsp_kaczuszki{};
	IntRect zmiana_kaczki;
	bool czy_mozna_liczyc_rzad_pkt[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int ktory_rzad=0;
	float podloga_y = 0;
public:
	int ktora_tekstura = 0;
	float przyspieszenie_skoku{};
	Animacja animacja;
	Texture tekstura_kaczuszka;
	Texture tekstura_kaczuszka_lewo;
	Texture tekstura_kaczuszka_A;
	Texture tekstura_kaczuszka_lewo_A;
	Texture tekstura_kaczuszka_K;
	Texture tekstura_kaczuszka_lewo_K;
	Texture tekstura_kaczuszka_W;
	Texture tekstura_kaczuszka_lewo_W;
	float punkty = 0;
	float predkosc_kaczuchy = 0.5f;
	RectangleShape kaczuszka;
	int skok_kierunek=1;
	bool czy_skok = false;
	void zmiana_obrazka(Graj& graj);
	Kaczuszka();
	virtual ~Kaczuszka();
	void rysuj_gracza(RenderWindow& okno);
	void ruch(float kierunek_x,float kierunek_y);
	bool kaczuszka_y(int i, int j);
	bool kaczuszka_x(int i, int j, Klocki* kloce);
	bool czy_jest_na_ziemi(Klocki* kloce);
	void czy_dotyka_chlebka(Klocki* kloce);
	void skok_kaczuchy();
	void ruch_gdy_na_ziemi(RenderWindow& okno, Klocki* kloce, Graj* graj);
	void przesuwanie_o_50_pikseli_w_dol(RenderWindow& okno, Klocki* kloce, Graj* graj);
	bool czy_podloga(Klocki* kloce);
	void liczenie_punktow(Klocki* kloce);
	float punkty_liczenie(Klocki* kloce);
};

