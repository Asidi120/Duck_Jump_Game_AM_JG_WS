#include "Gra.h"

int main() 
{
    Gra gra; //konstruktor tworzy okno

    while (gra.czyGraOtwarta())
    {
        gra.update();
        
        gra.render();
    }
}