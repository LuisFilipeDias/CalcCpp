#include <iostream>

#include "logger.h"

void Logger::log(const std::string& txt, const t_Trace& trace)
{
    if( TRACE <= trace)
    {
        std::cout << txt << std::endl;
    }
}

t_Error Logger::selectMode(t_Mode& mode) const
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    char mode_chr;
    t_Error err_code = ERR_NONE;

    Logger::log("Select calculator:", 	TRACE_INFO);
    Logger::log("1 - Basic", 		TRACE_INFO);
    Logger::log("2 - Scientific", 	TRACE_INFO);
    Logger::log("3 - Programmer", 	TRACE_INFO);
    Logger::log("X - Exit", 		TRACE_INFO);
    std::cin >> mode_chr;

    mode = (t_Mode) mode_chr;

    /* Eat away that '\n'. */
    char eatMe;
    std::cin.get(eatMe);

    if((MODE_BASIC > mode || MODE_PROGRAMMER < mode) && MODE_EXIT != mode && MODE_Exit != mode)
    {
        Logger::log("** Invalid mode. Try again...", TRACE_ERROR);
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
    Logger::log(__FUNCTION__, TRACE_DEBUG);
}
