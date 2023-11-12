#include <iostream>
#include <string>
using namespace std;

class Student {
	const int id;
	char* name;
	static int NO_STUDENTS;
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
		this->name = new char[name.size() + 1];
		strcpy_s(this->name, name.size() + 1, name.c_str());
	}

	~Student() {
		cout << endl << "Destructor";
		delete[] this->name;
		Student::NO_STUDENTS -= 1;
	}

	Student():id(0) {

	}

	Student(const Student& s):id(s.id) {
		cout << endl << "Copy ctor";
		this->setName(string(s.name));
		//s.setName(this->getName());
	}

	bool operator>(Student s) {
		
	}

	//static bool operator>(Student s, Student p) {

	//}

	void operator=(const Student& source) {
		//source.setName(this->getName());


		//test for self equality
		if (&source == this) {
			return;
		}

		//this->id = source.id;
		delete[] this->name;
		this->setName(string(source.name));
	}
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
		Student student;
		student.setName("John Doe");
		//Student johnDoe(0, "John Doe");
		return student;
	}


};

Student createJohnDoeStudent() {
	Student johnDoe(0, "John Doe");
	return johnDoe;
}

int Student::NO_STUDENTS = 0;

//bool operator>(Student s, Student p) {
//
//}

bool operator>(Student s, double average) {
	cout << endl << s.getName();
}


//ONLY by global methods
bool operator>(double average, Student s) {
	cout << endl << s.getName();
}

int main() {
	Student john(1, "John");

	cout << endl << "Name is " << john.getName();

	StudentUtil::printStudent(john);
	Student johnDoe = createJohnDoeStudent();

	Student johnClone = john;

	//cout << endl << "Name is " << johnDoe.getName();

	//Student test = StudentUtil::createJohnDoeStudent();

	Student justAStudent(2, "Bob");

	justAStudent = john;

	//john = john;

	if (john > johnDoe) { //operator > (Student, Student)
						  // john.operator>(johnDoe)

	}

	if (john > 9.0) { //operator > (Student, double)

	}

	if (9.0 > john) { //operator > (Student, double)

	}

	int vb = 10;
	int result = vb + 10;

	//result = operator+(vb, 20);
	if (vb > 5) {		//operator > (int, int)
		cout << endl << "It's greater";
	}



}