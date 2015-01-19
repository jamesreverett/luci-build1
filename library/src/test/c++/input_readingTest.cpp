#include <gtest/gtest.h>
#include <stdio.h>
#include "input_reading.h"

// https://code.google.com/p/googletest/wiki/AdvancedGuide#Floating-Point_Comparison

TEST(InputReading, DefaultAverageOpennessZero) {
    InputReading input;
    EXPECT_FLOAT_EQ(0.0, input.average_openness());
}

TEST(InputReading, AllNegativeAverageOpenness) {
    InputReading input(-1.2, -1.3, 12345);
    EXPECT_FLOAT_EQ(-1, input.average_openness());
}

TEST(InputReading, NegativeLeftAverageOpenness) {
    InputReading input(-1.7, 2, 12345);
    EXPECT_FLOAT_EQ(2, input.average_openness());
}

TEST(InputReading, NegativeRightAverageOpenness) {
    InputReading input(3.4, -1.4, 12345);
    EXPECT_FLOAT_EQ(3.4, input.average_openness());
}

TEST(InputReading, PositiveAverageOpenness) {
    InputReading input(10, 20, 12345);
    EXPECT_FLOAT_EQ(15, input.average_openness());
}
