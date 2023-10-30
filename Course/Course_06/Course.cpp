
#include <iostream>
#include <string>
using namespace std;

enum class StudentType { BACHELOR = 10, MASTER, PHD = 20 };

class Student {
private:
	const int id;
	string name = "Anonymous";
	int age = 0;
	int noGrades = 0;
	int* grades = nullptr;
	bool hasScholaship = false;
	StudentType type = StudentType::BACHELOR;
	char gender;

	static int noBoys;
	static int noGirls;
	static int noStudents;

public:
	static const int MAX_AGE = 100;
	static const int MIN_AGE = 5;
	static const int MIN_NAME = 2;


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

	string getName() {
		return this->name;
	}

	void setName(string newName) {
		if (newName.size() <= Student::MIN_NAME) {
			throw exception("Name too short");
		}
		this->name = newName;
	}

	int* getGrades() {
		//don't
		//return this->grades;

		//int copy[1000];
		//for (int i = 0; i < this->noGrades; i++) {
		//	copy[i] = this->grades[i];
		//}
		//return copy;

		int* copy = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			copy[i] = this->grades[i];
		}
		return copy;
	}

	void setGrades(int* newGrades, int newNoGrades) {
		//shallow-copy
		//this->grades = newGrades;

		//deep-copy
		delete[] this->grades;
		this->grades = new int[newNoGrades];
		memcpy(this->grades, newGrades, sizeof(int) * newNoGrades);

		this->noGrades = newNoGrades;
	}

	void getsScolarship() {
		this->hasScholaship = true;
	}

	void losesScholarship() {
		this->hasScholaship = false;
	}

	//constructor
	//has default value for age
	Student(string name, int age = 20): id(0) {
		//this->id = 0;
		this->name = name;
		this->setAge(age);
		//shadowing
		//name = name;
		this->name = name;
		Student::noStudents += 1;
	}

	Student(int id, string name, int age, char gender): id(id) {
		this->setName(name);
		this->setAge(age);

		//shadowing
		//gender = gender;
		this->gender = gender;

		if (this->gender == 'M') {
			Student::noBoys += 1;
		}
		else {
			Student::noGirls += 1;
		}
		Student::noStudents += 1;
	}

	Student(string name, char gender, 
		int age, int* grades, int noGrades): id(Student::noStudents) {

		this->setName(name);
		this->setAge(age);
		this->setGrades(grades, noGrades);
		this->gender = gender;


		if (this->gender == 'M') {
			Student::noBoys += 1;
		}
		else {
			Student::noGirls += 1;
		}
		Student::noStudents += 1;
	}

	Student(int id, char gender, string name, int age)
		: id(id), gender(gender), name(name), age(age) {

	}

	//default ctor
	//Student() {

	//}

	void print() {
		cout << endl << "Name: " << this->name;
		cout << endl << "Age: " << this->age;
		cout << endl << (this->hasScholaship ? "Has scholarship" : "No");
		
		if (this->grades != nullptr) {
			cout << endl << "Grades:";
			for (int i = 0; i < this->noGrades; i++) {
				cout << " " << this->grades[i];
			}
		}
	}

	static int getNoBoys() {
		//there is no this here
		return Student::noBoys;
	}

	static int getNoGirls() {
		//there is no this here
		return Student::noGirls;
	}

	//destructor
	~Student() {
		delete[] this->grades;
		//cout << endl << "Calling the class destructor ";
	}

	//copy constructor
	Student(Student& stud):id(0) {
		this->setGrades(stud.grades, stud.noGrades);
	}
};

//only way to init a non constant static attribute
int Student::noBoys = 0;
int Student::noGirls = 0;
int Student::noStudents = 0;

//the function will use the copy ctor to create a local copy on its stack
void doSomething(Student stud) {

}

Student doSomethingElse() {
	Student stud("Test",23);
	return stud;
}

int main() {

	Student bob("Bob");
	//Student::noBoys += 1;

	Student john(1, "John", 22, 'M');
	//Student::noBoys += 1;
	//Student::noBoys += 1;
	Student alice(2, "Alice", 22, 'F');
	//Student::noGirls += 1;

	cout << endl << "No boys: " << Student::getNoBoys();
	//cout << endl << "No girls: " << Student::noGirls;

	john.print();


	int grades[] = { 10,10,9,10 };
	int noGrades = 4;

	john.setGrades(grades, noGrades);

	john.print();

	grades[0] = 4;

	john.print();

	//test the destructor
	//for (;;) {
	//	Student* pVader = new Student("Vader", 23);
	//	pVader->setGrades(grades, noGrades);
	//	delete pVader;
	//}

	//testing the destructor
	Student* pVader = new Student("Vader", 23);
	pVader->setGrades(grades, noGrades);
	delete pVader;


	//calling the copy ctor
	Student johnClone = john;
	doSomething(john);

}