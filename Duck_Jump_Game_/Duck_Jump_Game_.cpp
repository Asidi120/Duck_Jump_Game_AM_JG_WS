#include "Gra.h"
#include "Menu.h"

int main()
{
    Gra gra; //konstruktor tworzy okno
    RenderWindow* okno = gra.wskdookna();
    Menu menu;
    gra.ustaw_menu(&menu); //ustawienie wskaznika do menu
    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
    }
    return 0;
}