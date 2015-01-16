#include <gtest/gtest.h>
#include <stdio.h>
#include "input_reading.h"

TEST(InputReading, JamieWasHere) {
  InputReading ir;

  EXPECT_EQ(0, ir.Print());
  EXPECT_NE(1, ir.Print());
}
