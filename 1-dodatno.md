```
class Automobil {
protected:
    char* reg_oznaka;
    int km;

public:
    // ... tvoji postojeći konstruktori i metode ...

    // Dodaj ovu liniju:
    friend bool operator<(const Automobil& a1, const Automobil& a2);
};
```

<br>


```
bool operator<(const Automobil& a1, const Automobil& a2) {
    return a1.km < a2.km;
}
```

<br>


```
Automobil* Prevoznik::VratiAutoSaNajmanjeKm() const {
    if (trenutan_broj_vozila == 0) return nullptr; // Ako je niz prazan

    Automobil* najmanji = automobili[0]; // Pretpostavimo da je prvi najmanji[cite: 17]

    for (int i = 1; i < trenutan_broj_vozila; i++) { // Prolazimo kroz ostatak niza[cite: 17]
        
        // KORIŠĆENJE OPERATORA:
        // Pošto su najmanji i automobili[i] pokazivači, stavljamo * ispred njih
        if (*automobili[i] < *najmanji) { 
            najmanji = automobili[i]; // Našli smo auto sa još manjom kilometražom
        }
    }

    return najmanji;
}
```
