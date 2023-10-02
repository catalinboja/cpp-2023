#include <stdio.h>
#include <malloc.h>


//things to remember from C
//strings managed as char message[100] or char* message
//some string processing from string.h, like strcpy, strlen, strcmp
//arrays: static and dynamic 
//pointers
//funtions and passing parameters to functions
//data types
//algorithms: sum of array elements, average, min or max

int main() {
	//return 0;

	const int vb = 3;
	int array[vb];

	//array[1000] = 10;

	int a = 0;

	if (a != 0) {
		int result = 10 / a;
	}

	printf("\n hello world !");

	//recap on arrays
	int values[10];	//static array


	//we don't do this
	int values[100000];
	int noValues = 10;

	noValues = 20;

	//dynamic arrays
	int* dynamicValues;
	//dynamicValues = (int*) malloc(10 * sizeof(int));

	//create the array in HEAP
	dynamicValues = new int[10];

	//remove it if you don't need it anymore
	delete[] dynamicValues;

	//one integer in HEAP
	int* oneInteger = new int;
	delete oneInteger;



}