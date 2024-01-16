#include <iostream>
#include <string>

using namespace std;

class Baza {
protected:
	int valoare = 10;
public:
	virtual void functie() { cout << endl << "baza"; }
	void ceva() {};

};

class Extinsa : public Baza {
public:
	void functie() { 
		this->valoare = 23;
		cout << endl << "extinsa"; 
	}
};

class ExtinsaAltfel {
	Baza b;	//composition 1:1
public:
	void functie() {
		//sthis->b.valoare = 23;
	}

	Baza getB() {
		return b;
	}

	~ExtinsaAltfel() {
		cout << endl << "Apel destructor Extinsa Altfel";
	}
};

int main() {
	Extinsa e;
	e.functie();
	e.ceva();

	Baza b;
	b.functie();

	ExtinsaAltfel e2;
	e2.getB().ceva();

	//testare destructor
	{
		int vb = 10;
		ExtinsaAltfel z;
	}

	cout << endl << "------------";

	ExtinsaAltfel* pObiect = new ExtinsaAltfel();
	delete pObiect;

	cout << endl << "------------";

	b = e;
	b.functie();

	Baza* pointeri[2];
	pointeri[0] = &b;
	pointeri[1] = &e;

	for (int i = 0; i < 2; i++) {
		pointeri[i]->functie();
		//pointeri[i]->_vfptr[0]();
	}
}

