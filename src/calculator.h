#pragma once
#include "common.h"
#include "logger.h"
#include <regex>

class Calculator
{
private:
    std::string l_operation_str;
    t_Mode l_mode = MODE_NONE;

    void applyRegex(const std::string& re_str, const std::regex& pattern, std::vector<std::string>& regexVector);

    void processOperation(void);

protected:
    char l_op;
    std::string l_supported_ops;
    /* Must not forget that the vectors are created in the heap. This is kind of obvious because otherwise how could
     * we push back more elements without needing to allocate more memory in the stack? std::array is a bit different
     * though, as the size is statically defined at compile time, it can be stored in the stack. */
    std::vector<std::string> numbers, operators;

public:
    Calculator(void);

    /* Don't want to allow copy constructor for this class. */
    Calculator(const Calculator& other) = delete;

    void setActiveMode(const t_Mode& mode);

    t_Mode getActiveMode(void) const;

    virtual void readOperation(void);

    virtual ~Calculator(void);
};

class BasicCalc : public Calculator
{
public:
    explicit BasicCalc(void);

    /* Don't want to allow copy constructor for this class. */
    BasicCalc(const BasicCalc& other) = delete;

    ~BasicCalc(void);
};

class ScientificCalc : public BasicCalc
{
public:
    explicit ScientificCalc(void);

    /* Don't want to allow copy constructor for this class. */
    ScientificCalc(const ScientificCalc& other) = delete;

    ~ScientificCalc(void);
};

class ProgrammerCalc : public Calculator
{
public:
    explicit ProgrammerCalc(void);

    /* Don't want to allow copy constructor for this class. */
    ProgrammerCalc(const ProgrammerCalc& other) = delete;

    ~ProgrammerCalc(void);
};
