
#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	int age;
	string address;
	int grades[100];
};

class StudentClass {

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
		if (value >= 5 && value <= 100) {
			this->age = value;
		}
		else {
			//throw "Wrong value";
			throw new exception("Wrong value");
			//throw exception("Wrong value");
		}
		
	}

	//constructor
	StudentClass(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

void printStudentData(Student student) {
	cout << endl << "Name : " << student.name;
}
void printStudentData(Student* pStudent) {
	cout << endl << "Name : " << pStudent->name;
}

int main() {

	string* studentNames = new string[1000];
	int* studentAges = new int[1000];

	Student* students = new Student[1000];

	//an article
	Student student;
	student.name = "John";
	printStudentData(student);
	printStudentData(&student);

	//an object
	//StudentClass studentObject;
	//studentObject.name = "Alice";
	//studentObject.age = -23;

	StudentClass alice("Alice", 21);
	StudentClass john("John", 21);

	//cout << endl << "Alice age is  " << alice.age;
	cout << endl << "Alice age is  " << alice.getAge();
	cout << endl << "John age is  " << john.getAge();
	//alice.age = 23;
	///alice.setAge(-23);
	alice.setAge(23);
	cout << endl << "Alice age is  " << alice.getAge();
}