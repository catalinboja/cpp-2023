#include <iostream>
#include <string>
using namespace std;

enum class TipAuto { SCUTER, DUBA, AUTO };

class Util {
public:
	static string* copiereVector(
		string* vector, int nrElemente) {

		if (vector == nullptr) {
			return nullptr;
		}

		string* vectorNou = new string[nrElemente];
		for (int i = 0; i < nrElemente; i++) {
			vectorNou[i] = vector[i];
		}
		return vectorNou;
	}

	static void printVectorString(string* vector, int n) {
		if (vector == nullptr) {
			cout << endl << "Vectorul nu contine valori";
		}
		else {
			cout << endl << "Valori: ";
			for (int i = 0; i < n; i++) {
				cout << " " << vector[i];
			}
		}
	}
};


class Curier {
	string nume = "";
	string* traseuLivrari = nullptr;
	int nrLocatii = 0;
	int nrPachete = 0;
	TipAuto autoLivrare = TipAuto::AUTO;
public:
	string getNume() {
		return this->nume;
	}

	string* getTraseu() {
		//NU asa
		//return this->traseuLivrari;
		return Util::copiereVector(
			this->traseuLivrari, this->nrLocatii);
	}

	int getNrLocatii() {
		return this->nrLocatii;
	}

	int getNrPachete() {
		return this->nrPachete;
	}

	TipAuto getTipAuto() {
		return this->autoLivrare;
	}

	void setNume(string nume) {
		//shadowing
		//nume = nume;
		this->nume = nume;
	}

	void setNrPachete(int nrPachete) {
		if (nrPachete < 0) {
			throw exception("Numar negativ");
		}
		this->nrPachete = nrPachete;
	}

	void setTraseu(string* traseu, int nrLocatii) {
		delete[] this->traseuLivrari;
		this->traseuLivrari = Util::copiereVector(traseu, nrLocatii);
		this->nrLocatii = nrLocatii;
	 }

	void setTipAuto(TipAuto tip) {
		this->autoLivrare = tip;
	}

	//constructori
	//Curier() {
	//	this->setNume("Anonim");
	//}

	Curier(string nume, TipAuto tip = TipAuto::AUTO) {
		this->setNume(nume);
		this->setTipAuto(tip);
	}

	Curier(TipAuto tip, string nume) {
		this->setNume(nume);
		this->setTipAuto(tip);
	}

	Curier(string nume, TipAuto tip,
		int nrPachete, string* locatii, int nrLocatii):nume(nume), autoLivrare(tip){
		this->setTraseu(locatii, nrLocatii);
		this->setNrPachete(nrPachete);
	}

	//destructor
	~Curier() {
		delete[] this->traseuLivrari;
	}


};

int main() {
	Curier curier("Ionut");
	Curier gigel("Gigel", TipAuto::SCUTER);

	curier.setNume("Gigel");
	string locatii[] = {"Piata Victorie", 
		"Piata Romana", "Unirii", "Universitate"};
	int nrLocatii = 4;
	curier.setTraseu(locatii, nrLocatii);
	curier.setNrPachete(10);
	curier.setTipAuto(TipAuto::DUBA);

	cout << endl << "Nume " << curier.getNume();

	string* traseu = curier.getTraseu();
	Util::printVectorString(traseu, curier.getNrLocatii());
	delete[] traseu;

	{
		Curier c2("Nu stiu");
	}

	Curier* pCurier = new Curier("Bob");
	delete pCurier;

}