#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//all classes are public to simplify the solution
//toate clasele sunt publice pentru a simplifica soluția

//class to manage grade data
//clasa pentru a gestiona o nota

class Grade
{

public:
	string course = "*";	//course name | numele cursului
	int value = -1;			//grade value | valoare notei


	//1. implement the Grade default ctor and set course to "" and grade value to 0
	//1. implementati ctorul implicit și setați cursul la "" și valoarea notei la 0

	Grade() {
	}

	//2. implement the parameters ctor
	//2. implementati ctorul cu parametri
	Grade(string course, int value) {

	}
};

//class to manage bachelor program data
//clasa pentru a gestiona programul de licenta

class Program
{
public:
	string name = "";				//program name | numele programului
	char faculty[50] = "";			//faculty name | numele facultatii
	char* university = nullptr;		//university name | numele universitatii

	Program(){ }

	//3. implement the parameters ctor
	//3. implementati ctorul cu parametri
	Program(string name, string faculty, string university)
		:name(name) {
	}


	//4. implement the copy ctor
	//4. implementati constructorul de copiere
	Program(const Program& program) {

	}

	//5. overload equals
	//5. supraincarcati operatorul =
	Program operator=(const Program& program) {
		return *this;
	}

	~Program() {
		delete[] university;
	}
};

//class to manage student data
//clasa pentru a gestiona datele unui student

class Student {

public:
	string name = "";			//student name | numele studentului
	int age = 0;				//student age | varsta studentului
	Program program;			//bachelor program | programul de licenta
	Grade* grades = nullptr;	//grades and their number | notele si numarul lor
	int noGrades = 0;
	bool hasScholarship = false;	//if has scholarship or not | daca are bursa


	Student() {

	}

	Student(string name,int age,string programName,string faculty,string university,bool hasScholarship)
		:name(name),age(age),program(programName, faculty, university),hasScholarship(hasScholarship) {
	}

	~Student() {
		delete[] grades;
	}


	//6. implement the next method that will add a new Grade
	//6. implementați următoarea metodă care va permite adaugarea unei note noi
	void addGrade(string course, int value) {

	}

	//7. implement the next method that will read Student data (read Readme.txt) from a binary file
	//7. implementați următoarea metodă care va citi datele unui Student (citește Readme.txt) dintr-un fișier binar
	void deserialize(string fileName) {
	}

};

class StudentList {
public:
	Student* list = nullptr;
	int noStudents = 0;

	StudentList() {	}

	//8. implement the next method that will read Students data (read Readme.txt) from a binary file
	//8. implementați următoarea metodă care va citi datele mai multor Studenti (citește Readme.txt) dintr-un fișier binar
	void deserialize(string fileName) {
	}
};
