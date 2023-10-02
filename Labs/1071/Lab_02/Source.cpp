
#include <iostream>
using namespace std;

void printValues(int value1, int value2) {
	std::cout << std::endl << "value1 = " << value1 << " and value2 = " << value2;
}

void interchange(int vb1, int vb2) {
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;
}

void interchange2(int *p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void interchange3(int& vb1, int& vb2) {
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;
}

int main() {

	int value1 = 10;
	int value2 = 20;

	//std::cout << std::endl << "value1 = " << value1 << " and value2 = " << value2;
	printValues(value1, value2);

	int temp = value1;
	value1 = value2;
	value2 = temp;

	//std::cout << std::endl << "value1 = " << value1 << " and value2 = " << value2;
	printValues(value1, value2);

	interchange(value1, value2);
	printValues(value1, value2);

	interchange2(&value1, &value2);
	printValues(value1, value2);

	interchange3(value1, value2);
	printValues(value1, value2);
}