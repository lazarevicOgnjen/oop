#include <iostream>
#include "prevoznik.h"
#include "hibrid.h"
#include "benzinac.h"
#include "automobil.h"

using namespace std;

Prevoznik::Prevoznik(int br) : kapacitet(br), trenutan_broj_vozila(0) {
	automobili = new Automobil * [kapacitet];
}

Prevoznik::~Prevoznik() {
	for (int i = 0;i < trenutan_broj_vozila;i++) {
		delete automobili[i];
	}
	delete[] automobili;
}

void Prevoznik::Dodaj(Automobil* a) {
	if (trenutan_broj_vozila < kapacitet) {
		automobili[trenutan_broj_vozila++] = a;
	}
	else {
		delete a;
	}
}

void Prevoznik::IzbaciPoKm(int zadataKilometraza) {
	for (int i = 0; i < trenutan_broj_vozila; ) {
		if (automobili[i]->getKm() > zadataKilometraza) {
			delete automobili[i];
			for (int j = i; j < trenutan_broj_vozila-1; j++) {
				automobili[j] = automobili[j + 1];
			}
			
			trenutan_broj_vozila--;
		}
		else {
			i++;
		}
	}
}


void Prevoznik::ObavljenaVoznja(const char* reg, int duzinaVoznje) {
	const char* reg1 = reg;
	for (int i = 0; i < trenutan_broj_vozila;i++) {
		const char* reg2 = automobili[i]->getReg();
		int k = 0;
		while (reg1[k] == reg2[k] && reg2[k] != '\0') {
			k++;
		}
		if (reg1[k] == reg2[k]) {
			automobili[i]->novaKilometraza(duzinaVoznje);
		}
	}
}

int Prevoznik::UkupnaKilometraza() const {
	int ukupno = 0;
	for (int i = 0; i < trenutan_broj_vozila; i++) {
		ukupno += automobili[i]->getKm();
	}
	return ukupno;
}


Automobil* Prevoznik::NajpovoljnijiAutomobil(int zadataDuzina) const {
	Automobil* najpovoljniji = nullptr;
	double minRazlika = -1;

	for (int i = 0;i < trenutan_broj_vozila;i++) {
		double maxKm = automobili[i]->maxKm();
		if (maxKm >= zadataDuzina) {
			double razlika = maxKm - zadataDuzina;
			if (najpovoljniji == nullptr || razlika < minRazlika) {
				minRazlika = razlika;
				najpovoljniji = automobili[i];
			}
		}

	}

	return najpovoljniji;
}

void Prevoznik::VratiNajDuzinuGorivo(Automobil** minDuzina, Automobil** minPotrosio) const {
	if (trenutan_broj_vozila == 0) return;

	*minDuzina = automobili[0];
	*minPotrosio = automobili[0];

	for (int i = 1;i < trenutan_broj_vozila; i++) {
		if ((*minDuzina)->getKm() > automobili[i]->getKm()) {
			*minDuzina = automobili[i];
		}
		if ((*minPotrosio)->getUtrosenoGorivo() > automobili[i]->getUtrosenoGorivo()) {
			*minPotrosio = automobili[i];
		}
	}
}

ostream& operator<<(ostream& os, const Prevoznik& p) {
	for (int i = 0;i < p.trenutan_broj_vozila;i++) {
		if (Hibrid* h = dynamic_cast<Hibrid*>(p.automobili[i])) {
			os << *h << "\n";
		}
		else if(Benzinac* b = dynamic_cast<Benzinac*>(p.automobili[i])) {
			os << *b << "\n";
		}
	}
	return os;
}