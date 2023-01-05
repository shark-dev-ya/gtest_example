#include <awesomeLib/awesomeHeader.h>
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(TestMagicFunctions, TestForRandomNumber) {
  // Expect equality.
  EXPECT_EQ(getRandomNumber(), 42);
}

// Demonstrate some basic assertions.
TEST(TestMagicFunctions, testValue10IncreasedBy5) {
  uint16_t initialValue = 10;
  uint16_t byValue = 5;
  const uint16_t expectedValue = initialValue + byValue;
  // Expect equality.
  EXPECT_EQ(increaseValueBy(initialValue , byValue ), expectedValue);
}

// Demonstrate some basic assertions.
TEST(TestMagicFunctions, testValue10DecreasedBy5) {
  uint16_t initialValue = 10;
  uint16_t byValue = 5;
  const uint16_t expectedValue = initialValue - byValue;
  // Expect equality.
  EXPECT_EQ(decreaseValueBy(initialValue , byValue ), expectedValue);
}
