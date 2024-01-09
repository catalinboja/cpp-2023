#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	string name = "";
	int age = 0;
public:
	Student(string name, int age) : name(name), age(age) {

	}

	//Student() {

	//}

	~Student() {

	}

	virtual void printInfo() {
		cout << endl << "The student " << this->name << " is " <<
			this->age << " years old";
	}
};

class MasterStudent: public Student {
	float bachelorExamAverage;
	string bachelorThesis;
public:
	MasterStudent():Student("John Doe", 18) {

	}

	MasterStudent(string name, int age, string bachelorThesis) 
		:Student(name, age), bachelorThesis(bachelorThesis) {

	}

	~MasterStudent() {

	}

	//void printMasterInfo() {
	//	cout << endl << "The student " << this->name << " is " <<
	//		this->age << " years old";
	//	cout << endl << "The bachelor thesis was " << this->bachelorThesis;
	//}

	//overriding
	void printInfo() {
		//cout << endl << "The student " << this->name << " is " <<
		//	this->age << " years old";
		//this->printInfo(); //stack overflow

		//calling the version from Student
		this->Student::printInfo();

		cout << endl << "The bachelor thesis was " << this->bachelorThesis;
	}

	//overloading
	void printInfo(int value) {
		cout << endl << "The student " << this->name << " is " <<
			this->age << " years old";
		cout << endl << "The bachelor thesis was " << this->bachelorThesis;
	}

};


int main() {
	MasterStudent master;
	MasterStudent alice("Alice", 21,"Future of OOP");
	Student bob("Bob", 20);

	//Student students[3];
	//students[0] = master; //Up-CASTING at value level -> you copy only the Student part
	//students[1] = alice;
	//students[2] = bob;

	Student* studentsUpgraded[3];
	studentsUpgraded[0] = &master;
	studentsUpgraded[1] = &alice;
	studentsUpgraded[2] = &bob;

	for (int i = 0; i < 3; i++) {
		studentsUpgraded[i]->printInfo();  //EARLY-BINDING
		//studentsUpgraded[i]->__vfptr[0]();  //LATE-BIDING
	}

	//alice.printInfo();

}