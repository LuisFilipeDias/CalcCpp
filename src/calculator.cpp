#include "calculator.h"

Calculator::Calculator(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}

void Calculator::readOperation(void)
{
    std::vector<int> numbers, operations;

    std::stringstream ss;

    Logger::log("Supported operations", TRACE_INFO);
    Logger::log(l_supported_ops, TRACE_INFO);
    std::getline(std::cin, l_operation_str);

    std::smatch re_matches;
    std::regex re_pattern ("[[:digit:]]+");
    std::string re_str = l_operation_str;

    /* Apply regex to find the numbers. */
    while(std::regex_search(re_str,re_matches,re_pattern))
    {
        /* Jig to send the string number to an int. */
        int number;
        std::stringstream ss(re_matches[0]);
        ss >> number;

        /* Append to vector. */
        numbers.push_back(number);

        /* Continue to process the string for more matches. */
        re_str = re_matches.suffix();
    }

    /* Iterate all numbers and print them out for user. */
    for(const int& n : numbers)
    {
        std::cout << n << std::endl;
    }

    /* Apply regex to find the operators. */
}

void Calculator::setActiveMode(const t_Mode& mode)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    l_mode = mode;
}

t_Mode Calculator::getActiveMode(void) const
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    return l_mode;
}

Calculator::~Calculator(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}

BasicCalc::BasicCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    l_supported_ops = "(+, -, *, /, %, (, ), sqrt, square).\nEnter operation:";

    setActiveMode(MODE_BASIC);
}

void BasicCalc::readOperation(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    Calculator::readOperation();
}

BasicCalc::~BasicCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}

ScientificCalc::ScientificCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    l_supported_ops = "(+, -, *, /, %, (, ), sqrt, square, cos, sin, tan, cosh, sinh, tanh, log, ln, Mod, Arg, Re, Im).\nEnter operation:";

    setActiveMode(MODE_SCIENTIFIC);
}

ScientificCalc::~ScientificCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}

ProgrammerCalc::ProgrammerCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    l_supported_ops = "(+, -, *, /, %, (, ), sqrt, square, mod, ones, twos, AND, NOT, OR, XOR, log, log2, int, frac).\nEnter operation:";

    setActiveMode(MODE_PROGRAMMER);
}

ProgrammerCalc::~ProgrammerCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}
