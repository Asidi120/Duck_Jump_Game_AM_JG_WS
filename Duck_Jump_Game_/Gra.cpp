#include "Gra.h"
#include "Menu.h"
#include "Ustawienia.h"
#include "Zasady.h"
#include "Postacie_sklep.h"
#include "Graj.h"
#include "Kaczuszka.h"
#include "Klocki.h"
void ustaw(Kaczuszka* kaczuszka, Graj* graj)
{
    if (!graj->czy_graj_wlaczone)
    {
        graj->kloce.pierwszy_rzad = 1;
        //czy_wyniki_wlaczone=1;
        graj->kloce.ktory_teraz = 0;
        graj->kloce.predkosc_klockow=0.5f;
        kaczuszka->predkosc_kaczuchy = 0.5f;
        for (int k = 0; k < 10; k++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (graj->kloce.klocki[i][k].getPosition().y <= 900)
                {
                    graj->kloce.klocki[i][k].setPosition(650.f, 900.f);
                }
            }
        }
        graj->kloce.podloga.setPosition(Vector2f(static_cast<float>((650 - graj->kloce.rozmiary_podlogi.x) / 2), float(900 - graj->kloce.rozmiary_podlogi.y + 8)));
        kaczuszka->kaczuszka.setPosition(Vector2f(static_cast<float>((650 - kaczuszka->kaczuszka.getSize().x) / 2), float(900 - kaczuszka->kaczuszka.getSize().y - 150)));
    }
}

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

Gra::~Gra() //dekstruktor - usuwa wszystkie wskazniki
{
    delete okno;
    delete menu;
    delete ustawienia;
    delete zasady ;
    delete postacie_sklep;
    delete graj;
    delete kaczuszka;
}
void Gra::ustaw(Menu* menu, Ustawienia* ustawienia, Zasady* zasady, Postacie_sklep* postacie_sklep, Graj* graj, Kaczuszka* kaczuszka)
{
    this->menu = menu;
    this->zasady = zasady;
    this->postacie_sklep = postacie_sklep;
    this->graj = graj;
    this->ustawienia = ustawienia;
    this->kaczuszka = kaczuszka;
}

const bool Gra::czyGraOtwarta() const
{
    return  okno->isOpen();
}
void ustawienia_sie_rysuja(RenderWindow& okno, Ustawienia* ustawienia)
{
    ustawienia->czy_ustawienia_wlaczone = 1;
    ustawienia->wybrany_obiekt = 0;
    while (ustawienia->czy_ustawienia_wlaczone==1)
    {
        okno.clear();
        ustawienia->rysuj_ustawienia(okno);
        ustawienia->co_sie_dzieje_w_ustawieniach(okno);
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
void postacie_sklep_sie_rysuje(RenderWindow& okno, Postacie_sklep* postacie_sklep)
{
    postacie_sklep->czy_postacie_sklep_wlaczone = 1;
    while (postacie_sklep->czy_postacie_sklep_wlaczone == 1)
    {
        okno.clear();
        postacie_sklep->rysuj_postacie_sklep(okno);
        postacie_sklep->co_sie_dzieje_w_sklepie(okno);
        okno.display();
    }
}
void graj_sie_rysuje(RenderWindow& okno, Graj* graj,Kaczuszka* kaczuszka)
{
    ustaw(kaczuszka, graj);
    graj->czy_graj_wlaczone = 1;
    while (graj->czy_graj_wlaczone == 1)
    {
        okno.clear();
        graj->ustaw_czas();
        graj->rysuj_graj(okno,kaczuszka,graj);
        graj->co_sie_dzieje_w_grze(okno,kaczuszka);
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
                    menu->wybrany_obiekt = menu->ruch_w_dol(5, menu->menu, menu->wybrany_obiekt);
                    break;
                case Keyboard::Up:
                    menu->wybrany_obiekt = menu->ruch_do_gory(5, menu->menu, menu->wybrany_obiekt);
                    break;
                case Keyboard::Enter:
                    if (menu->ktory_teraz() == 4) //przycisk wyjdz
                    {
                        okno->close();
                    }
                    if (menu->ktory_teraz() == 3) //przycisk zasady
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
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do postaci)
                        postacie_sklep_sie_rysuje(*okno, postacie_sklep);
                        menu->czy_menu_otwarte = 1;
                    }
                    if (menu->ktory_teraz() == 0) //przycisk graj
                    {
                        menu->czy_menu_otwarte = 0; //ustawia ze menu nie ma sie juz rysowac (idziemy do gry)
                        graj->czas_gry.restart();
                        graj_sie_rysuje(*okno, graj,kaczuszka);
                        menu->czy_menu_otwarte = 1;
                    }
                    break;
                }
            break;
            }

        }
    }
}

