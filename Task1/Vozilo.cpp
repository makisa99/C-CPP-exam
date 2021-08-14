#include "Vozilo.h"
#include <iostream>
using namespace std;
Vozilo::Vozilo()
{
}

Vozilo::Vozilo(int brMotora, int brSasije) : brMotora(brMotora), brSasije(brSasije)
{
}

Vozilo::~Vozilo()
{
}

int Vozilo::getBrMotora() const
{
	return brMotora;
}

void Vozilo::setBrMotora(int brMotora)
{
	this->brMotora = brMotora;
}

int Vozilo::getBrSasije() const
{
	return brSasije;
}

void Vozilo::setBrSasije(int brSasije)
{
	this->brSasije = brSasije;
}

Automobil::Automobil()
{
}

Automobil::Automobil(int brMotora, int brSasije, int brMesta) : Vozilo(brMotora, brSasije)
{
	this->brMesta = brMesta;
}

int Automobil::getBrMesta() const
{
	return brMesta;
}

void Automobil::setBrMesta(int brMesta)
{
	this->brMesta = brMesta;
}

Automobil::~Automobil()
{
}

void Automobil::info()
{
	cout << "Broj Motora: " << brMotora << " Broj Sasije: " << brSasije << " Broj mesta za sedenje: " << brMesta << endl;
}

Kamion::Kamion()
{
}

Kamion::Kamion(int brMotora, int brSasije, int maxTeret) : Vozilo(brMotora,brSasije)
{
	this->maxTeret = maxTeret;
}

int Kamion::getMaxTeret() const
{
	return maxTeret;
}

void Kamion::setMaxTeret(int maxTeret)
{
	this->maxTeret = maxTeret;
}

Kamion::~Kamion()
{
}

void Kamion::info()
{
	cout << "Broj Motora: " << brMotora << " Broj Sasije: " << brSasije << " Max teret: " << maxTeret << endl;
}
