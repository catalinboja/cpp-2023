#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Adresa {
	const int vb = 56;
	string strada = "";
	int numar = 0;
	string oras = "";
private:
	Adresa(){}

	 void ceva() {
		Adresa a;
	}
public:
	Adresa(string strada, int numar, string oras)
	: strada(strada), oras(oras), vb(100){
		this->numar = numar;
	}

	friend ostream& operator<<(ostream& out, Adresa& adresa);
};

ostream& operator<<(ostream& out, Adresa& adresa) {
	out << endl << "Adresa: " << adresa.strada << ", nr " << adresa.numar << ", " << adresa.oras;
	return out;
}

class Colet {
	Adresa adresaLivrare;	//has a - 1:1
	string destinatar;
	float greutate = 0;
private:
	Colet(): adresaLivrare("",0,"") {}
public:
	Colet(string strada, int numar, string oras, string destinatar)
	:adresaLivrare(strada, numar, oras), destinatar(destinatar){

	}
	Colet(string destinatar, Adresa& adresa): adresaLivrare(adresa), destinatar(destinatar) {

	}

	friend ostream& operator<<(ostream& out, Colet& colet);
};

ostream& operator<<(ostream& out, Colet& colet) {
	out << endl << "Destinatar: " << colet.destinatar;
	out << colet.adresaLivrare;
	out << endl << "Greutate: " << colet.greutate;
	return out;
}

class Curier {
	string nume;
	//Colet colete[50];	//has a - 1 : M
	//Colet* colete = nullptr;
	Colet** colete = nullptr;
	//Colet* colete[50]; //vector static de pointeri
	int nrColete = 0;

public:
	Curier(){}

	void adaugaColet(Colet& colet) {
		Colet** coleteTemp = new Colet*[this->nrColete + 1];
		for (int i = 0; i < this->nrColete; i++) {
			coleteTemp[i] = this->colete[i];
		}
		//coleteTemp[this->nrColete] = &colet; //NU asa
		coleteTemp[this->nrColete] = new Colet(colet); 

		delete[] this->colete;
		this->nrColete += 1;
		this->colete = coleteTemp;
	}

	~Curier() {
		for (int i = 0; i < this->nrColete; i += 1) {
			delete this->colete[i];
		}
		delete[] this->colete;
	}

	void generareRaport(ofstream& fisier) {
		fisier << endl << "Lista livrari curier " << this->nume;
		for (int i = 0; i < this->nrColete; i++) {
			fisier << *this->colete[i];
		}
	}
};


int main() {
	Curier fan1;

	Adresa adresaCsie("Calea Dorobanti", 15, "Bucuresti");
	Colet colet1("Gigel", adresaCsie);
	Colet colet2("Ana", adresaCsie);

	fan1.adaugaColet(colet1);
	fan1.adaugaColet(colet2);

	ofstream raport("Raport curier.txt", ios::ate);
	if (!raport.is_open()) {
		cout << endl << "********** NU s-a deschis fisierul ****************";
	}
	else {
		fan1.generareRaport(raport);
		raport.close();
	}



	//Curier - 1
	//Colete - 50
	//Adresa - 50

}
