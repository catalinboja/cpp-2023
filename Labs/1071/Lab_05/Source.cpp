#include <iostream>
using namespace std;

//define a class that will manage a courier roadmap
//store the roadmap
//store the name of the driver
//store the fuel consumption per km
//store no of packages

//define at least 2 ctors with parameters
//define the default ctor
//define a public a interface for attributes
//implement a method that allow users to check if the roadmap 
//	contains a given address



class Courier {
	string name = "";
	float litersPerKm = 0;
	int noPackages = 0;
	string* roadmap = nullptr;
	int noLocations = 0;

public:

	static int const MIN_SIZE_FOR_NAME = 3;

	string getName() {
		return this->name;
	}
	void setName(string newName) {
		//validate input
		if (newName.size() < Courier::MIN_SIZE_FOR_NAME) {
			throw exception("Short name");
		}
		if (newName[0] < 'A' || newName[0] > 'Z') {
			throw exception("First letter is not capital letter");
		}

		this->name = newName;
	}

	float getLiters() {
		return this->litersPerKm;
	}

	void setFuelConsumption(float litersPerKm) {
		if (litersPerKm <= 0) {
			throw exception("Wrong value");
		}
		//shadowing
		//litersPerKm = litersPerKm;

		this->litersPerKm = litersPerKm;
	}

	int getNoPackages() {
		return this->noPackages;
	}

	void setNoPackages(int noPackages) {
		if (noPackages <= 0) {
			throw exception("No packages");
		}
		this->noPackages = noPackages;
	}

	string* getRoadmap() {
		string* copy = new string[this->noLocations];
		for (int i = 0; i < this->noLocations; i++) {
			copy[i] = this->roadmap[i];
		}
		return copy;
	}

	void setRoadmap(string* newRoadmap, int noLocations) {
		//shallow copy
		//this->roadmap = newRoadmap;

		//deep copy
		this->roadmap = new string[noLocations];
		for (int i = 0; i < noLocations; i++) {
			this->roadmap[i] = newRoadmap[i];
		}
		this->noLocations = noLocations;
	}

	bool goesToAddress(string address) {
		if (this->roadmap == nullptr) {
			return false;
		}
		for (int i = 0; i < this->noLocations; i++) {
			if (this->roadmap[i] == address)
				return true;
		}
		return false;
	}


	//not OK
	//void setNoLocations(int no) {
	//	this->noLocations = no;
	//}

	//constructors
	//default ctor
	Courier() {
		this->setName("John Doe");
		this->setFuelConsumption(0.7);
		this->setNoPackages(1);
	}

	//ctor with parameters
	Courier(string name) {
		this->setName(name);
	}

	Courier(
		string name,
		float fuelConsumption,
		int noPackages,
		string* roadmap,
		int noLocations) {
		this->setName(name);
		this->setFuelConsumption(fuelConsumption);
		this->setNoPackages(noPackages);
		this->setRoadmap(roadmap, noLocations);
	}


};

int main() {

	Courier john;
	john.setName("John");
	cout << endl << "Driver name is " << john.getName();
	//john.setName("A");
	//john.setName("abcd");

	john.setFuelConsumption(0.5);
	cout << endl << "Fuel consumption " << john.getLiters();

	string roadmap[] =
	{ "Piata Victoriei", "Piata Romana", "Pipera", "Piata Unirii" };
	int noLocations = 4;

	john.setRoadmap(roadmap, noLocations);
	cout << endl << "First address is " << john.getRoadmap()[0];

	roadmap[0] = "Ploiesti";
	cout << endl << "First address is " << john.getRoadmap()[0];

	Courier bob("Bob");
	Courier dave("Dave", 0.8, 15, roadmap, noLocations);

	return 0;
}
