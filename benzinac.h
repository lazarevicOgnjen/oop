#pragma once
#include <iostream>
#include "automobil.h"

using namespace std;

class Benzinac : public Automobil {
protected:
	double zapremina_rezervoara;
	double prosecna_potrosnja;
	double zapremina_utrosenog_goriva;

public:
	Benzinac(const char* reg, int km1, double zr, double pp, double zug);
	~Benzinac() override = default;

	void novaKilometraza(int predjeniKm) override;
	double maxKm() const override;
	double getUtrosenoGorivo() const override { return zapremina_utrosenog_goriva; }

	friend ostream& operator<<(ostream& os, const Benzinac& b);
};