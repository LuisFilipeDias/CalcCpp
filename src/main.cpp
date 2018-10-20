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

Calculator* process(const t_Mode& mode)
{
    static Calculator* calc;
    if(MODE_BASIC == mode && (calc == nullptr || calc->getActiveMode() != MODE_BASIC))
    {
        delete calc;
        calc = new BasicCalc();
    }
    else if(MODE_SCIENTIFIC == mode && (calc == nullptr || calc->getActiveMode() != MODE_SCIENTIFIC))
    {
        delete calc;
        calc = new ScientificCalc();
    }
    else if(MODE_PROGRAMMER == mode && (calc == nullptr || calc->getActiveMode() != MODE_PROGRAMMER))
    {
        delete calc;
        calc = new ProgrammerCalc();
    }
    else if(MODE_EXIT == mode || MODE_Exit == mode)
    {
        std::cout << "Leaving..." << std::endl;
        delete calc;
        calc = nullptr;
    }
    else
    {
        calc = nullptr;
    }

    return calc;
}

void mainLoop(void)
{
    t_Mode mode = MODE_NONE;
    Logger* logger = new Logger();

    /* Probably there is a more elegant solution for case sensitive comparisons. */
    while(MODE_EXIT != mode && MODE_Exit != mode)
    {
        if(ERR_NONE == logger->getMode(mode))
        {
            Calculator* calc = process(mode);
            if(nullptr != (void*)calc)
            {
                calc->readMode();
            }
        }
    }
    delete logger;
}

int main(void)
{
    mainLoop();
}
