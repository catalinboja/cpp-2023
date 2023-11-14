#include <iostream>
#include <string>
using namespace std;

class Produs {
	string denumire = "";
	float pret = 0;
	int vanzariLunare[12];
	int lunaCurenta = 0;	//0 -> 11 (0 - Ianuarie, 11 - Decembrie)
public:
	Produs(string nume, float pret) :denumire(nume), pret(pret) {
		for (int i = 0; i < 12; i++) {
			this->vanzariLunare[i] = 0;
		}
	}

	Produs& operator=(const Produs& p) {

		if (this == &p) {
			return *this;
		}

		this->denumire = p.denumire;
		this->pret = p.pret;
		for (int i = 0; i < 12; i++) {
			this->vanzariLunare[i] = p.vanzariLunare[i];
		}
		this->lunaCurenta = p.lunaCurenta;

		return *this;
	}

	string getDenumire() {
		return this->denumire;
	}

	Produs operator+(int valoare) {
		//NU modifica operanzii
		Produs rezultat = *this;
		rezultat.pret += valoare;
		return rezultat;
	}

	friend void operator<<(ostream& consola, Produs& p);
};

Produs operator+(int valoare, Produs& p) {
	return p + valoare;
}

void operator<<(ostream& consola, Produs& p) {
	consola << "\n Denumire produs:" << p.getDenumire();
	consola << "\n Pret produs:" << p.pret;
	consola << "\n Vanzari lunare:";
	for (int i = 0; i < 12; i++) {
		consola << " " << p.vanzariLunare[i];
	}
	consola << "\n Luna curenta " << p.lunaCurenta;
}

int main() {
	Produs laptop("Laptop", 2500);
	Produs altProdus("", 2500);
	Produs temp("", 0);

	altProdus = laptop;

	temp = altProdus = laptop;

	int vb1, vb2, vb3;
	vb1 = vb2 = vb3 = 10;

	//laptop = laptop;

	//lucru cu stream-urile standard de input / ouput
	cout << laptop;

	//cin >> laptop;
	//cout << laptop;

	////operatori matematici
	////binari
	laptop = laptop + 20;	//crestem pretul
	laptop = 30 + laptop;	//crestem pretul

	cout << laptop;

	//altProdus = laptop + temp;
	////la fel pentru -, / *

	//laptop += 35;		//modificam vanzarile pentru luna curenta
	////la fel -=, /= si *=

	////unari
	//temp = laptop++;	//trecem la luna urmatoare - postincrementare
	//temp = ++laptop;	//trecem la luna urmatoare - preincrementare
	////la fel pentru -- cu cele 2 forme

	////operatori logici
	//if (laptop == temp) {
	//	cout << endl << "Cele 2 produse sunt identice";
	//}
	//if (laptop > 500) {
	//	cout << endl << "Produsul este unul scump";
	//}
	//if(laptop >= temp){
	//	cout << endl << "Are pretul mai mare sau egal";
	//}
	////la fel !=, <, =<

	//if (!laptop) {
	//	cout << endl << "Produsul nu s-a vandut pana acum";
	//}

	////operatorul cast
	//int totalVanzari = laptop;

	////operator indexare
	//int vanzariFebruarie = laptop[1];
	//laptop[0] = 123;

	////operatorul functie
	//float medieVanzariLunare = laptop(1, 5);

}