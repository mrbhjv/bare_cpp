
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
        if (something.find(",") != std::string::npos)
        {
            std::stoi(something.substr(0, something.find(",")));
            std::stoi(something.substr(something.find(",") + 1));
        }
        return std::stoi(something);
    }
} // namespace string_calculator

TEST(TestStringCalculator, Should_returnZeroWhenEmptyString)
{
    int result = string_calculator::add("");
    EXPECT_EQ(0, result);
}

class StringCalculatorSingleElementParameterizedTestFixture : public ::testing::TestWithParam<std::string>
{
};
TEST_P(StringCalculatorSingleElementParameterizedTestFixture, Should_returnElementWhenSingleNumberInString)
{
    std::string expected = GetParam();
    int result = string_calculator::add(expected);
    EXPECT_EQ(std::stoi(expected), result);
}

std::vector<std::string> get_single_number_strings_in_range(int beg, int end)
{
    std::vector<std::string> result;
    for (int i = beg; i <= end; i++)
    {
        result.push_back(std::to_string(i));
    }
    return result;
}

INSTANTIATE_TEST_SUITE_P(
    SingleNumberStringTests,
    StringCalculatorSingleElementParameterizedTestFixture,
    ::testing::ValuesIn(get_single_number_strings_in_range(1, 20)));

class StringCalculatorSingleElementWithCommaParameterizedTestFixture : public ::testing::TestWithParam<std::string>
{
};
TEST_P(StringCalculatorSingleElementWithCommaParameterizedTestFixture, Should_throwExceptionWhenStringWithCommaAndNotTwoElements)
{
    ASSERT_THROW(string_calculator::add(GetParam()), std::invalid_argument);
}

INSTANTIATE_TEST_SUITE_P(
    SingleNumberWithCommaTests,
    StringCalculatorSingleElementWithCommaParameterizedTestFixture,
    ::testing::Values(",", "1,", ",2"));
