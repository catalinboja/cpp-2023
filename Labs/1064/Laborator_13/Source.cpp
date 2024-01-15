#include <iostream>
#include <string>

using namespace std;

class Persoana {
	virtual void info() = 0;
};

class Student{
protected:
	string nume;
	string facultate;
public:
	Student(string nume, string facultate)
		:nume(nume), facultate(facultate)
	{

	}

	Student() {

	}

	virtual void print() {
		cout << endl << "Studentul(a) " << this->nume << " este la "
			<< this->facultate;
	}

	void ceva(){}
};

class Masterand: public Student {
	string master;
public:
	Masterand(string nume, string facultate, string master) {
		this->nume = nume;
		this->facultate = facultate;
		this->master = master;
		//this->ceva();
	}

	void printMasterand() {
		this->print();
		cout << endl << "Este la masterat " << this->master;
	}

	//overriding
	void print() {
		this->Student::print();
		cout << endl << "Este la masterat " << this->master;
	}

	//overloading
	void print(int val) {

	}
};

class Doctorand : public Masterand {
	string domeniu;
public:
	Doctorand(string nume,
		string facultate,
		string masterat,
		string domeniu):Masterand(nume, facultate, masterat) {
		this->domeniu = domeniu;
	}
};

int main() {

	//Student studenti[3];
	Student* studenti[3];
	Masterand m("Gigel", "CSIE", "Info");
	m.ceva();

	Doctorand d("Ana","CSIE","Info","Info");

	studenti[0] = new Student("Ionel", "MK");
	studenti[1] = &m;
	studenti[2] = &d;

	for (int i = 0; i < 3; i++) {
		studenti[i]->print();  //EARLY - BINDING
		//studenti[i]->_vfptr[0]();  //LATE - BINDING
	}

}

