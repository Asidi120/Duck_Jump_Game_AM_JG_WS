#include "Animacja.h"

Animacja::Animacja() 
{}

Animacja::~Animacja() {}

bool Animacja::czy_zmienic(Graj& graj)
{
	if (czas_zmiany.getElapsedTime().asMilliseconds() >= 300)
	{
		czas_zmiany.restart();
		return true;
	}
	return false;
}
