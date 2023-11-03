#include <iostream>
#include <string>
using namespace std;

enum class Stare {CLIENT, RIDICAT, DEPOZIT, LIVRAT};

class Util {
public:
	static char* copiereString(const char* sursa) { 
		if (sursa == nullptr) {
			return nullptr;
		}
		char* copie = new char[strlen(sursa) + 1];
		strcpy_s(copie, strlen(sursa) + 1, sursa);
		return copie;
	}
};

class Pachet {
	const int id;

	char* adresaLivrare = nullptr;
	float greutate = 0;
	bool areContinutFragil = false;
	Stare stare = Stare::RIDICAT;

	static int PACHETE_IN_DEPOZIT;
	static int GENERATOR_ID;

public:
	static const int LIMITA_DIM_ADRESA = 5;
	static const float LIMITA_GREUTATE_PACHETE_MICI;

	void setAdresa(string adresa) {
		if (adresa.size() < LIMITA_DIM_ADRESA) {
			throw exception("Adresa gresita");
		}
		delete[] this->adresaLivrare;
		this->adresaLivrare = Util::copiereString(adresa.c_str());
	}

	string getAdresa() {
		return string(this->adresaLivrare);
	}

	void setGreutate(float valoare) {
		if (valoare < 0) {
			throw exception("Greutate negativa");
		}
		this->greutate = valoare;
	}

	float getValoare() {
		return this->greutate;
	}

	void esteFragil() {
		this->areContinutFragil = true;
	}
	void nuEsteFragil() {
		this->areContinutFragil = false;
	}

	//este ok si asa, desi nu arata clean
	void setEsteFragil(bool valoare) {
		this->areContinutFragil = valoare;
	}

	bool trebuieGestionataCuAtentie() {
		return this->areContinutFragil;
	}

	void setStare(Stare stare) {
		if (stare == Stare::DEPOZIT) {
			Pachet::PACHETE_IN_DEPOZIT += 1;
		}
		if (this->stare == Stare::DEPOZIT) {
			Pachet::PACHETE_IN_DEPOZIT -= 1;
		}
		this->stare = stare;
	}

	Stare getStare() {
		return this->stare;
	}

	static int getNrPacheteDepozit() {
		return Pachet::PACHETE_IN_DEPOZIT;
	}


	Pachet(int id, const char* adresa, float greutate, bool esteFragil):
		id(id), areContinutFragil(esteFragil)
	{
		//prea tarziu
		//this->id = 1;
		this->setGreutate(greutate);
		this->setAdresa(adresa);
	}

	Pachet():id(++Pachet::GENERATOR_ID) {

	}

	int getId() {
		return this->id;
	}

	~Pachet() {
		delete[] this->adresaLivrare;
		if (this->stare == Stare::DEPOZIT) {
			Pachet::PACHETE_IN_DEPOZIT -= 1;
		}
	}

	//ctor copiere
	Pachet(Pachet& p): id(p.id), areContinutFragil(p.areContinutFragil) {
		this->setAdresa(p.getAdresa());
		this->setGreutate(p.greutate);
		this->setStare(p.stare);
	}
};

const float Pachet::LIMITA_GREUTATE_PACHETE_MICI = 10.0;
int Pachet::PACHETE_IN_DEPOZIT = 0;
int Pachet::GENERATOR_ID = 0;


int main() {
	Pachet pachet;
	pachet.setAdresa("Calea Dorobanti 15");
	pachet.esteFragil();
	pachet.setStare(Stare::RIDICAT);

	cout << endl << "Pachete in depozit: " << Pachet::getNrPacheteDepozit();

	cout << endl << "Adresa de livrare este " << pachet.getAdresa();
	pachet.setStare(Stare::DEPOZIT);

	cout << endl << "Pachete in depozit: " << Pachet::getNrPacheteDepozit();
}

