#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int suma(int a, int b) {
//	return a + b;
//}
//
//float suma(float a, float b) {
//	return a + b;
//}
//
//string suma(string a, string b) {
//	return a + b;
//}


template<typename T> T suma(T a, T b) {
	return a + b;
}

template<> char* suma(char* a, char* b) {
	cout << endl << "Apel versiune specializata";
	return nullptr;
}

class Adresa {
	string strada;
	int numar;
	string oras;
public:
	Adresa(string strada, int numar, string oras) {

	}

	Adresa(){}
};


template<typename T> class Student {
	string nume;
	vector<int> note;
	T adresa;
public:
	Student(string nume, T adresa) {
		this->nume = nume;
		this->adresa = adresa;
	}

	Student(string nume, string strada, int numar, string oras)
	{
		T adresa(strada, numar, oras);
		this->adresa = adresa;
	}


	void adaugaNota(int valoare) {
		this->note.push_back(valoare);
	}

	void afisare() {
		vector<int>::iterator it;
		for (it = this->note.begin(); it != this->note.end(); it++) {
			cout << endl << *it;
		}
	}

};

int main() {
	int rezultat = suma<int>(2, 3);
	float rezultatFloat = suma<float>(2.5, 1.6);
	char* msg1 = new char[5] {"test"};
	char* msg2 = new char[6] {"test2"};

	char* mesaj = suma<char*>(msg1, msg2);

	Student<Adresa> student("Gigel", "Piata Victorie", 2, "Bucuresti");

	//Student<string> student3("Gigel", "Piata Victorie", 2, "Bucuresti");
	Student<string> student2("Ana", "Bucuresti");

	student2.adaugaNota(10);
	student2.adaugaNota(10);
	student2.adaugaNota(9);

	student2.afisare();
}