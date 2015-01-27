#include <gtest/gtest.h>
#include <stdio.h>
#include "input_reading.h"

TEST(InputReading, DefaultAverageOpennessZero) {
    InputReading input;
    EXPECT_FLOAT_EQ(0.0, input.average());
}

