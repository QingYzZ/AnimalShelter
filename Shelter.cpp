#include "Shelter.hpp"

Shelter::Shelter(string *name, int capacity) {
	shelterName = new (nothrow) string;
	if (!shelterName) {
		exit(1);
	}
	animalList = new (nothrow) Animal;
	if (!animalList) {
		exit(1);
	}
	capacity = capacity;
	numOfAnimals = 0;

}


string Shelter::getShelterName() {
	return *shelterName;
}

int Shelter::getCapacity() {
	return capacity;
}

int Shelter::rename(string &newName) {
	if (newName.empty()) {
		return FAILURE;
	}
	delete shelterName;
	shelterName = new (nothrow) string;
	if (!shelterName) {
		cout << "Failed due to dynamic memory allocation." << endl;
		return FAILURE;
	}
	shelterName = &newName;
	return SUCCESS;
}

int Shelter::addAnimal(Animal *newAnimal) {
	if (newAnimal == nullptr) {
		return FAILURE;
	}
	if (!animalList) {
		animalList = newAnimal;
	} else {
		Animal *prev = nullptr, *current = animalList;
		while (animalList && (newAnimal->getSpecies() != animalList->getSpecies())) {
			animalList = animalList->next;
		}

		prev->next = newAnimal;
		newAnimal->next = current;
		numOfAnimals++;
	}
	return SUCCESS;
}

int Shelter::emptyShelter() {
	Animal *current;
	while(animalList) {
		animalList = animalList->next;
		current = animalList;
		delete current;
	}

	return SUCCESS;
}

int Shelter::removeAnimal(string &name) {
	if (name.empty()) {
		return FAILURE;
	}

	if (ifExist(name) == FAILURE) {
		return FAILURE;
	} else {
		Animal *prev = nullptr, *current = animalList;
		while (current) {
			if (current->name == &name) {
				break;
			} else {
				prev = current;
				current = current->next;
			}
		}
		prev->next = current->next;
		delete current;
		return SUCCESS;
	}
}

int Shelter::ifExist(string &name) {
	if (name.empty()) {
		return FAILURE;
	}
	Animal *current = animalList;
	while (current) {
		if (current->name == &name) {
			return SUCCESS;
		}
	}
	return FAILURE;
}

int Shelter::printShelter() {
	Animal *current = animalList;;
	while(current) {
		current->makeNoise();
		current = current->next;
	}
	return SUCCESS;
}

int Shelter::destroyShelter() {
	emptyShelter();
	delete shelterName;
	delete this;
	return SUCCESS;
}