#pragma once

#include "common.h"

class Logger{
public:
    static void log(const std::string& txt, const t_Trace& trace);

    Logger();

    t_Error getMode(t_Mode &mode);

    ~Logger();
};
