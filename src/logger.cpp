#include <iostream>

#include "logger.h"

Logger::Logger()
{
    std::cout << "Logger" << std::endl;
}

Logger::~Logger()
{
    std::cout << "~Logger" << std::endl;
}

t_Error Logger::getMode(t_Mode& mode)
{
    t_Error err_code = ERR_NONE;
    char mode_chr;

    std::cout << "Select calculator:" << std::endl;
    std::cout << "1 - Basic" << std::endl;
    std::cout << "2 - Scientific" << std::endl;
    std::cout << "3 - Programmer" << std::endl;
    std::cout << "X - Exit" << std::endl;
    std::cin >> mode_chr;

    mode = (t_Mode) mode_chr;

    /* Eat away that '\n'. */
    char eatMe;
    std::cin.get(eatMe);

    if((MODE_BASIC > mode || MODE_PROGRAMMER < mode) && MODE_EXIT != mode && MODE_Exit != mode)
    {
        std::cout << "** Invalid mode. Try again..." << std::endl;
        err_code = ERR_INVALID_MODE;
    }
    else
    {
        err_code = ERR_NONE;
    }

    return err_code;
}
