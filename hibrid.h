#pragma once
#include "benzinac.h"
#include <iostream>

using namespace std;

class Hibrid : public Benzinac {
private:
	int duzina_puta_u_km_na_el_pogon;

public:
	Hibrid(const char* reg, int km1, double zr, double pp, double zug, int dp);
	~Hibrid() override = default;

	void novaKilometraza(int predjenaKm) override;

	double maxKm() const override;
	double getUtrosenoGorivo() const override { return zapremina_utrosenog_goriva; }

	friend ostream& operator<<(ostream& os, const Hibrid& h);
};