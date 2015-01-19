#include <gtest/gtest.h>
#include <stdio.h>
#include "input_reading.h"

TEST(InputReading, UpdateAverageOpenness) {
    InputReading input;
    EXPECT_EQ(0.0, input.average_openness());
}
