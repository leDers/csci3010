#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Name(s):
//

class Animal {
public:
	Animal(std::string sound):
	sound_(sound)
	{}

	std::string MakeSound() const {return sound_; }

	void Race(Animal &opponent);

	virtual int GetSpeed() { return 0; };

private:
	std::string sound_;
};

class Reptile : public Animal {
public:
	Reptile(std::string sound):
	Animal(sound + " rawr!")
	{}

	int GetSpeed() { return 2; };

};

// Define your animals here.
// Define one class that inherits from Animal and
// one class that inherits from a child class of Animal

class Mammal: public Animal{
	public:
		Mammal():
		Animal("fuzzy fuzz") {}
		int GetSpeed() {return 3;}
};

class Turtle: public Reptile{
	public:
		Turtle(): Reptile("turtle turtle") {}
		int GetSpeed() {return 1;}
};

#endif  // ANIMAL_H
