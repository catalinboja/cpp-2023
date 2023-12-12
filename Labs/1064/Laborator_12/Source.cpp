#include <iostream>
#include <string>
using namespace std;

class Student {
	string nume = "";
	string facultate = "";
	int grupa = 0;
public:
	const int id = 0;

	 virtual void print() {
		cout << endl << "Studentul " << this->nume <<
			" este inmatriculat la " << this->facultate <<
			", grupa " << this->grupa;
	}

	Student(string nume, string facultate, int grupa)
		:nume(nume), facultate(facultate), grupa(grupa)
	{

	}

	Student() {

	}

	//void operator=(Masterand& m) {
	//	this->nume = m.nume;
	//	this->grupa = m.grupa;
	//	this->facultate = m.Student::facultate;
	//}

	void operator=(Student& s) {
		this->nume = s.nume;
		this->grupa = s.grupa;
		this->facultate = s.facultate;
	}
};

class Masterand: public Student
{
	string programMasterat;
	string facultate;
public:
	Masterand():Student("","",0) {}
	Masterand(
		string nume, string facultate, int grupa,
		string programMasterat, string facultateMasterat)
		:Student(nume, facultate, grupa),
		programMasterat(programMasterat),
		facultate(facultateMasterat) {

	}

	Masterand(Student student,
		string program, string facultate)
		:Student(student),
		programMasterat(program),
		facultate(facultate) {

	}

	void printMasterand() {
		this->print();
		cout << endl << "Masterat " << this->programMasterat
			<< " din facultatea " << this->facultate;
	}

	//overriding pentru print din Student
	void print() {
		//apel versiune din parinte
		this->Student::print();
		cout << endl << "Masterat " << this->programMasterat
			<< " din facultatea " << this->facultate;
	}
};

int main() {
	Student student("Gigel","CSIE",1001);
	cout << endl << "ID student " << student.id;
	student.print();

	Masterand masterand;
	cout << endl << "ID masterand " << masterand.id;
	//cout << endl << "Nume masterand " << masterand.nume;

	Masterand masterand2(student, "Info", "CSIE");


	//Student studenti[1000];
	//Masterand masteranzi[1000];

	Student stud;
	stud = masterand2; //UP Casting prin op =
	//masterand = student;  //DOWN Casting nu este implicit

	Student* pStudent = &masterand2; //UP casting la nivel de pointeri


	Masterand ana("Ana", "CSIE", 1002, "Info", "CSIE");

	//Student studenti[3];
	//studenti[0] = student;
	//studenti[1] = masterand2;
	//studenti[2] = ana;

	Student* studenti[3];
	studenti[0] = &student;
	studenti[1] = &masterand2;
	studenti[2] = &ana;

	for (int i = 0; i < 3; i++) {
		studenti[i]->print();  //EARLY - BINDING implicit

		//studenti[i]->_vfptr[0](); //LATE - BIDING
	}

	//incercare down cast
	//Masterand* temp = (Masterand*) studenti[2];
	//temp->printMasterand();




}