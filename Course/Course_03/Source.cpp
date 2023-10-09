#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

//Course objectives
//arrays - static vs dynamic
//arrays - char arrays/string  vs number arrays

void power(int value, int power);
void power2(int* pValue, int power);
void power3(int& pValue, int power);

int main() {

	int value = 10;
	power(value, 3);

	std::cout << endl << "Value is " << value;

	power2(&value, 3);

	std::cout << endl << "Value is " << value;

	power3(value, 3);

	std::cout << endl << "Value is " << value;

	//strings
	char variable = 48;
	variable += 1;

	cout << endl << "The char is " << variable;

	//char letter = "a";
	char letter = 'a';

	cout << endl << "The char is " << letter;

	const int constValue = 10;
	//constValue = 100;

	//define char arrays
	//static 


	//all static arrays names are POINTERS which are CONSTANT
	char name[] = "John";
	char firstName[100];

	//name = "Alice";
	//firstName = "Popescu";

	//change arrays values
	name[0] = 'j';

	cout << endl << "Name is " << name;

	name[0] = 'a';
	name[1] = 'b'; 

	cout << endl << "Name is " << name;

	//remember strcpy, strlen, strcmp, strcat
	strcpy(name, "Bob");

	strcpy_s(name,5, "Bob");

	cout << endl << "Name is " << name;

	name[2] = '\0';
	cout << endl << "Name is " << name;


	//the input exceeds the destination size
	//strcpy(name, "A very long name that will not fit");
	//cout << endl << "Name is " << name;

	//dynamic arrays
	char* lastName = nullptr;

	if (lastName != nullptr) {
		cout << endl << "Last Name is " << lastName;
	}

	//lastName = "John";

	//1. allocate space
	lastName = new char[strlen("John" ) + 1 ];


	//don't forget
	cout << endl << "Size is " << strlen("John" + 1);


	//2. copy the value
	strcpy(lastName, "John");

	if (lastName != nullptr) {
		cout << endl << "Last Name is " << lastName;
	}

	//reallocate space

	//avoid thr memory leak
	delete[] lastName;
	lastName = new char[strlen("A very long name that will not fit") + 1];

	strcpy(lastName, "A very long name that will not fit");

	if (lastName != nullptr) {
		cout << endl << "Last Name is " << lastName;
	}

	delete[]  lastName;

	string newName = "John";
	newName = "Alice";
	newName = "Popescu " + newName;

	cout << endl << "New Name is " << newName;

}

void power(int value, int power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= value;
	}
	value = result;
}

void power2(int* pValue, int power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= (*pValue);
	}
	*pValue = result;
}

void power3(int& value, int power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= value;
	}
	value = result;
}