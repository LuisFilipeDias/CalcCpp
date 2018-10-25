#include "calculator.h"

/* To be able to use 1s on thread sleep. */
using namespace std::literals::chrono_literals;

bool Calculator::calcDone = false;

Calculator::Calculator(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    /* We will always need two numbers, so go ahead and reserve space for at least three - this optimization
     * allows us to avoid memory re-allocation in case the vector can't hold 2 elements in the first memory location.
     * There are probably exceptions when applying logical operators to inputs in programmer mode though..."*/
    numbers.reserve(2);
}

void Calculator::applyRegex(const std::string& re_str, const std::regex& re_pattern, std::vector<std::string> &regexVector)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    regexVector.clear();

    /* Apply regex to find the numbers. */
    std::smatch re_matches;

    std::string local_str = re_str;

    while(std::regex_search(local_str, re_matches, re_pattern))
    {
        std::string item = re_matches[0];

        /* Append to vector. We are using emplace_back instead of push_back to avoid unnecessary copies, this way we don't
         * first create the variable in the stackframe, we create it directly in the vector allocated memory. Cool stuff. */
        regexVector.emplace_back(item);

        /* Continue to process the string for more matches. */
        local_str = re_matches.suffix();
    }

#if 0
    /* Iterate all numbers and print them out for user. */
    for(const std::string& c : regexVector)
    {
        Logger::log(c, TRACE_DEBUG);
    }
#endif

}

void Calculator::readOperation(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    Logger::log<std::string>("Supported operations", TRACE_INFO);
    Logger::log(l_supported_ops, TRACE_INFO);
    Logger::log<std::string>("Enter operation: ", TRACE_INFO);
    std::getline(std::cin, l_operation_str);

    /* Apply regex to find the numbers. */
    applyRegex(l_operation_str, (std::regex) "[[:digit:]]+", numbers);

    std::string ops_regex = (l_supported_ops.append("+"));
    applyRegex(l_operation_str, (std::regex) ops_regex, operators);

    processOperation();
}

/* NOTE: At the moment this calculator does not take into account precedence. */
void Calculator::processOperation(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    int result;

    Calculator::calcDone = false;

    std::thread t_calculation(calculationThread, std::ref(numbers), std::ref(operators), std::ref(result));

    Logger::log<std::string>("Calculating");

    while(!Calculator::calcDone)
    {
        std::this_thread::sleep_for(100ms);
        std::cout << "." << std::endl;
    }

    t_calculation.join();

    Logger::log<std::string>("** Result is: ");
    Logger::log<int>(result);
}

void Calculator::calculationThread(const std::vector<std::string>& numbers, const std::vector<std::string>& operators, int& result)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    Timer t;
    int a;

    std::stringstream ss1(numbers[0]);
    ss1 >> a;

    for(unsigned int i = 0; i < operators.size(); i++)
    {
        int b;
        std::stringstream ss2(numbers[i+1]);
        ss2 >> b;

        char op;
        std::stringstream ss3(operators[i]);
        ss3 >> op;

        // Call another thread to do the calculus, and join them further ahead.
        switch(op)
        {
        case '+':
            a = a + b;
            break;
        case '-':
            a = a - b;
            break;
        case '*':
            a = a * b;
            break;
        case '/':
            a = a / b;
            break;
        case '%':
            break;
        case '(':
            break;
        case ')':
            break;
        case 's':
            break;
        case 'S':
            break;
        }
    }

    result = a;

    /* We don't want it to be to fast otherwise we won't see those nice dots...*/
    std::this_thread::sleep_for(1s);

    Calculator::calcDone = true;
}

void Calculator::setActiveMode(const t_Mode& mode)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    l_mode = mode;
}

t_Mode Calculator::getActiveMode(void) const
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    return l_mode;
}

Calculator::~Calculator(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
}

BasicCalc::BasicCalc(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    Calculator();

    l_supported_ops = "[+, -, *, /, %, (, ), s, S]";

    setActiveMode(MODE_BASIC);
}

BasicCalc::~BasicCalc(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
}

ScientificCalc::ScientificCalc(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    Calculator();

    l_supported_ops = "[+, -, *, /, %, (, ), sqrt, square, cos, sin, tan, cosh, sinh, tanh, log, ln, Mod, Arg, Re, Im]";

    setActiveMode(MODE_SCIENTIFIC);
}

ScientificCalc::~ScientificCalc(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
}

ProgrammerCalc::ProgrammerCalc(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    Calculator();

    l_supported_ops = "[+, -, *, /, %, (, ), sqrt, square, mod, ones, twos, AND, NOT, OR, XOR, log, log2, int, frac]";

    setActiveMode(MODE_PROGRAMMER);
}

ProgrammerCalc::~ProgrammerCalc(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
}
