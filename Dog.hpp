#include "Animal.hpp"

class Dog : public Animal{
	public:
	string *bread;
	string *color;
	int woof() {
		cout << "Woof, woof, it's doggy..." << endl;
		return SUCCESS;
	}

	int makeNoise() {
		cout << "Woof, woof, it's doggy..." << endl; 
		return SUCCESS;
	}
};