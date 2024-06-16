#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"
#include "Zasady.h"
#include "Graj.h"
#include "Postacie_sklep.h"
#include "Kaczuszka.h"
#include "Klocki.h"
#include "Baza_Danych.h"
#include "Wyniki.h"
#include <ctime>

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    const char* sciezka = R"(GRACZE.db)";
    Baza_Danych baza_danych(sciezka);
    Gra gra; //konstruktor tworzy okno
    RenderWindow* okno = gra.wskdookna(); //ustawienie wskaznika do okna
    Menu menu;
    Ustawienia ustawienia;
    Zasady zasady;
    Postacie_sklep postacie_sklep;
    Graj graj;
    Kaczuszka kaczuszka;
    Klocki klocki;
    Wyniki wyniki;
    gra.ustaw(&menu, &ustawienia, &zasady, &postacie_sklep, &graj, &kaczuszka, &baza_danych, &wyniki); //ustawienie wskaznikow 
    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
    }
    baza_danych.wybierzDane();
    return 0;
}