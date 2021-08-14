#include <iostream>
#include "Vozilo.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <list>

int main() {
	ifstream fin;
	fin.open("Jovalex.txt"); 
	
	list<Automobil> sviAuti;
	list<Kamion> sviKamioni;
	int vrsta, brMotora, brSasije, temp;
	Automobil kola;
	Kamion kamion;
	while (fin >> vrsta >> brMotora >> brSasije >> temp) {
		if (vrsta == 0) {
			kola.setBrMotora(brMotora);
			kola.setBrSasije(brSasije);
			kola.setBrMesta(temp);
			sviAuti.push_back(kola);
		}
		else if (vrsta == 1) {
			kamion.setBrMotora(brMotora);
			kamion.setBrSasije(brSasije);
			kamion.setMaxTeret(temp);
			sviKamioni.push_back(kamion);
		}
	}
	cout << "Sva vozila auto kuce Jovalex" << endl;
	for (Automobil a1 : sviAuti)
	{
		a1.info();
	}

	for (Kamion k1 : sviKamioni) 
	{
		k1.info();
	}
	cout << endl;

	//Sada citam iz firme StartMB da vidim sta oni imaju
	vector<Automobil> sviAutiFirme;
	vector<Kamion> sviKamioniFirme;
	ifstream fin2;
	fin2.open("StartMB.txt");
	while (fin2 >> vrsta >> brMotora >> brSasije >> temp) {
		if (vrsta == 0) {
			kola.setBrMotora(brMotora);
			kola.setBrSasije(brSasije);
			kola.setBrMesta(temp);
			sviAutiFirme.push_back(kola);
		}
		else if (vrsta == 1) {
			kamion.setBrMotora(brMotora);
			kamion.setBrSasije(brSasije);
			kamion.setMaxTeret(temp);
			sviKamioniFirme.push_back(kamion);
		}
	}
	cout << "Sva vozila firme StartMB" << endl;
	for (Automobil a1 : sviAutiFirme)
	{
		a1.info();
	}

	for (Kamion k1 : sviKamioniFirme)
	{
		k1.info();
	}
	cout << endl;

	//Sada gledam koja vozila firma StartMB nema

	cout << "Sva vozila koja firma StartMB nije kupila od auto kuce Jovalex" << endl;
	int naso = 0;
	for (Automobil a1 : sviAuti)
	{
		for (Automobil a2 : sviAutiFirme) {
			if (a1.getBrSasije() == a2.getBrSasije()) {
				naso = 1;
			}
			else {
				naso = 0;
			}
		}
		if (naso == 0) {
			a1.info();
		}
	}
	naso = 0;
	for (Kamion k1 : sviKamioni)
	{
		for (Kamion k2 : sviKamioniFirme) {
			if (k1.getBrSasije() == k2.getBrSasije()) {
				naso = 1;
			}
			else {
				naso = 0;
			}
		}
		if (naso == 0) {
			k1.info();
		}
	}
	cout << endl;

	return 0;
}