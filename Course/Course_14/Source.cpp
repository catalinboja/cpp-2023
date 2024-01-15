#include <iostream>
#include <string>
using namespace std;


//an abstract class
//contracts between developers
class Printable {
	int value;
public:
	virtual void printInfo() = 0; //virtual pure method
	void doSomething() {

	}
};

class Student: public Printable {
public:
	//override the virtual pure method
	void printInfo() {
		cout << endl << "Is a student";
	}
};

class Person: public Printable {
	void printinfo() {

	}
	//override the virtual pure method
	void printInfo() {
		cout << endl << "Is a Person";
	}
};

class Employee {
	void print() {

	}

};

//multiple inheritance
class Inter :  public Student, public Employee, public Person {

};

class DogActions {
public:
	virtual void bark() = 0;
};

class Dog {

};

class Parrot: DogActions {
public:
	void bark() {
		cout << endl << "Woof Woof";
	}
};

int main() {
	//Printable printable;
	Printable* pointerToPrintable; //use the abstract class as a reference

	Student student;
	Person person;

	Printable** printableObjects = new Printable * [2];
	printableObjects[0] = &student;
	printableObjects[1] = &person;

	for (int i = 0; i < 2; i++) {
		printableObjects[i]->printInfo(); //LATE BINDING
	}


}