#include <gtest/gtest.h>
#include <stdio.h>
#include "input_reading.h"

TEST(InputReading, PrintExpected) {
  InputReading ir;
  EXPECT_EQ(0, ir.Print());
}

TEST(InputReading, PrintNotExpected) {
  InputReading ir;
  EXPECT_NE(1, ir.Print());
}
