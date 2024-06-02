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
	//okno.draw(podloga);//tu rysujemy podloge
	kaczuszka->rysuj_gracza(okno);
}

void Graj::co_sie_dzieje_w_grze(RenderWindow& okno,Kaczuszka* kaczuszka)
{
	while (okno.pollEvent(event_gra))
	{
		if (event_gra.type == Event::Closed)
		{
			okno.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			czy_graj_wlaczone = 0;
			break;
		}
	}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			cout << "idziemy w lewo";
			kaczuszka->ruch(-1, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			cout << "idziemy w prawo";
			kaczuszka->ruch(1,0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space))&&(czas_milisekundy() - czas_przycisku>80))
		{
			czas_przycisku = czas_milisekundy();
			cout << "Current time in milliseconds is: "<< czas_milisekundy() << endl;
			cout << "skok" ;
			//kaczuszka->ruch(0,1);
			kaczuszka->czy_skok = true;
		}	
		if (kaczuszka->czy_skok)
		{
			if (czas_milisekundy()-czas_czekania>=10)
			{
				czas_czekania = czas_milisekundy();

				kaczuszka->skok_kaczuchy();
			}

		}
}

long long Graj::czas_milisekundy()
{
	// Get the current time from the system clock
	auto now = chrono::system_clock::now();
	// Convert the current time to time since epoch
	auto duration = now.time_since_epoch();
	// Convert duration to milliseconds
	auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
	return milliseconds;

}
