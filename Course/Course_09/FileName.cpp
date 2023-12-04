#include <iostream>
#include <string>
using namespace std;

class WrongNameException {
	string msg;

public:
	WrongNameException(string message) {
		this->msg = message;
	}
	string what() {
		return this->msg;
	}
};

class WrongAgeException {
	string msg;

public:
	WrongAgeException(string message) {
		this->msg = message;
	}
	string what() {
		return this->msg;
	}
};

class WrongGradeException : public exception {
	WrongGradeException(string message): exception(message.c_str()) {
	}
};

class Student {
	int* grades;
	int noGrades;
	int age;
	string name;

public:
	static const int MIN_AGE = 14;
	void setAge(int value) {
		if (value < MIN_AGE) {
			throw exception("Value is too small for age");

			//catch it by using a exception* and delete it
			//throw new exception("Value is too small for age");
		}
		this->age = value;
	}

	void setName(string value) {
		if (value.size() < 5) {
			throw WrongNameException("Name too short");
		}
		this->name = name;
	}

	float operator()(int index1, int index2) {
		//TO DO: compute average
		return 0;
	}
};

void readStudentAge(Student& s) {
	while (true) {
		try {
			cout << endl << "Student age is: ";
			int value;
			cin >> value;
			s.setAge(value);

			break;
		}
		catch (exception e) {
			cout << endl << "We have a problem " << e.what();
		}
	}
}

int main() {
	Student student;



	try {
		cout << endl << "Student age is: ";
		int value;
		cin >> value;
		student.setAge(value);
		cout << endl << "Student name: ";
		string name;
		cin >> name;
		student.setName(name);

		//does not work for system exceptions
		//int values[10];
		//delete values;

		cout << endl << "Done reading data";
	}
	catch (exception e) {
		cout << endl << "We have a problem " << e.what();
	}
	//catch (exception* e) {
	//	cout << endl << "We have a problem " << e->what();
	//	delete e;
	//}
	catch (WrongNameException e) {
		cout << endl << "We have a *problem* " << e.what();
	}
	catch (...) {
		cout << endl << "Houston we have a problem !";
	}

	//function operator
	float average = student(1, 5); //compute average of grades 1  -> 5

	readStudentAge(student);

	cout << endl << "The end of it";
}