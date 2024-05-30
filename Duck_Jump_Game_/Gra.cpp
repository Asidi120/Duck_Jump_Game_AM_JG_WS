#include "Gra.h"

void Gra::tworzOkno()
{
	videomode.height = 700; //rozmiary okienka
	videomode.width = 900;
	okno = new RenderWindow(videomode, "Duck Jump", Style::Titlebar | Style::Close);

	this->okno->setFramerateLimit(60); // 60 fps
}

Gra::Gra()
{
	tworzOkno();
}

Gra::~Gra()
{
	delete okno; //usuwa okno
}

const bool Gra::czyGraOtwarta() const
{
    return okno->isOpen();
}

void Gra::petlaOkna()
{
    while (okno->pollEvent(e)) //zbiera jakies wydarzenie
    {
        switch (e.type)
        {
        case Event::Closed:
            okno->close(); //po nacisnieciu przycisku x okno sie zamknie
            break;

        case Event::KeyPressed:
            if (e.key.code == Keyboard::Escape) //po nacisnieciu klawiszu esc okno sie zamknie
                okno->close();
            break;
        }
    }
}

void Gra::update()
{
    petlaOkna();
}

void Gra::render()
{
    okno->clear(); //czysci stare okno
    //tu bedziemy rysowac elementy gry 

    okno->display(); //koniec renderingu
}

