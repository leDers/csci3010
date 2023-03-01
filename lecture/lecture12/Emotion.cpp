#include <iostream>
#include <string>

#include "Emotion.h"

std::ostream& operator<<(std::ostream &os, const Emotion &d) {
    os << d.get_name();
    // TODO: print out more information if you want to
    return os;
}

int Emotion::counter_ = 0;

