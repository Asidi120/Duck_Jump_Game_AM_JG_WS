#include "Graj.h"
#include "Kaczuszka.h"
Graj::Graj()
{
	tytul.setFont(czcionka);
	tytul.setFillColor(Color::Magenta);
	tytul.setString("GRA");
	tytul.setCharacterSize(40);
}

Graj::~Graj() {}

void Graj::rysuj_graj(RenderWindow& okno, Kaczuszka* kaczuszka)
{
	okno.draw(tlo);
	okno.draw(tytul);
	kaczuszka->rysuj_gracza(okno);
}

void Graj::co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka)
{
	while (okno.pollEvent(event_gra))
	{
		if (event_gra.type == Event::KeyPressed)
		{
			if (event_gra.key.code == Keyboard::D || event_gra.key.code == Keyboard::Right)
			{
				cout << "idziemy w prawo";
				for (int i = 0; i < 10; i++)
				{
					kaczuszka->ruch(1,0);
				}
			}
			if (event_gra.key.code == Keyboard::A || event_gra.key.code==Keyboard::Left)
			{
				cout << "idziemy w lewo";
				for (int i = 0; i < 10; i++)
				{
					kaczuszka->ruch(-1, 0);
				}
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
		if (event_gra.type == Event::Closed)
		{
			okno.close();
		}
	}
}
