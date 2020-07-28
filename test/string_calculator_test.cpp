
#include "gtest/gtest.h"

#include <string>

namespace string_calculator
{
    inline int add(std::string something)
    {
        if (something.empty())
        {
            return 0;
        }
        return std::stoi(something);
    }
} // namespace string_calculator

TEST(TestStringCalculator, Should_returnZeroWhenEmptyString)
{
    int result = string_calculator::add("");
    EXPECT_EQ(0, result);
}

TEST(TestStringCalculator, Should_returnOneWhenSingleNumberIsOne)
{
    int result = string_calculator::add("1");
    EXPECT_EQ(1, result);
}