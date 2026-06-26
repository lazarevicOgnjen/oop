#include <iostream>
#include "hibrid.h"

using namespace std;

Hibrid::Hibrid(const char* reg, int km1, double zr, double pp, double zug, int dp) : Benzinac(reg, km1, zr, pp, zug), duzina_puta_u_km_na_el_pogon(dp) {

}



void Hibrid::novaKilometraza(int predjenaKm) {
	km += predjenaKm;
	zapremina_utrosenog_goriva += (predjenaKm - duzina_puta_u_km_na_el_pogon) * prosecna_potrosnja;
}

double Hibrid::maxKm() const {
	return zapremina_rezervoara * prosecna_potrosnja + duzina_puta_u_km_na_el_pogon;
}

ostream& operator<<(ostream& os, const Hibrid& h) {
	os << static_cast<const Benzinac&>(h)
		<< "Duzina puta u km na elektricni pogon: " << h.duzina_puta_u_km_na_el_pogon;
	return os;
}