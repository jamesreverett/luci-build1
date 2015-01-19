#include <stdio.h>

#include "input_reading.h"

InputReading::InputReading() {
    left_openness_      = 0.0;
    right_openness_     = 0.0;
    average_openness_   = 0.0;
    device_timestamp_   = 0;
    epoch_time_         = 0;
}

InputReading::InputReading(float left, float right, long timestamp) {
    left_openness_      = left;
    right_openness_     = right;
    average_openness_   = 0.0;
    device_timestamp_   = timestamp;
    epoch_time_         = 0;
    UpdateAverageOpenness();
}

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

long InputReading::device_timestamp() {
    return device_timestamp_;
}
void InputReading::set_device_timestamp(long val) {
    device_timestamp_ = val;
}

long InputReading::epoch_time() {
    return epoch_time_;
}
void InputReading::set_epoch_time(long val) {
    epoch_time_ = val;
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
