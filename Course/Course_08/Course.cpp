#include <iostream>
#include <string>
using namespace std;

class Student {
	const int id;
	char* name;
	static int NO_STUDENTS;
	int scolarshipValue;
	int grades[10];
	int noGrades;

	Student() :id(0) {

	}
public:
	Student(int id, const char* name) : id(id) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		Student::NO_STUDENTS += 1;
	}

	string getName() {
		return string(this->name);
	}

	void setName(string name) {
		delete[] this->name;
		this->name = new char[name.size() + 1];
		strcpy_s(this->name, name.size() + 1, name.c_str());
	}

	~Student() {
		cout << endl << "Destructor";
		delete[] this->name;
		Student::NO_STUDENTS -= 1;
	}

	Student(const Student& s) :id(s.id) {
		cout << endl << "Copy ctor";
		this->setName(string(s.name));
		//s.setName(this->getName());
		Student::NO_STUDENTS += 1;
	}

	Student operator=(const Student& source) {
		//source.setName(this->getName());


		//test for self equality
		if (&source == this) {
			return;
		}

		//this->id = source.id;
		delete[] this->name;
		this->setName(string(source.name));

		return source;
		//return *this;
	}

	void operator+=(int value) {
		this->scolarshipValue += value;
	}

	void operator-=(int value) {
		this->scolarshipValue -= value;
	}

	Student operator+(int value) {
		//DON'T change the object
		//this->scolarshipValue += value;
		Student result = *this;
		result.scolarshipValue += value;
		return result;
	}

	bool operator!() {
		return this->scolarshipValue >= 0;
	}

	bool operator>(int value) {
		if (this->scolarshipValue > value) {
			return true;
		}
		else {
			return false;
		}
	}

	//cast operator
	explicit operator int() {
		return this->scolarshipValue;
	}


	//is an OPTION
	friend ostream& operator<<(ostream& console, Student& s);
	friend void operator>>(istream& console, Student& s);
};

class StudentUtil {
public:
	static void printStudent(Student student) {
		cout << endl << "Student data is ";
		cout << endl << student.getName();
	}


	//alternatives that DON'T require the copy ctor
	// 
	//static void printStudent(Student& student) {
	//	cout << endl << "Student data is ";
	//	cout << endl << student.getName();
	//}

	//static void printStudent(Student* student) {
	//	cout << endl << "Student data is ";
	//	cout << endl << student->getName();
	//}

	static Student createJohnDoeStudent() {
		Student student(0, "John Doe");
		//Student johnDoe(0, "John Doe");
		return student;
	}

	//by class memeber function
	//we can't do it because we get this as the 1st argument
	//void operator<<(ostream& console) { //Student* this, ostream& console

	//}

};

Student createJohnDoeStudent() {
	Student johnDoe(0, "John Doe");
	return johnDoe;
}

int Student::NO_STUDENTS = 0;

//by global method
ostream& operator<<(ostream& console, Student& s) {

	//DON'T USE cout, use your variable aka console
	console << endl << "Student name is: " << s.getName();
	console << endl << "Student scholarship value is: " << s.scolarshipValue;
	return console;
}

void operator>>(istream& console, Student& s) {
	cout << endl << "Student name is ";
	char buffer[2000];
	//console >> buffer; //stops on Space
	console.getline(buffer, 2000); //if you need space in the string
	console.clear();
	s.setName(buffer);
	cout << endl << "Student scholarship is ";
	console >> s.scolarshipValue;
}

Student operator+(int value, Student s) {
	return s + value; //because we already have it
}




int main() {
	Student john(1, "John");
	Student alice(1, "Alice");
	Student bob(1, "Bob");

	john = alice = bob;

	//console streams
	cout << john;
	cin >> john;
	cout << john;

	cout << john << alice;

	//math operators
	//binary operators
	john += 230;		//add 230 to the scholarship
	john -= 100;		//substract 100 from scholarship

	//same for *=, /=

	Student clone = john + 500;
	Student clone2 = 500 + john;
	//same with *, /, -

	//unary operators
	//john++;		//postfix incrementation
	//++john;		//prefix incrementation

	//same for --

	//logic operators
	if (!john) {			//negation operator
		cout << endl << "John does not have a scholarship";
	}
	//if (john == clone) {
	//	cout << endl << "They have the same name";
	//}

	//if (john > clone) {
	//	cout << endl << "John has a bigger scolarship";
	//}

	if (john > 500) {
		cout << endl << "John has scolarship greater tahn 500";
	}

	//same for <, =<, >=, !=


	//cast operator
	int scholarshipValue = (int)john;

	//index operator
	//cout << endl << "John 2nd grade is " << john[1];
	//john[1] = 10;


}