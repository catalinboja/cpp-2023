
#include <iostream>
#include <string>
using namespace std;

enum class StudentType { BACHELOR = 10, MASTER, PHD = 20 };

class Student{


private:
	//private: you get it by default
	// 
	//public:
	string name = "Anonymous";
	//private:
	int age = 0;
	string address = "";
	int grades[100];
	int noGrades = 0;
	int* bonusPoints = nullptr;
	int noBonusPoints = 0;
	char* faculty = nullptr;
	char university[100] = "ASE";
	bool hasScholaship = false;
	bool isErasmusStudent = false;
	StudentType type = StudentType::BACHELOR;
	char gender;

public:
	static const int MAX_AGE = 100;
	static const int MIN_AGE = 5;
	static const int MIN_NAME = 2;
	static int noBoys;
	static int noGirls;

public:
	//class public interface
	//accessor methods
	//getters - provide read access
	int getAge() {
		return this->age;
	}

	//setters - provide write access
	void setAge(int value) {
		//ALWAYS validate the input
		if (value >= MIN_AGE && value <= MAX_AGE) {
			this->age = value;
		}
		else {
			//throw "Wrong value";
			throw new exception("Wrong value");
			//throw exception("Wrong value");
		}

	}

	//public interface for faculty
	char* getFaculty() {
		//don't return pointers
		return this->faculty;
	}

	char* getUniversity() {
		//return this->university;

		//do a copy
		//don't use static arrays
		//char univCopy[100];

		char* univCopy = new char[strlen(this->university) + 1];
		strcpy_s(univCopy, strlen(this->university) + 1, this->university);
		return univCopy;
	}

	int* getBonusPoints() {
		int* copy = new int[this->noBonusPoints];
		for (int i = 0; i < this->noBonusPoints; i++) {
			copy[i] = this->bonusPoints[i];
		}

		//memcpy(copy, this->bonusPoints, sizeof(int) * this->noBonusPoints);
		return copy;
	}

	int getNoBonusPoints() {
		return this->noBonusPoints;
	}

	string getName() {
		return this->name;
	}

	void setName(string newName) {
		if (newName.size() <= Student::MIN_NAME) {
			throw exception("Name too short");
		}
		this->name = newName;
	}

	void setFaculty(char* newFaculty) {
		//DON't
		this->faculty = faculty;	//shallow copy

	}

	void getsScolarship() {
		this->hasScholaship = true;
	}

	void losesScholarship() {
		this->hasScholaship = false;
	}

	//constructor
	Student(string name, int age) {
		this->name = name;
		this->setAge(age);
		//shadowing
		//name = name;
		this->name = name;
	}

	Student(string name, int age, char gender) {

	}

	Student(string name, char gender, int age, int* bonusPoints, int noBonusPoints) {

	}



	//default ctor
	Student() {

	}

	//destructor

	//copy constructor
};

//only way to init a non constant static attribute
int Student::noBoys = 0;
int Student::noGirls = 0;


int main() {

	//calling the default ctor
	Student john;
	Student* pStudent = new Student();

	delete pStudent;

	Student alice("Alice", 23);
	pStudent = new Student("Bob", 21);

	//StudentType type;
	//cout << endl << "Min age is " << Student::MIN_AGE;

	//Student john("John", 23);
	////we create a memory leak
	////cout << endl << "University " << john.getUniversity();


	//char* univ = john.getUniversity();
	//cout << endl << "University " << univ;

	//strcpy_s(univ, 100, "Poli");

	//char* johnUniv = john.getUniversity();
	//cout << endl << "University " << johnUniv;
	//delete[] johnUniv;

	////i din't need univ
	//delete[] univ;
	//univ = nullptr;

	//john.getsScolarship();
}