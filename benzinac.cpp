#include <iostream>
#include "benzinac.h"

using namespace std;

Benzinac::Benzinac(const char* reg, int km1, double zr, double pp, double zug) : Automobil(reg, km1), zapremina_rezervoara(zr), prosecna_potrosnja(pp), zapremina_utrosenog_goriva(zug) {

}



void Benzinac::novaKilometraza(int predjenaKm) {
	km += predjenaKm;
	zapremina_utrosenog_goriva += predjenaKm * prosecna_potrosnja;
}

double Benzinac::maxKm() const {
	return zapremina_rezervoara * prosecna_potrosnja;
}

ostream& operator<<(ostream& os, const Benzinac& b) {
	os << static_cast<const Automobil&>(b)
		<< "Zapremina rezervoara: " << b.zapremina_rezervoara
		<< "Prosecna potrosnja: " << b.prosecna_potrosnja
		<< "Zapremina utrosenog goriva: " << b.zapremina_utrosenog_goriva;
	return os;
}