#include <iostream>
#include <string>

using namespace std;

class Product {
private:
	string name = "";
	float price = 0;
	int soldProductsPerMonth[12];
	int currentMonth = 0; //from 0 (Jan) to 11 (Dec)

public:
	Product(string name, float price) 
		:name(name), price(price) {
		for (int i = 0; i < 12; i++) {
			this->soldProductsPerMonth[i] = 0;
		}
		this->currentMonth = 0;
	}

	int getMonthData(int monthIndex) {
		return this->soldProductsPerMonth[monthIndex];
	}

	//postfix version
	Product operator++(int) {
		Product copy = *this;
		this->price += 1;
		return copy;
	}

	//prefix version
	Product operator++() {
		this->price += 1;
		return *this;
	}

	//index operator
	int& operator[](int index) {
		if (index < 0 || index > 11) {
			throw exception("Wrong month index");
		}
		return this->soldProductsPerMonth[index];
	}

	bool operator==(Product prod) {
		if (this->name == prod.name && this->price == prod.price) {
			return true;
		}
		else {
			return false;
		}

		//return (this->name == prod.name && this->price == prod.price);
	}

	bool operator >= (Product prod) {
		if (this->price >= prod.price) {
			return true;
		}
		else {
			return false;
		}
	}


	friend void operator<<(ostream& console, Product& prod);
};

void operator<<(ostream& console, Product& prod) {
	console << endl << "Product name: " << prod.name;
	console << endl << "Product price: " << prod.price;
	console << endl << "Current month: " << prod.currentMonth;
	console << endl << "Previous data: ";
	//we print also the current month
	for (int i = 0; i <= prod.currentMonth; i++) {
		console << " " << prod.soldProductsPerMonth[i];
	}
}

int main() {
	Product p("Laptop", 2500);
	cout << p;

	int vb = 10;
	int vb2 = ++vb;
	int vb3 = vb++;


	cout << endl << " vb1 = " << vb 
		<< " vb2 << " << vb2 << " vb3 = " << vb3;

	//post
	Product temp1 = p++;	//increment the price
	cout << endl << "****************************";
	cout << temp1;
	cout << p;
	
	//pre
	temp1 = ++p;
	cout << endl << "****************************";
	cout << temp1;
	cout << p;

	//index operator
	cout << endl << "Feb sales data is " << p[1];
	p[0] = 143;
	cout << p;

	if (p == temp1) {
		cout << endl << "They have the same name and price";
	}
	else {
		cout << endl << "They are different";
	}

	if (p >= temp1) {
		cout << endl << "P has a price greated or equal than temp1";
	}
	else {
		cout << endl << "P has a smaller price than temp1";
	}
}