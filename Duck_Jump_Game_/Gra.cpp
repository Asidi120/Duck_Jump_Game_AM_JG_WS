#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"

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
    while (okno->pollEvent(evnt) && menu->czy_menu_otwarte==1) //zbiera co sie aktualnie dzieje
    {
        if (menu->czy_menu_otwarte == 1) //jezeli menu ma byc rysowane (jest otwarte)
        {
            okno->clear(); //czysci stare okno
            menu->rysuj_menu(*okno);
            okno->display(); //koniec renderingu
        }
        switch (evnt.type)
        {
        case Event::Closed:
            okno->close(); //po nacisnieciu przycisku x okno sie zamknie
            break;

        case Event::KeyPressed:
            switch (evnt.key.code)
            {
            case Keyboard::Escape://po nacisnieciu klawiszu esc okno sie zamknie
                okno->close();
                break;
            case Keyboard::Down:
                menu->ruch_w_dol(4);
                break;
            case Keyboard::Up:
                menu->ruch_do_gory(4);
                break;
            case Keyboard::Enter:
                if (menu->ktory_teraz() == 3) //przycisk wyjdz
                {
                    okno->close();
                }
                if (menu->ktory_teraz() == 2) //przycisk ustawienia
                {
                    menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do ustawien)
                    okno->clear();
                    Ustawienia ustawienia;
                    ustawienia.rysuj_ustawienia(*okno);
                    ustawienia.wylacz_wlacz_muzyka(*okno);
                    okno->display();
                }
                if (menu->ktory_teraz() == 1) //przycisk postacie
                {
                }
                if (menu->ktory_teraz() == 0) //przycisk graj
                {
                    //tu bedzie dziko
                }
                break;
            }
        break;
        }

    }

}
