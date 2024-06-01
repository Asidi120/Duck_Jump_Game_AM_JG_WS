#include "Graj.h"

Graj::Graj()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("GRA");
	tytul.setCharacterSize(40);
}

Graj::~Graj() {}

void Graj::rysuj_gra(RenderWindow& okno)
{
	okno.draw(tlo);
	okno.draw(tytul);
}

void Graj::co_sie_dzieje_w_grze(RenderWindow& okno)
{
	while (okno.pollEvent(event_gra))
	{
		if (event_gra.type == Event::KeyPressed)
		{
			if (event_gra.key.code == Keyboard::D || event_gra.key.code == Keyboard::Right)
			{
				cout << "idziemy w prawo";
			}
			if (event_gra.key.code == Keyboard::A || event_gra.key.code==Keyboard::Left)
			{
				cout << "idziemy w lewo";
			}
			if (event_gra.key.code == Keyboard::Space || event_gra.key.code==Keyboard::W || event_gra.key.code==Keyboard::Up)
			{
				cout << "skok";
			}
			if (event_gra.key.code == Keyboard::Escape)
			{
				czy_graj_wlaczone = 0;
				break;
			}
		}
	}
}
