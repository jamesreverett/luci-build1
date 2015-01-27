#include <stdio.h>
#include "input_reading.h"

InputReading::InputReading() {
    left_      = 0.0;
    right_     = 0.0;
    average_   = 0.0;
    evaluate();
}

float InputReading::average() {
    return average_;
}

void InputReading::evaluate() {
    if (left_ < 0.0 && right_ < 0.0) {
        average_ = -1;
    } else if (left_ < 0.0 || right_ < 0.0) {
        average_ = (right_ < 0.0) ? left_ : right_;
    } else {
        average_ = (right_ + left_) / 2;
    }
}
