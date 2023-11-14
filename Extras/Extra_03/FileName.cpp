#include <iostream>
#include <string>

namespace something{
	int value = 10;
}

namespace somethingelse {
	int value = 20;
}

//overloading
int sum(int a, int b) {
	return a + b;
}

int sum(int a, int b, int c) {
	return a + b + c;
}

float sum(float a, float b) {
	return a + b;
}




class Message {
	std::string text;
	int priority = 0;
public:
	void increasePriorityBy(int value) {
		this->priority += value;
	}

	void operator+=(int value) {
		this->priority += value;
	}

	static void doSomething() {
		//this->priority = 20;
	}

	explicit operator int() {
		return this->priority;
	}

	//pre
	Message operator++() {
		this->priority += 1;
		return *this;
	}

	//post
	Message operator++(int) {
		Message copy = *this;
		this->priority += 1;
		return copy;
	}

	friend void operator<<(std::ostream& c, Message value);

};

void operator<<(std::ostream& c, Message value) {
	c << value.priority;
}

class Util {
private:
	Util() {}
public:
	static void doSomething() {
		Message m;
		std::cout << m;
	}
};



//Disadvantages for overloading operators by global methods
//....when this is an option

//easy to forget to pass the objects by reference
//...when you need to change their values
//void operator+=(Message m, int value) {  //need a reference
//	//m.priority += value; //does not have access on private
//	m.increasePriorityBy(value);
//}

int main() {

	std::cout << "Suma " << sum(2, 3);
	std::cout << "Suma " << sum(2, 3, 4);

	Message m;

	std::cout << m;

	int vb = 10;
	vb += 20;

	m += 20;
	//20 + m;
	m.increasePriorityBy(20);

	std::cout << "Value is " << something::value;

	//Util util;
	Util::doSomething();

	//util += 10;

	int intValue = (int)m;

	//Message newMessage = m + 23;

	Message newMessage;

	//std::cout << m << newMessage;
	std::cout << m;
	std::cout << newMessage;

	std::cout << std::endl << m;

	//std::cout << m << std::endl;

	int vb1 = 10;
	int vb2 = vb1++;	//vb1 = 11, vb2 = 10
	int vb3 = ++vb1;    //vb1 = 12, vb3 = 12


	Message anotherMessage = m++;
	newMessage = ++m;

}