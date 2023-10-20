#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int* createAnArrayWithAllValuesZero(int requiredSize) {
	int* newArray = new int[requiredSize];
	for (int i = 0; i < requiredSize; i++) {
		newArray[i] = 0;
	}
	return newArray;
}

//the method resizes an existing array and return 0 for ok else 1 for error
int resizeWithPointers(int** yourArray, int initialSize, int newSize) {
	if (newSize < initialSize)
		return 1; //error code 1 -  tou can't do the resize
	int* newArray = new int[newSize];
	for (int i = 0; i < initialSize; i += 1) {
		newArray[i] = (*yourArray)[i];
	}
	for (int i = initialSize; i < newSize; i++) {
		newArray[i] = 0;
	}


	delete[] *yourArray;
	*yourArray = newArray;
}

int resizeWithReference(int*& yourArray, int initialSize, int newSize) {
	if (newSize < initialSize)
		return 1; //error code 1 -  tou can't do the resize
	int* newArray = new int[newSize];
	for (int i = 0; i < initialSize; i += 1) {
		newArray[i] = yourArray[i];
	}
	for (int i = initialSize; i < newSize; i++) {
		newArray[i] = 0;
	}


	delete[] yourArray;
	yourArray = newArray;
}

int resizeWithNotWorking(int* yourArray, int initialSize, int newSize) {
	yourArray = new int[newSize];

	return 0;
}

void filterValuesBiggerThanVersion2(
	const int* valori, 
	int nrValori, 
	int valoarePrag, 
	int** valoriMaiMari)
{
	int k = 0;
	for (int i = 0; i < nrValori; i++)
	{
		if (valori[i] >= valoarePrag) {
			k++;  ///numeri si dupa faci alocare!!!
		}
	}

	if (k > 0) {
		*valoriMaiMari = new int[k];

		int j = 0;
		for (int i = 0; i < nrValori; i++) {
			if (valori[i] >= valoarePrag) {
				(*valoriMaiMari)[j++] = valori[i]; ////////////vezi cum ai facut atribuirea!!!!
			}
		}
	}
	else {
		*valoriMaiMari = nullptr;
	}
}

int main() {
	char c = 'Z';

	char faculty[5];
	char name[100];

	char d = 'B';
	
	name[99] = '\0';

	//cout << endl << "Name is " << name;
	//cout << endl << "Faculty is " << faculty;

	//cout << endl << "Your name is :";
	//cin >> faculty;

	//buffer overflow
	//strcpy(faculty, "My name is a very long value aaaaaaaaaaaaaaaaaaaaaaaaa");

	//cout << endl << "Name is " << name;
	//cout << endl << "Faculty is " << faculty;

	int size = 50;
	int* myArray = createAnArrayWithAllValuesZero(size);
	int* results;

	filterValuesBiggerThanVersion2(myArray, 5, 10, &results);

	//int value;

	int values[] = { 10,20,30,40,50,60,70,80 };
	int noValues = 8;
	int filterValue = 30;
	int* biggerValues;

	filterValuesBiggerThanVersion2(values, noValues, filterValue, &biggerValues);

	for (int i = 0; i < noValues; i++) {
		cout << endl << "value is " << biggerValues[i];
	}

}