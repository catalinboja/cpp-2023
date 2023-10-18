#include <iostream>
#include <string>

enum TipStudent { LICENTA = 10, MASTERAT = 20, DOCTORAT };

class Student {
private:
	std::string nume = "Anonim";
	char universitate[100] = "ASE";
	char* facultate = nullptr;
	int varsta = 0;
	char gen = 'N';
	int* note = nullptr;
	int nrNote = 0;
	bool areBursa = false;
	TipStudent tip = TipStudent::LICENTA;

public:
	// interfata publica a clasei
	//citire
	std::string getNume() {
		return this->nume;
	}

	int getVarsta() {
		return varsta;
	}

	char* getUniversitate() {
		//NU returnati adrese
		//return this->universitate;

		//NU returnam adrese de variabile locale (sunt pe stiva functiei)
		//char copie[100];
		//strcpy_s(copie, 100, this->universitate);
		//return copie;

		char* copie = new char[strlen(this->universitate) + 1];
		strcpy_s(copie, strlen(this->universitate) + 1, this->universitate);
		return copie;
	}

	char* getFacultate() {
		if (this->facultate == nullptr) {
			return nullptr;
		}

		char* copie = new char[strlen(this->facultate) + 1];
		strcpy_s(copie, strlen(this->facultate) + 1, this->facultate);
		return copie;
	}

	int* getNote() {
		if (this->note == nullptr) {
			return nullptr;
		}

		int* copie = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++) {
			copie[i] = this->note[i];
		}

		//alternativa la for
		//memcpy(copie, this->note, sizeof(int) * this->nrNote);

		return copie;
	}


	//scriere
};

int main() {
	Student student;
	Student ana;

	//student.nume = "Gigel";
	//student.areBursa = true;

	//student.varsta = -23;

	std::cout<< std::endl << "Numele este " << student.getNume();
	std::cout << std::endl << "Varsta este " << student.getVarsta();
	std::cout << std::endl << "Numele este " << ana.getNume();
	std::cout << std::endl << "Universitatea este " << ana.getUniversitate();

	char* univ = ana.getUniversitate();
	
	strcpy_s(univ, 100, "Unibuc");

	std::cout << std::endl << "Universitatea este " << ana.getUniversitate();

	//delete[] univ;

}