#include <iostream>
#include "automobil.h"

using namespace std;

Automobil::Automobil(const char* reg, int km1) : km(km1) {
	int duzina = 0;
	while (reg[duzina] != '\0') {
		duzina++;
	}
	reg_oznaka = new char[duzina + 1];
	for (int i = 0; i <= duzina;i++) {
		reg_oznaka[i] = reg[i];
	}
	
}

Automobil::~Automobil() {
	delete[] reg_oznaka;
}



ostream& operator<<(ostream& os, const Automobil& a) {
	os << "Registracija: " << a.reg_oznaka
		<< "kilometraza: " << a.km;

	return os;
}