#pragma once
#include "common.h"
#include "logger.h"
#include <regex>

class Calculator
{
private:
    std::string l_operation_str;
    t_Mode l_mode = MODE_NONE;

    void applyRegex(const std::string& re_str, const std::regex& pattern, std::vector<char>& regexVector);

protected:
    char l_op;
    int l_a, l_b;
    std::string l_supported_ops;
    std::vector<char> numbers, operators;

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

    void readOperation(void);

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
