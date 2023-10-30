#include <iostream>
#include <string>
using namespace std;

class Util {
public:
	static char* copyString(const char* source) {
		if (source == nullptr) {
			return nullptr;
		}
		char* value = new char[strlen(source) + 1];
		strcpy_s(value, strlen(source) + 1, source);
		return value;
	}
};

class Concert {
	const string name;
	char* openingBand = nullptr;
	char date[11] = ""; // dd/mm/yyyy
	int capacity = 0;
	static int TOTAL_EVENTS;
public:
	static int getTotalNoOfEvents() {
		return Concert::TOTAL_EVENTS;
	}

	string getName() {
		return this->name;
	}

	char* getOpeningBand() {
		char* copy = Util::copyString(this->openingBand);
		return copy;
	}

	void setOpeningBand(const char* band) {
		//is not this
		//this->openingBand = band;

		//here we get the pointer of the copy
		this->openingBand = Util::copyString(band);
	}

	char* getDate() {
		return Util::copyString(this->date);
	}

	void setDate(const char* newDate) {
		if (strlen(newDate) != 10) {
			throw exception("Wrong date");
		}
		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("Wrong date format");
		}

		strcpy_s(this->date, newDate);
	}

	int getCapacity() {
		return this->capacity;
	}

	void setCapacity(int value) {
		this->capacity = value;
	}

	//default ctor
	Concert(): name("No name"), capacity(0) {
		this->setOpeningBand("None");
		this->setDate("00/00/0000");
		Concert::TOTAL_EVENTS += 1;
	}

	Concert(string name): name(name), capacity(1000) {
		this->setOpeningBand("None");
		this->setDate("00/00/0000");
		Concert::TOTAL_EVENTS += 1;
	}

	Concert(string name,
		const char* date,
		string openingBand,
		int capacity) : name(name), capacity(capacity) {
		this->setDate(date);
		this->setOpeningBand(openingBand.c_str());
		Concert::TOTAL_EVENTS += 1;
	}

	//destructor
	~Concert() {
		delete[] this->openingBand;
		Concert::TOTAL_EVENTS -= 1;
	}

	Concert(Concert& c) : name(c.name){
		this->capacity = c.capacity;
		this->setDate(c.getDate());
		this->setOpeningBand(c.getOpeningBand());
	}
};

int Concert::TOTAL_EVENTS = 0;

void doSomething(Concert c) {

}


int main() {
	cout << endl << "No of concerts: " <<
		Concert::getTotalNoOfEvents();

	//Concert concert;

	//concert.setCapacity(100);
	//concert.setDate("03/06/2024");
	//concert.setOpeningBand("Abba");

	Concert concert(
		"2024 New Year Party",
		"31/12/2023",
		"Abba",
		10000);

	cout << endl << "Date: " << concert.getDate();
	cout << endl << "Band: " << concert.getOpeningBand();
	cout << endl << "Name: " << concert.getName();
	cout << endl << "Capacity: " << concert.getCapacity();

	cout << endl << "No of concerts: " <<
		Concert::getTotalNoOfEvents();

	//copy the concert
	//copy ctor
	Concert newConcert = concert;

	//default ctor
	//Concert newCopy;
	////operator =
	//newCopy = concert;

	doSomething(concert);
}