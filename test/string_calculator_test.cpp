#include "gtest/gtest.h"

TEST(TestStringCalculator, Should_Fail)
{
    EXPECT_EQ(1, 0) << "I'm just failing";
}