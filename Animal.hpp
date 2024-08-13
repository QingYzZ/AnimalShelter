#include <iostream>
#include <string>

#include "Macros.hpp"

using namespace std;

class Animal {
	public:
	string *name;
	string *species;
	double age;
	double weight;
	Animal *next;

	int makeNoise() { 
		cout << "It's some kind of animal..." << endl; 
		return SUCCESS;
	}

	string getSpecies() {
		return *species;
	}
};