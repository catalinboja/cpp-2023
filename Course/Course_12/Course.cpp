#include <iostream>
#include <string>
using namespace std;

//relations between classes
// "has a"
// "is a"

class Student {
protected:
	string name;
	int age;
	string faculty;
	//int* grades = nullptr;
public:

	const int id = 0;

	//1000 methods
	void printInfo() {
		cout << endl << "Student name " << this->name;
		cout << endl << "It's a student";
	}

	string getName() {
		return this->name;
	}

	Student(){}

	Student(string name, int age) {
		this->name = name;
		this->age = age;
		cout << endl << "Student ctor";
	}

	~Student() {
		//delete[] this->grades;
	}

	void operator=(Student s) {
		this->name = s.name;
		this->age = s.age;
	}
};

//C style
//class MasterStudent {
//	string name;
//	int age;
//	string faculty;
//
//	float bachelorExamAverage;
//	string universityDegree;
//public:
//	//1000 methods
//};

//C++ style
class MasterStudent: public Student {
	float bachelorExamAverage;
	string universityDegree;
	//char* faculty = nullptr;

public:
	void printMasterInfo() {
		cout << endl << "Master student name " << this->name;
		cout << endl << "Master student age " << this->age;
		//cout << endl << "Master student name " << this->getName();
	}

	MasterStudent():Student("John Doe", 0) {

	}

	MasterStudent(string name, int age, string university)
	:Student(name, age){
		this->universityDegree = university;

		cout << endl << "MasterStudent ctor";
	}

	MasterStudent(Student student, string university)
		:Student(student) {
		this->universityDegree = university;
	}

	~MasterStudent()
	{
		//please DO NOT
		//delete[] this->grades;
		//this->grades = nullptr;
		//delete[] this->faculty;
	}
};

class A {
	int a;
public:
	~A() {
		cout << endl << "A destructor";
	}
};

class B: public A {
	int b;
public:
	~B() {
		cout << endl << "B destructor";
	}
};

class C : public B {
	int c;
public:
	~C() {
		cout << endl << "C destructor";
	}
};

int main() {
	Student student("John", 21);
	student.printInfo();

	//student.age = 23;

	MasterStudent master;
	master.printInfo();
	cout << endl << "Master student id " << master.id;
	//cout << endl << "Master student age " << master.age;

	MasterStudent master2(student, "CSIE");
	MasterStudent alice("Alice", 21, "CSIE");

	//C c;

	//student = alice; //up-casting

	//A a;
	//a = c; //up casting

	//c = a; //down casting
	//master = student; //down casting


	Student* students;
	//MasterStudent* masterStudents;
	students = new Student[2];
	students[0] = student;
	students[1] = alice;

	students[0].printInfo();
	students[1].printInfo();

	//MasterStudent copy;
	//copy = (MasterStudent)students[1];


}
