#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"
#include "Zasady.h"
#include "Postacie_sklep.h"
#include "Graj.h"
#include "Kaczuszka.h"
#include "Klocki.h"
#include "Baza_Danych.h"
#include "Wyniki.h"
#include "Nazwa_gracza.h"
//ustawia zmienne w odpowiednie miesce i wartosci po rozpoczenciu gry
void ustaw(Kaczuszka* kaczuszka, Graj* graj,Baza_Danych* baza_danych)
{
    if (!graj->czy_graj_wlaczone)
    {
        graj->kloce.pierwszy_rzad = 1;
        graj->kloce.ktory_teraz = 0;
        graj->kloce.predkosc_klockow=0.5f;
        kaczuszka->predkosc_kaczuchy = 0.5f;
        graj->kloce.chlebek.predkosc_chlebka = 0.5f;
        kaczuszka->punkty = 0;
        kaczuszka->przyspieszenie_skoku = 0;
        graj->kloce.chlebek.ilosc_zdobytych_chlebkow = baza_danych->pobierzChlebki(graj->nazwa_gracza);
        for (int k = 0; k < 10; k++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (graj->kloce.klocki[i][k].getPosition().y <= 900)
                {
                    graj->kloce.klocki[i][k].setPosition(650.f, 900.f);
                }
            }
        }
        graj->kloce.chlebek.chlebek.setPosition(650.f, 900.f);
        graj->kloce.podloga.setPosition(Vector2f(static_cast<float>((650 - graj->kloce.rozmiary_podlogi.x) / 2), float(900 - graj->kloce.rozmiary_podlogi.y + 8)));
        kaczuszka->kaczuszka.setPosition(Vector2f(static_cast<float>((650 - kaczuszka->kaczuszka.getSize().x) / 2), float(900 - kaczuszka->kaczuszka.getSize().y - 150)));
    }
}

Gra::Gra() //kostruktor domyslny - tworzy okienko
{  
    okno=new RenderWindow(VideoMode(650,900), "Duck Jump", Style::Titlebar | Style::Close);
    okno->setFramerateLimit(90); // max 90 fpsow
    okno->setVerticalSyncEnabled(1); // fps takie jak monitor
}

RenderWindow* Gra::wskdookna() const
{
    return okno;
}

Gra::~Gra() //dekstruktor - usuwa wszystkie wskazniki
{
    delete okno;
    delete menu;
    delete ustawienia;
    delete zasady ;
    delete postacie_sklep;
    delete graj;
    delete kaczuszka;
    delete baza_danych;
    delete wyniki;
}
//usuwa znaczniki
void Gra::ustaw(Menu* menu, Ustawienia* ustawienia, Zasady* zasady, Postacie_sklep* postacie_sklep, Graj* graj, Kaczuszka* kaczuszka,Baza_Danych* baza_danych, Wyniki* wyniki, Nazwa_gracza* nazwa_gracza)
{
    this->menu = menu;
    this->zasady = zasady;
    this->postacie_sklep = postacie_sklep;
    this->graj = graj;
    this->ustawienia = ustawienia;
    this->kaczuszka = kaczuszka;
    this->baza_danych = baza_danych;
    this->wyniki = wyniki;
    this->nazwa_gracza = nazwa_gracza;
}

