#include "Gra.h"
#include "Menu.h"

int main() 
{
    Gra gra; //konstruktor tworzy okno
    Menu menu;

    while (gra.czyGraOtwarta())
    {
        gra.aktualizuj();
        gra.rysuj();
       
    }
}