#include "calculator.h"

Calculator::Calculator(void)
{
    std::cout << "++ Calculator" << std::endl;
}

void Calculator::readMode(void)
{
    std::cout << "Insert mode: " << std::endl;
    std::getline(std::cin, l_mode_str);
    std::cout << l_mode_str << std::endl;
}

void Calculator::setActiveMode(const t_Mode& mode)
{
    l_mode = mode;
}

t_Mode Calculator::getActiveMode(void)
{
    return l_mode;
}

Calculator::~Calculator(void)
{
    std::cout << "-- ~Calculator" << std::endl;
}

BasicCalc::BasicCalc(void)
{
    std::cout << "++ BasicCalc" << std::endl;
    setActiveMode(MODE_BASIC);
}

void BasicCalc::readMode(void)
{
    Calculator::readMode();
}

BasicCalc::~BasicCalc(void)
{
    std::cout << "-- ~BasicCalc" << std::endl;
}

ScientificCalc::ScientificCalc(void)
{
    std::cout << "++ ScientificCalc" << std::endl;
    setActiveMode(MODE_SCIENTIFIC);
}

ScientificCalc::~ScientificCalc(void)
{
    std::cout << "-- ~ScientificCalc" << std::endl;
}

ProgrammerCalc::ProgrammerCalc(void)
{
    std::cout << "++ ProgrammerCalc" << std::endl;
    setActiveMode(MODE_PROGRAMMER);
}

ProgrammerCalc::~ProgrammerCalc(void)
{
    std::cout << "-- ~ProgrammerCalc" << std::endl;
}
