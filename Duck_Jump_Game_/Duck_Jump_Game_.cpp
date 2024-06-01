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
    gra.ustaw_menu(&menu); //ustawienie wskaznika do menu
    gra.ustaw_ustawienia(&ustawienia);
    gra.ustaw_zasady(&zasady);
    gra.ustaw_postacie_sklep(&postacie_sklep);
    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
    }
    return 0;
}