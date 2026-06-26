#pragma once
#include "automobil.h"

#include <iostream>

using namespace std;

class Prevoznik {
private:
	int kapacitet;
	int trenutan_broj_vozila;
	Automobil** automobili;

public:
	Prevoznik(int br);
	~Prevoznik();


	void Dodaj(Automobil* a);
	void IzbaciPoKm(int kilometraza);
	void ObavljenaVoznja(const char* reg, int duzinaVoznje);

	int UkupnaKilometraza() const;
	Automobil* NajpovoljnijiAutomobil(int zadataDuzina) const;

	void VratiNajDuzinuGorivo(Automobil** minDuzina, Automobil** minPotrosio) const;

	friend ostream& operator<<(ostream& os, const Prevoznik& p);
};