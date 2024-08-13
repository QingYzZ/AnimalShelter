#include "Animal.hpp"

class Cat : public Animal {
	public:
	string *bread;
	string *color;

	int meow(){
		cout << "Meow, meow, it's kitty..." << endl;
		return SUCCESS;
	}

	int makeNoise() {
		cout << "Meow, meow, it's kitty..." << endl; 
		return SUCCESS;
	}
};