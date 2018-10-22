#pragma once
#include "common.h"

class Calculator
{
private:
    std::string l_mode_str;
    t_Mode l_mode = MODE_NONE;

protected:
    char l_op;
    int l_a, l_b;

public:
    Calculator(void);

    void setActiveMode(const t_Mode& mode);

    t_Mode getActiveMode(void) const;

    virtual void readMode(void);

    virtual ~Calculator(void);
};

class BasicCalc : public Calculator
{
public:
    explicit BasicCalc(void);

    void readMode(void);

    ~BasicCalc(void);
};

class ScientificCalc : public BasicCalc
{
public:
    explicit ScientificCalc(void);

    ~ScientificCalc(void);
};

class ProgrammerCalc : public Calculator
{
public:
    explicit ProgrammerCalc(void);

    ~ProgrammerCalc(void);
};
