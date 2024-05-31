#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"

int main()
{
    Gra gra; //konstruktor tworzy okno
    RenderWindow* okno = gra.wskdookna(); //ustawienie wskaznika do okna
    Menu menu;
    Ustawienia ustawienia;
    gra.ustaw_menu(&menu); //ustawienie wskaznika do menu
    gra.ustaw_ustawienia(&ustawienia);
    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
    }
    return 0;
}