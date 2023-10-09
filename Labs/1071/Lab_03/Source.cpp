#include <iostream>
#include<string>

char* getStringFromConsole(int maxLength);
void printString(std::string message, const char* stringToBeDisplayed);
char* getStringFromConsole(std::string message, int maxLength);
bool checkAdminPassword(const char* pass, std::string dbPassword);

void getBonusPoints(int *noPoints, int** points) {
	*noPoints = 20;
	*points = new int[*noPoints];
	for (int i = 0; i < *noPoints; i++) {
		(*points)[i] = i + 1;
	}
}

void getBonusPointsWithReference(int& noPoints, int*& points) {
	noPoints = 20;
	points = new int[noPoints];
	for (int i = 0; i < noPoints; i++) {
		points[i] = i + 1;
	}
}

int main() {

	char username[20];
	char* password = nullptr;

	//username = getStringFromConsole(20);
	strcpy_s(username, 20, getStringFromConsole("Username:", 20));

	//char* temp = getStringFromConsole(20);
	//strcpy_s(username, 20, temp);

	printString("Username is: ",username);

	password = getStringFromConsole("Password:", 100);
	printString("Password is: ", password);

	//avoid memory leak
	delete[] password;
	password = getStringFromConsole("Password:", 100);
	printString("Password is: ", password);

	if (checkAdminPassword(password, "root1234")) {
		std::cout << std::endl << "Hello admin !";
	}
	else {
		std::cout << std::endl << "Wrong admin pass !";
	}

}

bool checkAdminPassword(const char* pass, std::string dbPassword) {
	if (strcmp(pass, dbPassword.c_str()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

char* getStringFromConsole(int maxLength) {
	std::cout << std::endl << "Your input is: ";

	//DON'T DO IT
	//char buffer[1000];

	char* newString = new char[maxLength];
	std::cin >> newString;

	//DON'T DO IT
	//return buffer;

	return newString;
}

char* getStringFromConsole(std::string message, int maxLength) {
	std::cout << std::endl << message;
	
	char* newString = new char[maxLength];
	std::cin >> newString;

	return newString;
}

void printString(std::string message, const char* stringToBeDisplayed) {
	std::cout << std::endl << message << stringToBeDisplayed;
}
