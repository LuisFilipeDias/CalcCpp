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


class HelloWorld{
public:
    HelloWorld()
    {
        Logger::log(__FUNCTION__, TRACE_DEBUG);
    }
};

class ScopedHelloWorld{
private:
    HelloWorld* l_hw;
public:
    ScopedHelloWorld(HelloWorld* hw): l_hw(hw)
    {
        Logger::log(__FUNCTION__, TRACE_DEBUG);
    }

    ~ScopedHelloWorld()
    {
        Logger::log(__FUNCTION__, TRACE_DEBUG);
        delete l_hw;
    }
};
