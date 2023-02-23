#include <iostream>
#include "Earth.h"

// Names:
//  Leif Anders

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp

    // 1) Get an instance of your earth object
    Earth &e = Earth::GetInstance();

    // 2) Get another instance of your earth object
    Earth &f = Earth::GetInstance();

    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.
    std::cout << &e << std::endl;
    std::cout << &f << std::endl;

    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?
    e.IncreasePopulation();

    std::cout << e.get_population() << std::endl;
    std::cout << f.get_population() << std::endl;

    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?

    std::cout << e.x_ << std::endl;
    // yes you need an instance to access this field

    std::cout << (e == f) << std::endl;

	return 0;
}
