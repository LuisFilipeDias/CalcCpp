/*
 * ToDo:
 * - Add logging system;
 * - Implement base calculator;
 * - Implement scientific calculator;
 * - Implement programmer calculator;
 * - Create a printer/logger class;
*/

#include "logger.h"
#include "common.h"
#include "calculator.h"
#include "test.h"

static std::shared_ptr<Calculator> process(const t_Mode& mode)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

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
        Logger::log<std::string>("Leaving...", TRACE_INFO);
        calc = nullptr;
    }

    return calc;
}

static void mainLoop(void)
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

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
                calc->readOperation();
            }
        }
        else
        {
            Logger::log<std::string>("Failed to process mode. Leaving...", TRACE_FATAL);
            return;
        }
    }
}

int main(int argc, char* argv[])
{
    Logger::log<std::string>(__FUNCTION__, TRACE_DEBUG);

    testing::InitGoogleTest(&argc, argv);
    std::cout << RUN_ALL_TESTS() << std::endl;

    /* Scoped pointer example. */
    ScopedHelloWorld scoped_hw = new HelloWorld();

    scoped_hw->printHello()
              .printHello()
              .printHello();

    mainLoop();

    /* could use auto instead. */
    void(*byeMessage)(int) = HelloWorld::printBye;

    byeMessage(0);
}
