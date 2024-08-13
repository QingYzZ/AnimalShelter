#include "Animal.hpp"

class Dog : public Animal{
	public:
	string *bread;
	string *color;
	int bark() {
		cout << "Bark, bark, it's doggy..." << endl;
		return SUCCESS;
	}

	int makeNoise() {
		cout << "Bark, bark, it's doggy..." << endl; 
		return SUCCESS;
	}
};