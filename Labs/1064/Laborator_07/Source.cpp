#include <iostream>
#include <string>

using namespace std;

class Smartphone {
	std::string* contacte = nullptr;
	int nrContacte = 0;

	const std::string IMEI;
	char nivelBaterie = 0;	//0 -> 100
public:
	string* getContacte() {
		string* lista = new string[this->nrContacte];
		for (int i = 0; i < this->nrContacte; i++) {
			lista[i] = this->contacte[i];
		}
		return lista;
	}

	int getNrContacte() {
		return this->nrContacte;
	}

	void setContacte(string* lista, int nrContacte) {
		if (lista == nullptr)
		{
			throw exception("Lista este vida");
		}
		delete[] this->contacte;
		this->nrContacte = nrContacte;
		this->contacte = new string[nrContacte];
		for (int i = 0; i < nrContacte; i++) {
			this->contacte[i] = lista[i];
		}
	}

	void printConsola() {
		cout << endl << "IMEI: " << this->IMEI;
		cout << endl << "Nivel baterie: " << (int)this->nivelBaterie << "%";
		if (this->nrContacte == 0) {
			cout << endl << "Agenda nu contine contacte";
		}
		else {
			cout << endl << "Agenda: ";
			for (int i = 0; i < this->nrContacte; i++) {
				cout << " " << this->contacte[i];
			}
		}
	}
	//Smartphone() {

	//}

	Smartphone(string imei, string* contacte, int nrContacte) 
		: IMEI(imei), nivelBaterie(100){
		//this->IMEI = imei;
		this->setContacte(contacte, nrContacte);
	}

	~Smartphone() {
		cout << endl << "Apel destructor";
		delete[] this->contacte;
		this->contacte = nullptr;
	}

	Smartphone(const Smartphone& tel):IMEI(tel.IMEI) {
		//tel.nivelBaterie = this->nivelBaterie;
		this->setContacte(tel.contacte, tel.nrContacte);
		this->nivelBaterie = tel.nivelBaterie;
	}

	void operator=(const Smartphone& tel) {
		//tel.nivelBaterie = this->nivelBaterie;

		if (this == &tel) {
			return;
		}
		
		//dezalocare in set
		//delete[] this->contacte;
		//this->contacte = nullptr;
		this->setContacte(tel.contacte, tel.nrContacte);
		this->nivelBaterie = tel.nivelBaterie;
	}

};

void printSmartphone(Smartphone tel) {
	//tel.printConsola();
}

Smartphone createSmartphone() {
	string agenda[] = { "Gigel", "Ana", "Ionel" };
	int nrContacte = 3;

	Smartphone telefon("1234", agenda, nrContacte);
	return telefon;
}

int main() {

	string agenda[] = { "Gigel", "Ana", "Ionel" };
	int nrContacte = 3;

	Smartphone telefon("1234", agenda,nrContacte);
	telefon.printConsola();

	//telefon.setContacte(agenda, nrContacte);
	telefon.printConsola();

	Smartphone telefon2("2222", agenda, nrContacte);
	telefon2.printConsola();

	Smartphone clonaTelefon = telefon2;

	printSmartphone(telefon2);

	cout << endl << "Revenire main";

	int* pointer = new int[10];
	delete[] pointer;
	//aici pointer este dangling pointer
	pointer = nullptr;
	//aici nu mai este

	clonaTelefon = telefon; //clonaTelefon.operator=(telefon)
	telefon = telefon;
}