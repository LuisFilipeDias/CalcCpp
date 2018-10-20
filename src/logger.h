#pragma once

#include "common.h"

class Logger{
public:
    Logger();

    t_Error getMode(t_Mode &mode);

    ~Logger();
};
