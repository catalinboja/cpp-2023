#include <iostream>
#include <string>
#include <string.h> 

using namespace std;

void doSomething(int value);

void doSomethingElse() {
	doSomething(23);
}

void doSomething(int value) {
	doSomethingElse();
}


enum class StudentType {BACHELOR = 10, MASTER = 20, PHD, ERASMUS};

class Student {
private:
	std::string name;
	char* faculty;
	char university[100] = "CSIE";
	int age;
	int* grades;
	int noGrades;
	bool hasScholarship;
	StudentType type;
	char gender;
public:
	string getName() {
		return this->name;
	}

	//DON'T return addresses
	//char* getUniversity() {
	//	return this->university;
	//}

	char* getUniversity() {
		//create a copy
		//DON'T use static arrays as return
		//char copy[100];
		char* copy = new char[strlen(this->university) + 1];
		strcpy_s(copy, strlen(this->university) + 1, this->university);
		return copy;
	}

	char* getFaculty() {
		char* copy = new char[strlen(this->faculty) + 1];
		strcpy_s(copy, strlen(this->faculty) + 1, this->faculty);
		return copy;
	}

	int getNoGrades() {
		return this->noGrades;
	}

	int getAge() {
		return this->age;
	}

	bool hasScolarship() {
		return this->hasScholarship;
	}

	int* getGrades() {
		int* copy = new int[this->noGrades];

		//memcpy(copy, this->grades, sizeof(int) * this->noGrades);

		for (int i = 0; i < this->noGrades; i++) {
			copy[i] = this->grades[i];
		}
		return copy;
	}

	char getGender() {
		return this->gender;
	}

	StudentType getType() {
		return this->type;
	}

};

int main() {

	Student john;
	cout << endl << "John's university is " << john.getUniversity();
	char* univ = john.getUniversity();
	cout << endl << univ;
	strcpy_s(univ,10,"MK");
	cout << endl << univ;
	cout << endl << "John's university is " << john.getUniversity();
}