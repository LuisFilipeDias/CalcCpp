#include <iostream>

#include "logger.h"

t_Error Logger::selectMode(t_Mode& mode) const
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    char mode_chr;

    /* Testing auto keyword - let compiler find out the type.
     * This is very usefull for client side avoing changes every time the API changes. */
    auto err_code = ERR_NONE;

    Logger::log<std::string>("Select calculator:", 	TRACE_INFO);
    Logger::log<std::string>("1 - Basic", 		TRACE_INFO);
    Logger::log<std::string>("2 - Scientific", 	TRACE_INFO);
    Logger::log<std::string>("3 - Programmer", 	TRACE_INFO);
    Logger::log<std::string>("X - Exit", 		TRACE_INFO);
    std::cin >> mode_chr;

    mode = (t_Mode) mode_chr;

    /* Eat away that '\n'. */
    char eatMe;
    std::cin.get(eatMe);

    if((MODE_BASIC > mode || MODE_PROGRAMMER < mode) && MODE_EXIT != mode && MODE_Exit != mode)
    {
        Logger::log<std::string>("** Invalid mode. Try again...", TRACE_ERROR);
        err_code = ERR_INVALID_MODE;
    }
    else
    {
        err_code = ERR_NONE;
    }

    return err_code;
}

Logger::~Logger()
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
}
