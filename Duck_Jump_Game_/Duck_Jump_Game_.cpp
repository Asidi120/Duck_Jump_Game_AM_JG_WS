#include "Gra.h"
#include "Menu.h"

int main() 
{
    Gra gra; //konstruktor tworzy okno
    RenderWindow* okno = gra.wskdookna();
    Menu menu;
    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
        okno->clear(); ////czysci stare okno
        menu.rysuj_menu(*okno); 
        okno->display(); //koniec renderingu
    }
}