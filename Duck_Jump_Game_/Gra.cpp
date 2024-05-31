#include "Gra.h"
#include "Menu.h"

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

Gra::~Gra() //dekstruktor - usuwa okienko
{
    delete okno;
}

const bool Gra::czyGraOtwarta() const
{
    return  okno->isOpen();
}
void Gra::ustaw_menu(Menu* menu) 
{
    this->menu = menu;
}

void Gra::aktualizuj() //co robi okienko, czy zamyka sie, czy nie
{
    while (okno->pollEvent(evnt)) //zbiera co sie aktualnie dzieje
    {
        switch (evnt.type)
        {
        case Event::Closed:
            okno->close(); //po nacisnieciu przycisku x okno sie zamknie
            break;

        case Event::KeyPressed:
            if (evnt.key.code == Keyboard::Escape) //po nacisnieciu klawiszu esc okno sie zamknie
            {
                okno->close();
            }
            if (evnt.key.code == Keyboard::Down)
            {
                menu->ruch_w_dol();
                cout << "klikam";
            }
            if (evnt.key.code == Keyboard::Up)
            {
                menu->ruch_do_gory();
                cout << "To tez";
            }
        break;
        }
        okno->clear(); //czysci stare okno
        menu->rysuj_menu(*okno);
        okno->display(); //koniec renderingu
    }
}
