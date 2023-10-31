#include <iostream>
#include <string>
using namespace std;

//shadowing
//setter for a char attribute
//setter for boolean attributes
//constructor/functions overloading
//long cout vs printf
//destructor
//copy ctor 
//enum class vs enum
//shallow copy

enum class TestType {BACHELOR, MASTER};

class StudentGroup {
	int groupNo = 1071; //code C1056 - Cybernetics 1056
	char code = 'C';
	string* students = nullptr;
	int noStudents = 0;
	bool isBachelor = false;

public:
	void setCode(char code) {
		//shadowing 
		//code = code;
		this->code = code;
	}

	//void setCode(char newCode) {
	//	code = newCode;
	//}
	//void setCode(char _code) {
	//	code = _code;
	//}

	char getCode() {
		return this->code;
	}

	int getNumber() {
		return this->groupNo;
	}

	bool isBachelorGroup() {
		return this->isBachelor;
	}

	void registerForBachelorProgram() {
		this->isBachelor = true;
	}

	void registerForAnotherProgram() {
		this->isBachelor = false;
	}

	void setIsBachelor(bool value) {
		this->isBachelor = value;
	}

	//overloading - multiple methods with the same name
	StudentGroup(char code, int number) {
		this->setCode(code);
		this->groupNo = number;
	}

	StudentGroup(char code, int number, int year) {
		this->setCode(code);
	}

	//StudentGroup(char code, int year) {
	//	this->setCode(code);
	//}

	StudentGroup(int number, bool isBachelorGroup) {
		this->setCode(code);
		this->groupNo = number;
		this->setIsBachelor(isBachelorGroup);
	}

	StudentGroup(char code, int number, bool isBachelorProgram) {
		this->setCode(code);
		this->groupNo = number;
		if(isBachelorProgram){
			this->registerForBachelorProgram();
		}
		//this->setIsBachelor(isBachelorProgram);
	}

	StudentGroup() {

	}

	void setStudents(string* students, int  noStudents) {
		delete[] this->students;
		this->students = new string[noStudents];
		for (int i = 0; i < noStudents; i++) {
			this->students[i] = students[i];
		}
		this->noStudents = noStudents;
	}

	void printStudentsList() {
		if (this->students != nullptr) {
			cout << endl << "Students: ";
			for (int i = 0; i < this->noStudents; i++) {
				cout << " " << this->students[i];
			}
		}
		else {
			cout << endl << "No students";
		}
	}

	string* getStudentsList() {
		//don't do this
		//return this->students;

		string* copy = new string[this->noStudents];
		for (int i = 0; i < this->noStudents; i++)
		{
			copy[i] = this->students[i];
		}

		return copy;
	}

	~StudentGroup() {
		cout << endl << "Apel destructor";
		delete[] this->students;
	}

	StudentGroup(StudentGroup& group) {
		cout << endl << "Calling copy ctor";
		this->code = group.code;
		//this->students = group.students;
		this->students = group.getStudentsList();
		this->noStudents = group.noStudents;
	}
};

void takeExam() {
	StudentGroup g1071;
	string students[] = { "John", "Alice", "Bob" };
	g1071.setStudents(students, 3);
}

void takeExam(StudentGroup group) {
	cout << endl << group.getNumber() << " takes the exam";
}

void takeExam(StudentGroup* group) {
	cout << endl << group->getNumber() << " takes the exam";
}

StudentGroup doSomething() {
	StudentGroup g1071;
	string students[] = { "John", "Alice", "Bob" };
	g1071.setStudents(students, 3);
	return g1071;
}

//void takeExam(StudentGroup& group) {
//	cout << endl << group.getNumber() << " takes the exam";
//}

int main() {
	StudentGroup g1071;

	g1071.setCode('M');

	printf("\n Group code and number %c%d",
		g1071.getCode(), g1071.getNumber());
	cout << endl << "Group code and number "
		<< g1071.getCode() << g1071.getNumber();


	StudentGroup g1072('C', 1072, true);
	StudentGroup g1500('M', 1500);
	StudentGroup g1768(1768, false);

	string students[] = { "John", "Alice", "Bob" };
	g1072.setStudents(students, 3);

	g1072.printStudentsList();

	string* studentsList = g1072.getStudentsList();
	studentsList[0] = "Vader";
	delete[] studentsList;

	g1072.printStudentsList();

	//for (;;) {
	//	takeExam();
	//}

	takeExam();

	StudentGroup* pGrupa = new StudentGroup('C', 1071);
	pGrupa->setStudents(students, 3);
	delete pGrupa;

	takeExam(g1072);

	//calling copy ctor
	StudentGroup g1072Clone = g1072;

	TestType type = TestType::BACHELOR;
	//works with simple enum
	//if (type == 0) {

	if (type == TestType::BACHELOR) {
		cout << endl << "Is Bachelor";
	}
	
}