#include "Gra.h"
#include "Menu.h"

void Gra::tworzOkno()
{
	videomode.height = 900; //rozmiary okienka
	videomode.width = 650;
	okno = new RenderWindow(videomode, "Duck Jump", Style::Titlebar | Style::Close);
    okno->setFramerateLimit(90); // 90 fps
}

Gra::Gra() //kostruktor domyslny - tworzy okienko
{
	tworzOkno();
}

Gra::~Gra() //dekstruktor - usuwa okienko
{
	delete okno;
}

const bool Gra::czyGraOtwarta() const
{
    return okno->isOpen();
}

void Gra::petlaOkna() //co robi okienko, czy zamyka sie, czy nie
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
                okno->close();
            break;
        }
    }
}

void Gra::aktualizuj()
{
    petlaOkna();
}

void Gra::rysuj()
{
    okno->clear(); //czysci stare okno
    //tu bedziemy rysowac elementy gry 

    okno->display(); //koniec renderingu
}

