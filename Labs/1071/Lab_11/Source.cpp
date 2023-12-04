#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

	friend ostream& operator<<(ostream& console, Address& addr);
};

class Box {
	string sender = "";
	float weight = 0;
	Address deliveryAddress; //a box "has" an address
private:
	Box():deliveryAddress("",0,"") {
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

	void addBox(Box box) {
		Box** newBoxes = new Box*[this->noBoxes + 1];
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

int main() {
	//Box box;

	//DeliveryVan  - 1 
	//Box - 100
	//Address - 100

	DeliveryVan van;

	Address csieAddress("Calea Dorobanti", 15, "Bucharest");
	//Box box;
	Box box2("John", "Calea Dorobanti", 15, "Bucharest");
	Box box3("Alice", csieAddress);

	van.addBox(box2);
	van.addBox(box3);

	cout << van;

}


