#include <gtest/gtest.h>
#include <stdio.h>
#include "input_reading.h"

TEST(dummyTest, AllwaysTrueTest) {
  EXPECT_EQ(1, 1);
}

TEST(InputReading, Print) {
  InputReading ir;

  EXPECT_EQ(0, ir.Print());
  EXPECT_EQ(1, ir.Print());
}
