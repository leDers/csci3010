#include <iostream>

#include "Animal.h"

// Name(s): Leif Anders

int main() {

  Reptile ralph("alligator");
  std::cout << ralph.MakeSound() << std::endl;

  // 1) Instantiate another animal
  Animal crow("caw");
  std::cout << crow.MakeSound() << std::endl;

  // 2) Call the Fight method of animal
  ralph.Race(crow);

  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal

  // 4) Instantiate at least one object of each class you defined for #3
  Mammal m;
  Turtle t;

  // 5) Have a tournament between the animals that you have instantiated
  std::cout << "Race 1" << std::endl;
  ralph.Race(m);
  std::cout << "Race 2" << std::endl;
  ralph.Race(t);
  std::cout << "Race 3" << std::endl;
  crow.Race(m);
  std::cout << "Race 4" << std::endl;
  crow.Race(t);

	return 0;
}
