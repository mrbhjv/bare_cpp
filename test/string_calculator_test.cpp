
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

class StringCalculatorParameterizedTestFixture : public ::testing::TestWithParam<std::string> {};
TEST_P(StringCalculatorParameterizedTestFixture, Should_returnElementWhenSingleNumberInString)
{
    std::string expected = GetParam();
    int result = string_calculator::add(expected);
    EXPECT_EQ(std::stoi(expected), result);
}

std::vector<std::string> get_single_number_strings_in_range(int beg, int end){
    std::vector<std::string> result;
    for(int i = beg; i <= end; i++)
    {
        result.push_back(std::to_string(i));
    }
    return result;
}

INSTANTIATE_TEST_SUITE_P(
    SingleNumberStringTests,
    StringCalculatorParameterizedTestFixture,
    ::testing::ValuesIn(get_single_number_strings_in_range(1,20))
);