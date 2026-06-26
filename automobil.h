#pragma once
#include <iostream>

using namespace std;

class Automobil {
protected:
	char* reg_oznaka;
	int km;

public:
	Automobil(const char* reg, int km1);
	virtual ~Automobil();

	int getKm() const { return km;  }
	const char* getReg() const { return reg_oznaka; }
	virtual void novaKilometraza(int predjeniKm) = 0;
	
	virtual double maxKm() const = 0;

	virtual double getUtrosenoGorivo() const = 0;


	friend ostream& operator<<(ostream& os, const Automobil& a);
};