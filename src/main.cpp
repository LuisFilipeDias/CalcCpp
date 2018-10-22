/*
 * ToDo:
 * - Add logging system;
 * - Implement base calculator;
 * - Implement scientific calculator;
 * - Implement programmer calculator;
 * - Create a printer/logger class;
*/

#include "logger.h"
#include "calculator.h"
#include <memory>

static std::shared_ptr<Calculator> process(const t_Mode& mode)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    static std::shared_ptr<Calculator> calc;
    if(MODE_BASIC == mode && (calc == nullptr || calc->getActiveMode() != MODE_BASIC))
    {
        calc = std::make_shared<BasicCalc>();
    }
    else if(MODE_SCIENTIFIC == mode && (calc == nullptr || calc->getActiveMode() != MODE_SCIENTIFIC))
    {
        calc = std::make_shared<ScientificCalc>();
    }
    else if(MODE_PROGRAMMER == mode && (calc == nullptr || calc->getActiveMode() != MODE_PROGRAMMER))
    {
        calc = std::make_shared<ProgrammerCalc>();
    }
    else if(MODE_EXIT == mode || MODE_Exit == mode)
    {
        Logger::log("Leaving...", TRACE_INFO);
        calc = nullptr;
    }
    else
    {
        calc = nullptr;
    }

    return calc;
}

static void mainLoop(void)
{
    Logger::log(__FUNCTION__, TRACE_DEBUG);

    t_Mode mode = MODE_NONE;

    /* Implicit conversion - sounds nice... */
    Logger logger = TRACE;

    /* Probably there is a more elegant solution for case sensitive comparisons. */
    while(MODE_EXIT != mode && MODE_Exit != mode)
    {
        if(ERR_NONE == logger.selectMode(mode))
        {
            std::shared_ptr<Calculator> calc = process(mode);
            if(nullptr != calc)
            {
                calc->readMode();
            }
        }
        else
        {
            Logger::log("Failed to process mode. Leaving...", TRACE_FATAL);
            return;
        }
    }
}

int main(void)
{
    /* Scoped pointer example. */
    ScopedHelloWorld scoped_hw = new HelloWorld();

    Logger::log(__FUNCTION__, TRACE_DEBUG);

    mainLoop();
}
