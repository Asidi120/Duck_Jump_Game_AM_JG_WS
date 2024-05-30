#include "Gra.h"

void Gra::tworzOkno()
{
	this->videomode.height = 700; //rozmiary okienka
	this->videomode.width = 900;
	this->okno = new RenderWindow(this->videomode, "Duck Jump", Style::Titlebar | Style::Close);

	this->okno->setFramerateLimit(60); // 60 fps
}

Gra::Gra()
{
	this->tworzOkno();
}

Gra::~Gra()
{
	delete this->okno; //usuwa okno
}

const bool Gra::czyGraOtwarta() const
{
    return this->okno->isOpen();
}

void Gra::petlaOkna()
{
    while (this->okno->pollEvent(this->e)) //zbiera jakies wydarzenie
    {
        switch (this->e.type)
        {
        case Event::Closed:
            this->okno->close(); //po nacisnieciu przycisku x okno sie zamknie
            break;

        case Event::KeyPressed:
            if (this->e.key.code == Keyboard::Escape) //po nacisnieciu klawiszu esc okno sie zamknie
                this->okno->close();
            break;
        }
    }
}

void Gra::update()
{
    this->petlaOkna();
}

void Gra::render()
{
    this->okno->clear(); //czysci stare okno
    //tu bedziemy rysowac elementy gry min menu

    this->okno->display(); //koniec renderingu
}

