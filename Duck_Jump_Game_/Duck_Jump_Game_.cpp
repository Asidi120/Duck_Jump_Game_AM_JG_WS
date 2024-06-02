#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"
#include "Zasady.h"
#include "Graj.h"
#include "Postacie_sklep.h"

int main()
{
    Gra gra; //konstruktor tworzy okno
    RenderWindow* okno = gra.wskdookna(); //ustawienie wskaznika do okna
    Menu menu;
    Ustawienia ustawienia;
    Zasady zasady;
    Postacie_sklep postacie_sklep;
    Graj graj;
    gra.ustaw(&menu, &ustawienia, &zasady, &postacie_sklep, &graj); //ustawienie wskaznikow 
    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
    }
    delete okno;
    return 0;
}