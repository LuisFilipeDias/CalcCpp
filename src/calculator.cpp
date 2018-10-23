#include "calculator.h"

Calculator::Calculator(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    /* We will always need two numbers, so go ahead and reserve space for at least three - this optimization
     * allows us to avoid memory re-allocation in case the vector can't hold 2 elements in the first memory location.
     * There are probably exceptions when applying logical operators to inputs in programmer mode though..."*/
    numbers.reserve(2);
}

void Calculator::applyRegex(const std::string& re_str, const std::regex& re_pattern, std::vector<char> &regexVector)
{
    /* Apply regex to find the numbers. */
    std::smatch re_matches;

    std::string local_str = re_str;

    while(std::regex_search(local_str, re_matches, re_pattern))
    {
        Logger::log((std::string)re_matches[0], TRACE_DEBUG);

        char item;

#if 0 // not needed at this level)
        /* Jig to send the string number to an int. */
        std::stringstream ss(re_matches[0]);
        ss >> number;
#endif
        /* Append to vector. We are using emplace_back instead of push_back to avoid unnecessary copies, this way we don't
         * first create the variable in the stackframe, we create it directly in the vector allocated memory. Cool stuff. */
        if(item != 0)
            regexVector.emplace_back(item);

        /* Continue to process the string for more matches. */
        local_str = re_matches.suffix();
    }

    /* Iterate all numbers and print them out for user. */
    for(const char& c : regexVector)
    {
        Logger::log(c, TRACE_DEBUG);
    }
}

void Calculator::readOperation(void)
{
    Logger::log("Supported operations", TRACE_INFO);
    Logger::log(l_supported_ops, TRACE_INFO);
    Logger::log("Enter operation: ", TRACE_INFO);
    std::getline(std::cin, l_operation_str);

    /* Apply regex to find the numbers. */
    applyRegex(l_operation_str, (std::regex) "[[:digit:]]+", numbers);

    std::string ops_regex = (l_supported_ops.append("+"));

    applyRegex(l_operation_str, (std::regex) ops_regex, operators);
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

    Calculator();

    l_supported_ops = "[\+, \-, \*, \/, \%, \(, \), sqrt, square]";

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

    Calculator();

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

    Calculator();

    l_supported_ops = "(+, -, *, /, %, (, ), sqrt, square, mod, ones, twos, AND, NOT, OR, XOR, log, log2, int, frac).\nEnter operation:";

    setActiveMode(MODE_PROGRAMMER);
}

ProgrammerCalc::~ProgrammerCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}
