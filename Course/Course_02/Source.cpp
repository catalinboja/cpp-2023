
#include <stdio.h>

void changeValue(int* variable) {
	*variable = 1000;
}

int main() {

	int noStudents = 100;

	//define pointers
	//pointers are for storing addresses
	//pointers are numeric variables
	int* pointerToNoStudents = nullptr;

	pointerToNoStudents = (int*)100;

	//read the value of the pointer address
	//int anotherValue = (int)pointerToNoStudents;

	//read the value from the pointer address
	//not allowed.....access violation
	//int anotherValue = *pointerToNoStudents;

	
	//printf("\n Value is %d", anotherValue);

	//get the address of noStudents variable
	pointerToNoStudents = &noStudents;

	int anotherValue = *pointerToNoStudents;

	printf("\n Value is %d", anotherValue);

	//writing at pointer address
	*pointerToNoStudents = 200;

	printf("\n Value is %d", noStudents);

	//getting space in HEAP
	int* heapValues = new int[1000];
	int* aSingleIntInHeap = new int;


	//release space in HEAP
	delete[] heapValues;
	delete aSingleIntInHeap;

	changeValue(&noStudents);
	printf("\n Value is %d", noStudents);

}


