#include "Animacja.h"

Animacja::Animacja() 
{}

Animacja::~Animacja() {}

bool Animacja::czy_zmienic(Graj& graj)
{
	if (graj.czas_gry.getElapsedTime().asMilliseconds() >= 3)
	{
		return true;
	}
	return false;
}
