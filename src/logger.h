#pragma once

#include "common.h"

class Logger{
private:
    t_Trace l_trace = TRACE_ERROR;

public:
    static void log(const std::string& txt, const t_Trace& trace);

    // Not Explicit, this means we can do this: Logger L = TRACE_DEBUG;
    Logger(const t_Trace& trace) : l_trace(trace){}

    /* Const because this method doesn't change this class. */
    t_Error selectMode(t_Mode &mode) const;

    ~Logger();
};
