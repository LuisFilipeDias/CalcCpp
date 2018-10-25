#pragma once

#include "common.h"

class Logger{
private:
    t_Trace l_trace = TRACE_ERROR;

public:
    template<typename t>
    static void log(const t& txt, const t_Trace& trace)
    {
        if( TRACE <= trace)
            std::cout << txt << std::endl;
    }

    template<typename t>
    static void log(const t& txt)
    {
        Logger::log<t>(txt, TRACE_INFO);
    }

    // Not Explicit, this means we can do this: Logger L = TRACE_DEBUG;
    Logger(const t_Trace& trace) : l_trace(trace){}

    /* For some reason cannot delete the copy constructor because now explicit conversion does not work...*/
# if 0
    /* Don't want to allow copy constructor for this class. */
    Logger(const Logger& other) = delete;
#endif

    /* Const because this method doesn't change this class. */
    t_Error selectMode(t_Mode &mode) const;

    ~Logger();
};


class HelloWorld{
public:
    HelloWorld()
    {
        Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
    }

    void printHello() const
    {
        Logger::log<std::string>("Hello World!");
    }

    static void printBye(int foo)
    {
        Logger::log<std::string>("Bye World...");
    }
};

class ScopedHelloWorld{
private:
    HelloWorld* l_hw;
public:
    ScopedHelloWorld(HelloWorld* hw): l_hw(hw)
    {
        Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
    }

    /* Overloading the arrow operator to be able to dereference the internal HelloWorld object. */
    const HelloWorld* operator->() const
    {
        return l_hw;
    }

    ~ScopedHelloWorld()
    {
        Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);
        delete l_hw;
    }
};
