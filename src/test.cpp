#include "test.h"

TEST_F(CalculatorTester, SmokeTest)
{
    EXPECT_EQ(MODE_NONE, getCalculator()->getActiveMode());
}

TEST_P(CalculatorStateTest, ParamsTest)
{
    auto as = GetParam();
    auto success = (calcT->getActiveMode() == as.t_mode);
    EXPECT_EQ(as.t_mode_success, success);
}

INSTANTIATE_TEST_CASE_P(Default, CalculatorStateTest, testing::Values(
                            CalculatorState{MODE_PROGRAMMER, "text", true},
                            CalculatorState{MODE_NONE, "", true},
                            CalculatorState{MODE_SCIENTIFIC, "", true}));

CalculatorTester::CalculatorTester(void)
{
    calcT = std::make_unique<Calculator>();
}

CalculatorTester::~CalculatorTester(void)
{
}

CalculatorStateTest::CalculatorStateTest(void)
{
}

CalculatorStateTest::~CalculatorStateTest(void)
{
}

std::unique_ptr<Calculator>& CalculatorTester::getCalculator(void)
{
    return calcT;
}
