#include <iostream>
#include <string>
using namespace std;

//shadowing
//setter for a char attribute
//setter for boolean attributes
//constructor/functions overloading
//long cout vs printf
//destructor
// copy ctor 
//enum class vs enum
//shallow copy



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
};

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

}