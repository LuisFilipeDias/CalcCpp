#include "common.h"
#include "calculator.h"
#include <gtest/gtest.h>
#include <memory>

struct CalculatorTester : testing::Test
{
    std::unique_ptr<Calculator> calcT;

    CalculatorTester(void);

    ~CalculatorTester(void);

    std::unique_ptr<Calculator>& getCalculator(void);
};

struct CalculatorState{
    int t_mode;
    std::string t_operation_str;
    bool t_mode_success;

    friend std::ostream& operator<<(std::ostream& os, const CalculatorState& obj)
    {
        return os << "\nt_mode: " << obj.t_mode
                  << "\nt_mode_success: " << obj.t_mode_success;
    }
};

struct CalculatorStateTest:CalculatorTester, testing::WithParamInterface<CalculatorState>
{
    CalculatorStateTest();

    ~CalculatorStateTest();
};
