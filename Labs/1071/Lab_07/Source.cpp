#include <iostream>
#include <string>
using namespace std;

enum class State {WAITING_PICKUP, IN_TRANSIT, DEPOSIT, DELIVERED};

class Util {
public:
	static char* copyArray(const char* source) {
		char* copy = new char[strlen(source) + 1];
		strcpy_s(copy, strlen(source) + 1, source);
		return copy;
	}

	static string stateToString(State state) {
		switch (state) {
		case State::WAITING_PICKUP:
			return "Waiting for pick up";
		case State::DEPOSIT:
			return "In desposit";
		case State::IN_TRANSIT:
			return "In transit";
		case State::DELIVERED:
			return "Delivered";
		default:
			throw exception("Type not covered");
		}

	}
};

class Box {
	char* AWB = nullptr;
	float weight = 0;
	State state = State::WAITING_PICKUP;
public:
	void setAWB(string awb) {
		delete[] this->AWB;
		this->AWB = Util::copyArray(awb.c_str());
	}
	string getAWB() {
		if (this->AWB != nullptr)
			return string(this->AWB);
		else return "";
	}
	void setState(State state) {
		this->state = state;
	}
	void pickUp() {
		this->state = State::IN_TRANSIT;
	}
	void store() {
		this->state = State::DEPOSIT;
	}
	State getState() {
		return this->state;
	}

	Box(string AWB, float weight) : weight(weight) {
		this->setAWB(AWB);
	}
	~Box() {
		cout << endl << "Destructor";
		delete[] this->AWB;
	}

	Box(const Box& box) : weight(box.weight){
		this->setAWB(string(box.AWB));
		this->setState(box.state);
	}

	void operator=(const Box& source) {

		if (&source == this) {
			return;
		}

		this->setAWB(string(source.AWB));
		this->weight = source.weight;
		this->setState(source.state);
	}

	void operator+=(int v) {
		this->weight += v;
	}
};

//void operator+=(Box b, int v) {
//	//b.weight += v;
//}

int main() {
	Box box("FAN012023", 5.6);
	cout << endl << "Box AWB: " << box.getAWB();
	cout << endl << "Box state: " << Util::stateToString(box.getState());

	//TESTING THE DESTRUCTOR
	{
		Box box2("FAN012023", 5.6);
	}

	Box* pBox = new Box("FAN012023", 5.6);
	delete pBox;

	//cout << endl << "Box AWB: " << box2.getAWB();

	Box box2("FAN022024", 5.6);

	box = box2;

	box += 2;	//add 2 kg to the box weight

	//box = box;

}
