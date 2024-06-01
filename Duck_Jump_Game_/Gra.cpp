#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"
#include "Zasady.h"

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
void Gra::ustaw_ustawienia(Ustawienia* ustawienia)
{
    this->ustawienia = ustawienia;
}

void Gra::ustaw_zasady(Zasady* zasady)
{
    this->zasady = zasady;
}

void ustawienia_sie_rysuja(RenderWindow& okno, Ustawienia* ustawienia)
{
    ustawienia->czy_ustawienia_wlaczone = 1;
    while (ustawienia->czy_ustawienia_wlaczone==1)
    {
        okno.clear();
        ustawienia->rysuj_ustawienia(okno);
        ustawienia->wylacz_wlacz_muzyka(okno);
        okno.display();
    }
}

void zasady_sie_rysuja(RenderWindow& okno, Zasady* zasady)
{
    zasady->czy_zasady_wlaczone = 1;
    while (zasady->czy_zasady_wlaczone == 1)
    {
        okno.clear();
        zasady->rysuj_zasady(okno);
        zasady->co_sie_dzieje_w_zasadach(okno);
        okno.display();
    }
}

void Gra::aktualizuj() //co robi okienko, czy zamyka sie, czy nie
{
    while (menu->czy_menu_otwarte == 1)
    {
        while (okno->pollEvent(evnt)) //zbiera co sie aktualnie dzieje
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
                    menu->ruch_w_dol(5);
                    break;
                case Keyboard::Up:
                    menu->ruch_do_gory(5);
                    break;
                case Keyboard::Enter:
                    if (menu->ktory_teraz() == 4) //przycisk wyjdz
                    {
                        okno->close();
                    }
                    if (menu->ktory_teraz() == 3) //przycisk wyjdz
                    {
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do zasad)
                        zasady_sie_rysuja(*okno, zasady);
                        menu->czy_menu_otwarte = 1;
                    }
                    if (menu->ktory_teraz() == 2) //przycisk ustawienia
                    {
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do ustawien)
                        ustawienia_sie_rysuja(*okno,ustawienia);
                        menu->czy_menu_otwarte = 1;
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
}
