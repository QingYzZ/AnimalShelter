#ifndef SHELTER_HPP
#define SHELTER_HPP

#include <iostream>
#include <string>
#include "Macros.hpp"
#include "Animal.hpp"

using namespace std;

class Shelter {
	public:
	Shelter(string *name, int capacity);
	string getShelterName();
	int getCapacity();
	int rename(string &newName);
	int addAnimal(Animal *newAnimal);
	int emptyShelter();
	int ifExist(string &name);
	int removeAnimal(string &name);
	int printShelter();
	int destroyShelter();

	
	private:
	string *shelterName;
	int capacity;
	int numOfAnimals;
	Animal *animalList;

};

#endif
