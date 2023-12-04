#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
	const int id;
	char* name;
	int scolarshipValue;
	int grades[10];
	int noGrades;

	static int NO_STUDENTS;
	static int ID_COUNTER;

	Student() :id(0) {

	}
public:
	Student(const char* name) : id(++ID_COUNTER) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		Student::NO_STUDENTS += 1;
	}

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

	void setGrades(int* grades, int noGrades) {
		if (noGrades > 10) {
			throw exception("Too many");
		}
		for (int i = 0; i < noGrades; i++) {
			this->grades[i] = grades[i];
		}
		this->noGrades = noGrades;
	}

	Student operator=(const Student& source) {
		//source.setName(this->getName());


		//test for self equality
		if (&source == this) {
			return source;
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

	//files
	//serializing objects
	void saveData(ofstream& file) {
		if (!file.is_open()) {
			throw exception("file is not opened");
		}
		//IT's A mistake
		// YOU WRITE ADDRESSES 
		// YOU should write only values
		//file.write((char*)this, sizeof(Student));

		file.write((char*)&this->id, sizeof(int));
		int nameSize = strlen(this->name) + 1;
		file.write((char*)&nameSize, sizeof(int));
		file.write(this->name, sizeof(char) * (strlen(this->name) + 1));
		file.write((char*)&this->scolarshipValue, sizeof(int));

		file.write((char*)&this->noGrades, sizeof(int));

		//option 1 - dump the entire static array
		//file.write((char*)this->grades, sizeof(this->grades));

		//option 2 - write only the values that we use
		file.write((char*)this->grades, sizeof(int) * this->noGrades);
		//for (int i = 0; i < this->noGrades; i++) {
		//	file.write((char*)&this->grades[i], sizeof(int));
		//}
	}

	//deserializing objects
	void readData(ifstream& file) {
		if (!file.is_open()) {
			throw exception("file is not opened");
		}
		//file.read((char*)this, sizeof(Student));

		//extra
		//int* add = (int*) & this->id;
		//*add = 23;

		file.read((char*)&this->id, sizeof(int));

		int nameSize;
		file.read((char*)&nameSize, sizeof(int));
		delete this->name;
		this->name = new char[nameSize];
		file.read((char*)this->name, sizeof(char) * nameSize);
		file.read((char*)&this->scolarshipValue, sizeof(int));
		file.read((char*)&this->noGrades, sizeof(int));
		for (int i = 0; i < this->noGrades; i++) {
			file.read((char*)&this->grades[i], sizeof(int));
		}

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
		Student student("John Doe");
		//Student johnDoe(0, "John Doe");
		return student;
	}

	//by class memeber function
	//we can't do it because we get this as the 1st argument
	//void operator<<(ostream& console) { //Student* this, ostream& console

	//}

};

Student createJohnDoeStudent() {
	Student johnDoe("John Doe");
	return johnDoe;
}

int Student::NO_STUDENTS = 0;
int Student::ID_COUNTER = 0;

//by global method
ostream& operator<<(ostream& console, Student& s) {

	//DON'T USE cout, use your variable aka console
	console << endl << "Student id is: " << s.id;
	console << endl << "Student name is: " << s.getName();
	console << endl << "Student scholarship value is: " << s.scolarshipValue;
	console << endl << "Grades: ";
	for (int i = 0; i < s.noGrades; i++) {
		console << " " << s.grades[i];
	}
	
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

class Address {
	string street;
	int number;
	string city;
	string country;
public:
	Address(string str, int no, string city, string country)
	:street(str), number(no), city(city), country(country){

	}
};

//relations between classes
//composition - "has a"
class Faculty {
	Address address;		//1:1
	//Student *students;		//1:M
	Student** students;
	int noStudents;
public:
	Faculty():address("Calea Dorobanti", 15,"Bucharest", "Romania") {

	}
	Faculty(string str, int no, string city, string country) :address(str, no, city, country) {

	}

	Faculty(Address adr) : address(adr) {

		//this->students = new Student[10];
		this->students = new Student*[10];
		this->students[0] = new Student("john");
	}
};



int main() {
	Student john("John");
	Student alice("Alice");
	Student bob("Bob");

	int grades[] = { 10,10,9,8 };
	john.setGrades(grades, 4);

	//serializing objects

	ofstream file("student.bin", ios::binary);
	john.saveData(file);
	file.close();

	ifstream file2("student.bin", ios::binary);
	bob.readData(file2);
	file2.close();
	cout << bob;

	//testing composition
	Faculty csie;
}