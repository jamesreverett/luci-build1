#include <stdio.h>

#include "input_reading.h"

float InputReading::average_openness() {
    return average_openness_;
}

float InputReading::left_openness() {
    return left_openness_;
}
void InputReading::set_left_openness(float val) {
    left_openness_= val;
    UpdateAverageOpenness();
}

float InputReading::right_openness() {
    return right_openness_;
}
void InputReading::set_right_openness(float val) {
    right_openness_= val;
    UpdateAverageOpenness();
}

long InputReading::epoch_time() {
    return epoch_time_;
}
void InputReading::set_epoch_time(long val) {
    epoch_time = val;
}

long InputReading::system_time() {
    return system_time_;
}
void InputReading::set_system_time(long val) {
    system_time_ = val;
}


void InputReading::UpdateAverageOpenness() {
    float average_eye_ratio = 0.0;

    if (left_openness_ < 0.0 && right_openness_ < 0.0) {
        average_eye_ratio = -1;
    } else if (left_openness_ < 0.0 || right_openness_ < 0.0) {
        average_eye_ratio = (right_openness_ < 0.0) ? left_openness_ : right_openness_;
    } else {
        average_eye_ratio = (right_openness_ + left_openness_) / 2;
    }

    average_openness_ = average_eye_ratio;
}

void InputReading::Print() const {
  printf("[Left: %f][Right: %f]", left_openness_, right_openness_);
}
