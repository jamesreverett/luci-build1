#include <stdio.h>

#include "input_reading.h"

InputReading::InputReading() {
    left_openness_      = 0.0;
    right_openness_     = 0.0;
    average_openness_   = 0.0;
    perclos_            = 0;
    device_timestamp_   = 0;
    epoch_time_         = 0;
    EvaluateOpenness();
}

InputReading::InputReading(float left, float right, long timestamp) {
    left_openness_      = left;
    right_openness_     = right;
    average_openness_   = 0.0;
    perclos_            = 0;
    device_timestamp_   = timestamp;
    epoch_time_         = 0;
    EvaluateOpenness();
}

float InputReading::average_openness() {
    return average_openness_;
}

float InputReading::left_openness() {
    return left_openness_;
}
void InputReading::set_left_openness(float val) {
    left_openness_= val;
    EvaluateOpenness();
}

float InputReading::right_openness() {
    return right_openness_;
}
void InputReading::set_right_openness(float val) {
    right_openness_= val;
    EvaluateOpenness();
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



void InputReading::EvaluateOpenness() {
    if (left_openness_ < 0.0 && right_openness_ < 0.0) {
        average_openness_ = -1;
    } else if (left_openness_ < 0.0 || right_openness_ < 0.0) {
        average_openness_ = (right_openness_ < 0.0) ? left_openness_ : right_openness_;
    } else {
        average_openness_ = (right_openness_ + left_openness_) / 2;
    }

    if (average_openness_ < kEyeRatioBarrier) {
        // Openness is less a positive barrier - ie can be zero or negative
        perclos_ = 1;
    }
}

void InputReading::PrintJSON() const {
  printf("{left_ratio: %f, right_ratio: %f, used_ratio: %f, perclos_reading: %d, timestamp: %d, system_time: %d",
         left_openness_, right_openness_, average_openness_, perclos_, epoch_time_, device_timestamp_);
}
