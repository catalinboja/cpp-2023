#include <iostream>
#include <string>
using namespace std;

//"=" vs "=="

//if(student == student)
//student = student 

class Student {
	char* name;

	void operator= (const Student& s) {
		if (this == &s) {
			return;
		}
		delete this->name;
		this->name = new char[strlen(s.name) + 1];
	}

	bool operator==(const Student s) {
		return strcmp(this->name, s.name) == 0;
	}
};


class WrongDateFormatException {

};

class WrongTestDurationException {
	string message;
public:
	WrongTestDurationException(string msg) {
		this->message = msg;
	}

	WrongTestDurationException() {
		this->message = "";
	}
	string what() {
		return this->message;
	}
};

class WrongStudentNameException : public exception {
public:
	WrongStudentNameException(string msg):exception(msg.c_str()) {

	}

	WrongStudentNameException() {

	}
};

class LaboratoryTest {
	string date = "";		//dd/mm/yyyy
	int durationInMinutes = 0;
	string* students = nullptr;
	int noStudents = 0;

	const static int MIN_DURATION = 30;
public:
	void setDate(string newDate) {
		if (newDate.size() < 6 ||
			newDate[2] != '/' ||
			newDate[5] != '/' || 
			newDate.size() != 10) {
			throw WrongDateFormatException();
		}
		this->date = newDate;
	}

	void setDuration(int minutes) {
		if (minutes < LaboratoryTest::MIN_DURATION) {
			string msg = "Duration must be  >= " + MIN_DURATION;
			throw WrongTestDurationException(msg);
		}
		this->durationInMinutes = minutes;
	}

	void enrollStudent(string studentName) {
		if (studentName.size() < 3) {
			throw WrongStudentNameException("Name too short");
		}
		string* newList = new string[this->noStudents + 1];
		for (int i = 0; i < this->noStudents; i++) {
			newList[i] = this->students[i];
		}
		delete[] this->students;
		this->students = newList;
		this->students[this->noStudents] = studentName;
		this->noStudents += 1;
	}
};

int main() {

	LaboratoryTest test;

	while (true) {

		try {
			cout << endl << "Test date: ";
			string testDate;
			cin >> testDate;
			test.setDate(testDate);
			cout << endl << "Test duration: ";
			int duration;
			cin >> duration;
			test.setDuration(duration);
			cout << endl << "Number of students: ";
			int noStudents;
			cin >> noStudents;
			for (int i = 0; i < noStudents; i++) {
				cout << endl << "Student name: ";
				string name;
				cin >> name;
				test.enrollStudent(name);
			}
			break;
		}
		catch (WrongDateFormatException e) {
			cout << endl << "Wrong date";
		}
		catch (WrongTestDurationException e) {
			cout << endl << e.what();
		}
		catch (WrongStudentNameException e) {
			cout << endl << e.what();
		}
		catch (...) {
			cout << endl << "We have an issue";
		}

	}


}