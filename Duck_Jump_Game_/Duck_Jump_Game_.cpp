#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"
#include "Zasady.h"
#include "Graj.h"
#include "Postacie_sklep.h"
#include "Kaczuszka.h"
#include "Klocki.h"
#include <ctime>

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    Gra gra; //konstruktor tworzy okno
    RenderWindow* okno = gra.wskdookna(); //ustawienie wskaznika do okna
    Menu menu;
    Ustawienia ustawienia;
    Zasady zasady;
    Postacie_sklep postacie_sklep;
    Graj graj;
    Kaczuszka kaczuszka;
    Klocki klocki;
    gra.ustaw(&menu, &ustawienia, &zasady, &postacie_sklep, &graj, &kaczuszka); //ustawienie wskaznikow 
    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
    }
    return 0;
}