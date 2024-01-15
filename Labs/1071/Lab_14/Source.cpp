#include <iostream>
#include <string>

using namespace std;

//an abstract class
class Invoiceable {
public:
	virtual void getInvoiceItem() = 0;
	void doSomething(){}
};

class Product : public Invoiceable {
protected:
	string name = "Nothing";
private: 
	float price = 100;
public:

	float getBasePrice() {
		return this->price;
	}

	virtual void printInfo() = 0;
	virtual float getPrice() = 0;

	void addToCart() {
		cout << endl << " Add product to shopping cart";
	}

	//not overriding
	void dosomething() {}
};

class DiscountedProduct : public Product {
	float discount = 10; //percentage
public:
	float getPrice() {
		return this->getBasePrice() * (1 - (float)discount / 100);
	}

	void getInvoiceItem() {
		cout << endl << this->name << " ----- " << this->getPrice();
	}

	void printInfo() {
		cout << endl << "It's a discounted prduct - "
			<< this->discount << "%";
	}
};

class Toy : public Product {
	int minAge;
public:
	float getPrice() {
		return this->getBasePrice();
	}
	void getInvoiceItem() {
		cout << endl << "Toy " << this->name << " ----------- "
			<<this->getPrice();
	}

	void printInfo() {
		cout << endl << "It's a toy";
	}

	void addToCart() {
		cout << endl << " Add toy to shopping cart";
	}
};

int main() {

	//Invoiceable invoiceable;
	//invoiceable.getInvoiceItem();

	DiscountedProduct discountedProduct;
	Toy toy;

	Invoiceable** items = new Invoiceable * [2];
	items[0] = &discountedProduct;
	items[1] = &toy;

	for (int i = 0; i < 2; i++) {
		items[i]->getInvoiceItem();
	}

	Product** products = new Product * [2];
	products[0] = &discountedProduct;
	products[1] = &toy;

	for (int i = 0; i < 2; i++) {
		products[i]->printInfo(); //LATE BIDING
	}

	for (int i = 0; i < 2; i++) {
		products[i]->addToCart(); //EARLY BINDING
	}

}