const bool Gra::czyGraOtwarta() const
{
    return  okno->isOpen();
}
// rysuje czesc z menu (wejscie do ustawien)
void ustawienia_sie_rysuja(RenderWindow& okno, Ustawienia* ustawienia)
{
    ustawienia->czy_ustawienia_wlaczone = 1;
    ustawienia->wybrany_obiekt = 0;
    while (ustawienia->czy_ustawienia_wlaczone==1)
    {
        okno.clear();
        ustawienia->rysuj_ustawienia(okno);
        ustawienia->co_sie_dzieje_w_ustawieniach(okno);
        okno.display();
    }
}
// rysuje czesc z menu (wejscie do zasad)
void zasady_sie_rysuja(RenderWindow& okno, Zasady* zasady)
{
    zasady->czy_zasady_wlaczone = 1;
    while (zasady->czy_zasady_wlaczone == 1)
    {
        okno.clear();
        zasady->rysuj_zasady(okno);
        zasady->co_sie_dzieje_w_zasadach(okno);
        okno.display();
    }
}
// rysuje czesc z menu (wejscie do sklepu postaci)
void postacie_sklep_sie_rysuje(RenderWindow& okno, Postacie_sklep* postacie_sklep,Klocki* kloce,Kaczuszka* kaczuszka, Baza_Danych* baza_danych)
{
    postacie_sklep->czy_postacie_sklep_wlaczone = 1;
    postacie_sklep->wybrana = 0;
    postacie_sklep->postacie_sklep_tekst[0].setTexture(&postacie_sklep->tekstury_kaczki_swiatlo[0]);
    while (postacie_sklep->czy_postacie_sklep_wlaczone == 1)
    {
        okno.clear();
        postacie_sklep->rysuj_postacie_sklep(okno,baza_danych);
        postacie_sklep->co_sie_dzieje_w_sklepie(okno,kloce,kaczuszka);
        okno.display();
    }
}
//rysuje gre
void graj_sie_rysuje(RenderWindow& okno, Graj* graj,Kaczuszka* kaczuszka, Baza_Danych* baza_danych,Wyniki* wyniki,Nazwa_gracza* nazwa_gracza) 
{
    nazwa_gracza->zmiana_nazwy(graj);
    ustaw(kaczuszka, graj,baza_danych);
    graj->czy_graj_wlaczone = 1;
    wyniki->czy_wyniki_wlaczone = 0;
    while (graj->czy_graj_wlaczone == 1)
    {
        okno.clear();
        graj->ustaw_czas();
        graj->rysuj_graj(okno,kaczuszka,graj,baza_danych,wyniki);
        graj->co_sie_dzieje_w_grze(okno,kaczuszka);
        okno.display();
    }
    wyniki->wynik_i_naj_wynik[0].setString("Twoj wynik: " + wyniki->wypisz_punkty(kaczuszka, &graj->kloce));
    wyniki->wynik_i_naj_wynik[1].setString("Najlepszy wynik: " + to_string(baza_danych->pobierzWynik(graj->nazwa_gracza)));
    while (wyniki->czy_wyniki_wlaczone)
    {
        ustaw(kaczuszka, graj, baza_danych);
        okno.clear();
        wyniki->rysuj_wyniki(okno,baza_danych);
        wyniki->co_sie_dzieje_w_wynikach(okno,graj);
        okno.display();
    }
}
// rysuje czesc z menu (wejscie do zmiany nazwy)
void nazwa_gracza_sie_rysuje(RenderWindow& okno, Nazwa_gracza* nazwa_gracza, Baza_Danych* baza_danych) 
{
    nazwa_gracza->czy_nazwa_gracza_wlaczone = 1;
    nazwa_gracza->nazwa_gracza_tekst[0].setString("Nazwa gracza: " + nazwa_gracza->ustaw_nazwe_gracza(baza_danych));
    while (nazwa_gracza->czy_nazwa_gracza_wlaczone)
    {
        okno.clear();
        nazwa_gracza->rysuj_nazwa_gracza(okno);
        nazwa_gracza->co_sie_dzieje_w_nazwa_gracza(okno);
        okno.display();
    }
}

void Gra::aktualizuj() //co robi okienko, czy zamyka sie, czy nie
{
    while (menu->czy_menu_otwarte == 1)
    {
        while (okno->pollEvent(evnt)) //zbiera co sie aktualnie dzieje
        {
            if (menu->czy_menu_otwarte == 1) //jezeli menu ma byc rysowane (jest otwarte)
            {
                okno->clear(); //czysci stare okno
                menu->rysuj_menu(*okno);
                okno->display(); //koniec renderingu
            }
            switch (evnt.type)
            {
            case Event::Closed:
                okno->close(); //po nacisnieciu przycisku x okno sie zamknie
                break;

            case Event::KeyPressed:
                switch (evnt.key.code)
                {
                case Keyboard::Escape://po nacisnieciu klawiszu esc okno sie zamknie
                    okno->close();
                    break;
                case Keyboard::Down:
                    menu->wybrany_obiekt = menu->ruch_w_dol(Ilosc_Napisow, menu->menu, menu->wybrany_obiekt);
                    break;
                case Keyboard::Up:
                    menu->wybrany_obiekt = menu->ruch_do_gory(Ilosc_Napisow, menu->menu, menu->wybrany_obiekt);
                    break;
                case Keyboard::Enter:
                    if (menu->ktory_teraz() == 5) //przycisk wyjdz
                    {
                        okno->close();
                    }
                    if (menu->ktory_teraz() == 4) //przycisk zasady
                    {
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do zasad)
                        
                        zasady_sie_rysuja(*okno, zasady);
                        menu->czy_menu_otwarte = 1;
                    }
                    if (menu->ktory_teraz() == 3) //przycisk ustawienia
                    {
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do ustawien)
                        ustawienia_sie_rysuja(*okno,ustawienia);
                        menu->czy_menu_otwarte = 1;
                    }
                    if (menu->ktory_teraz() == 2) //przycisk postacie
                    {
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do postaci)
                        postacie_sklep_sie_rysuje(*okno, postacie_sklep,&graj->kloce,kaczuszka,baza_danych);
                        menu->czy_menu_otwarte = 1;
                    }
                    if (menu->ktory_teraz() == 1) //przycisk nazwa gracza
                    {
                        menu->czy_menu_otwarte = 0;
                        nazwa_gracza_sie_rysuje(*okno, nazwa_gracza, baza_danych);
                        menu->czy_menu_otwarte = 1;
                    }
                    if (menu->ktory_teraz() == 0) //przycisk graj
                    {
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do gry)
                        graj->czas_gry.restart();
                        system("cls");
                        graj_sie_rysuje(*okno, graj,kaczuszka, baza_danych,wyniki,nazwa_gracza);
                        menu->czy_menu_otwarte = 1;
                    }
                    break;
                }
            break;
            }
        }
    if (graj->czy_graj_wlaczone) //odpala graj ponownie po kliknieciu zagraj ponownie
    {
        system("cls");
        graj_sie_rysuje(*okno, graj, kaczuszka, baza_danych, wyniki,nazwa_gracza);
    }
    }
    
}

