#include "calculator.h"
#include "logger.h"

Calculator::Calculator(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}

void Calculator::readMode(void)
{

    Logger::log("Insert mode: ", TRACE_INFO);
    std::getline(std::cin, l_mode_str);
    std::cout << l_mode_str << std::endl;
}

void Calculator::setActiveMode(const t_Mode& mode)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    l_mode = mode;
}

t_Mode Calculator::getActiveMode(void)
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

    setActiveMode(MODE_BASIC);
}

void BasicCalc::readMode(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    Calculator::readMode();
}

BasicCalc::~BasicCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}

ScientificCalc::ScientificCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
    setActiveMode(MODE_SCIENTIFIC);
}

ScientificCalc::~ScientificCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}

ProgrammerCalc::ProgrammerCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
    setActiveMode(MODE_PROGRAMMER);
}

ProgrammerCalc::~ProgrammerCalc(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}
