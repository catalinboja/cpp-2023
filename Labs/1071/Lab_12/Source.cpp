#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void serializeString(string value, ofstream& file) {
	int valueSize = strlen(value.c_str()) + 1;
	file.write((char*)&valueSize, sizeof(int));
	file.write(value.c_str(), sizeof(char) * valueSize);
}

string deserializeString(ifstream& file) {
	int valueSize = 0;
	//read the size
	file.read((char*)&valueSize, sizeof(int));
	//use a stack buffer
	char buffer[1000];
	file.read(buffer, sizeof(char) * valueSize);
	return string(buffer);
}

class Address {
	string street = "";
	int no = 0;
	string city = "";
private:
	Address() {

	}
public:
	Address(string street, int no, string city) :
		street(street), no(no), city(city) {

	}

	void serialize(ofstream& file) {
		//write the number
		file.write((char*)&this->no, sizeof(int));
		//write the street
		// don't serialize the entire string
		//file.write((char*)&this->street, sizeof(string));

		//+ \0
		int valueSize = strlen(this->street.c_str()) + 1;
		//write the string size
		file.write((char*)&valueSize, sizeof(int));
		//write the value
		file.write(this->street.c_str(), sizeof(char) * valueSize);

		valueSize = strlen(this->city.c_str()) + 1;
		file.write((char*)&valueSize, sizeof(int));
		file.write(this->city.c_str(), sizeof(char) * valueSize);
	}

	void deserialize(ifstream& file) {
		//read number
		file.read((char*)&this->no, sizeof(int));
		this->street = deserializeString(file);
		this->city = deserializeString(file);
	}


	friend ostream& operator<<(ostream& console, Address& addr);
};

class Box {
	string sender = "";
	float weight = 0;
	Address deliveryAddress; //a box "has" an address
private:
	Box() :deliveryAddress("", 0, "") {
	}

public:
	Box(string sender, string street, int no, string city)
		:deliveryAddress(street, no, city)
	{
		this->sender = sender;
	}
	Box(string sender, Address address) :
		deliveryAddress(address), sender(sender)
	{
	}

	void serialize(ofstream& file) {
		//write the weight
		file.write((char*)&this->weight, sizeof(float));
		//write the sender
		serializeString(this->sender, file);
		//write the address
		this->deliveryAddress.serialize(file);

	}

	void deserialize(ifstream& file) {
		file.read((char*)&this->weight, sizeof(float));
		this->sender = deserializeString(file);
		this->deliveryAddress.deserialize(file);
	}

	friend ostream& operator<<(ostream& console, Box& box);

};

class DeliveryVan {
	string driver = "";
	//works ONLY if you have the Box default ctor
	//Box boxes[100]
	//Box* boxes = nullptr;

	Box** boxes = nullptr;
	//Box* boxes[100];
	int noBoxes = 0;

public:
	DeliveryVan() {

	}

	DeliveryVan(string driverName) {
		this->driver = driverName;
	}

	void addBox(Box box) {
		Box** newBoxes = new Box * [this->noBoxes + 1];
		for (int i = 0; i < this->noBoxes; i++) {
			newBoxes[i] = this->boxes[i];
		}
		//using the Box copy ctor to create a copy in HEAP
		//box is on addBox stack
		//newBoxes[this->noBoxes] = &box; //NOT ok

		newBoxes[this->noBoxes] = new Box(box);

		delete[] this->boxes;
		this->boxes = newBoxes;

		this->noBoxes += 1;
	}

	void generateDayReport(ofstream& report) {
		if (!report.is_open()) {
			throw exception("File not opened for report");
		}
		report << "\t\t Daily delivery report for " << this->driver;
		for (int i = 0; i < this->noBoxes; i++) {
			report << "\n\t Delivery " << i + 1;
			report << *this->boxes[i];
		}
	}

	void serialize(ofstream& file) {
		//write the driver's name
		serializeString(this->driver, file);

		//write the number of boxes
		file.write((char*)&this->noBoxes, sizeof(int));

		//write each box content ,NOT address
		for (int i = 0; i < this->noBoxes; i++) {
			//file.write((char*)this->boxes[i], sizeof(Box));
			this->boxes[i]->serialize(file);
		}
	}

	void deserialize(ifstream& file) {

		//cleanup previous values
		for (int i = 0; i < this->noBoxes; i++) {
			delete this->boxes[i];
		}
		delete[] this->boxes;

		this->driver = deserializeString(file);
		file.read((char*)&this->noBoxes, sizeof(int));

		this->boxes = new Box * [this->noBoxes];
		for (int i = 0; i < this->noBoxes; i++) {
			this->boxes[i] = new Box("","",0,"");
			this->boxes[i]->deserialize(file);
		}
	}

	friend ostream& operator<<(ostream& console, DeliveryVan& van);
};



ostream& operator<<(ostream& console, Address& addr) {
	console << endl << "Address: " << " " << addr.street <<
		", no " << addr.no << ", " << addr.city;
	return console;
}

ostream& operator<<(ostream& console, Box& box) {
	console << endl << "Delivery from " << box.sender;
	console << endl << "Weight " << box.weight;
	console << box.deliveryAddress;
	return console;
}

ostream& operator<<(ostream& console, DeliveryVan& van) {
	console << endl << "Driver: " << van.driver;
	for (int i = 0; i < van.noBoxes; i++) {
		console << *(van.boxes[i]);
	}
	return console;
}


class FileUtils {
public:
	static void genereateVanReport(DeliveryVan& van, string filename) {
		ofstream report(filename);
		if (!report.is_open()) {
			cout << endl << "**** ISSUES with the file";
		}
		van.generateDayReport(report);
		report.close();
	}

	static void backup(DeliveryVan& van, string filename) {
		ofstream file(filename, ios::binary | ios::ate);
		if (!file.is_open()) {
			cout << endl << "**** ISSUES with the file";
		}

		//TODO: add the serialization
		van.serialize(file);

		file.close();
	}

	static void restore(DeliveryVan& van, string filename) {
		ifstream file(filename, ios::binary);
		if (!file.is_open()) {
			cout << endl << "**** ISSUES with the file";
		}

		//TODO: add the serialization
		van.deserialize(file);

		file.close();
	}
};

int main() {
	//Box box;

	//DeliveryVan  - 1 
	//Box - 100
	//Address - 100

	DeliveryVan van("Bob");

	Address csieAddress("Calea Dorobanti", 15, "Bucharest");
	//Box box;
	Box box2("John", "Calea Dorobanti", 15, "Bucharest");
	Box box3("Alice", csieAddress);

	van.addBox(box2);
	van.addBox(box3);

	cout << van;

	//generate the text report
	FileUtils::genereateVanReport(van, "Van 1 report.txt");


	//ofstream file("test.bin", ios::binary);
	//csieAddress.serialize(file);
	//file.close();

	//FileUtils::backup(van, "Van 1.backup");
	FileUtils::restore(van, "Van 1.backup");

	cout << endl << "**********";
	cout << van;

}


