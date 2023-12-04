#include <iostream>
#include <string>

using namespace std;

class TestLaborator {
	string data;			//dd/mm/yyyy
	int durataInMinute = 0;
	string* studenti = nullptr;
	int nrStudenti = 0;
public:
	static const int DURATA_MINIMA = 30;
	static int NR_TOTAL_SOLUTII;

	void setData(string data) {
		if (data.size() != 10 ||
			data[2] != '/' ||
			data[5] != '/')
			throw exception("Data are un format gresit");
		this->data = data;
	}
	void setDurata(int minute) {
		if (minute < TestLaborator::DURATA_MINIMA) {
			throw exception(("Durata minima este " + to_string(DURATA_MINIMA)).c_str());
		}
		this->durataInMinute = minute;
	}

	void prezenta(string numeStudent) {
		string* lista = new string[this->nrStudenti + 1];
		for (int i = 0; i < this->nrStudenti; i++) {
			lista[i] = this->studenti[i];
		}
		delete[] this->studenti;
		this->studenti = lista;
		lista[this->nrStudenti] = numeStudent;
		this->nrStudenti += 1;
	}

	void incarcaSolutie(string numeStudent) {
		bool estePrezent = false;
		for (int i = 0; i < this->nrStudenti; i++) {
			if (numeStudent == this->studenti[i]) {
				estePrezent = true;
				break;
			}
		}
		if (!estePrezent) {
			throw exception("Studentul incarca solutia fara a fi prezent");
		}
		TestLaborator::NR_TOTAL_SOLUTII += 1;
	}

	explicit operator int() {
		return this->durataInMinute;
	}

	//void setStudent(int index, TestLaborator test) {
	//	this->studenti[index] = test;
	// }

	void setStudent(int index, string nume) {
		this->studenti[index] = nume;
	}

	string& operator[](int index){
		if (index < 0 || index >= this->nrStudenti) {
			throw exception("Indexul este gresit");
		}
		return this->studenti[index];
	}

	string operator()(int index){
		return (*this)[index];
	}


};

int TestLaborator::NR_TOTAL_SOLUTII = 0;

int main() {
	TestLaborator test;

	try {
		test.setData("28/11/2023");
		test.setDurata(60);

		test.prezenta("Gigel");
		test.prezenta("Ana");
		test.prezenta("Ionut");

		test.incarcaSolutie("Ana");

		int durata = (int)test;
		cout << endl << "Durata este " << durata;

		//test += 34;
		//TestLaborator newTest = (test + 60);
		//if ((int)test) {

		//}

		//operator indexare
		cout << endl << "Primul student din lista este " << test[0];
		test[0] = "gigel";
		cout << endl << "Primul student din lista este " << test[0];

		string nume = test(1);
	}
	catch (exception e) {
		cout << endl << "Eroare " << e.what();
	}
}