#include <iostream>
#include <string>
using namespace std;

class Student {

	void doSomething() {
		cout << endl << "Private method in Student";
	}

	friend class Secretary;

	//friend void Secretary::callStudent(Student&);
};

class Secretary {
public:
	void callStudent(Student& student) {
		student.doSomething();
	}

};

class Something {
	int something;
};

class SuperSomething: public Something {
	int super;
public:
	SuperSomething(int super) {
		this->super = super;
	}


	//copy ctor with pointer
	// the official one is with reference 
	SuperSomething(SuperSomething* obj) {

	}
};

class AwesomeSomething : SuperSomething {
	int awesome;
public:
	AwesomeSomething(int awesome, int super)
		:SuperSomething(super) {

	}

	AwesomeSomething():SuperSomething(0) {

	}

	AwesomeSomething(int awesome,
		SuperSomething super) :SuperSomething(&super) {
		this->awesome = awesome;
	}

};

int* generateArray(int requiredSize) {
	int array[10000];
	for (int i = 0; i < requiredSize; i++) {
		array[i] = i + 1;
	}
	return array;
}

void doSomething() {
	int values[100000];
	for (int i = 0; i < 100000; i++) {
		values[i] = 3;
	}
}


int main() {

	int* myArray = generateArray(100);
	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << " " << myArray[i];
	}

	Student student;
	Secretary secretary;
	secretary.callStudent(student);

	AwesomeSomething awesome(1,2);

	doSomething();

	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << " " << myArray[i];
	}

	//delete[] myArray;
	//myArray = generateArray(500);

}
