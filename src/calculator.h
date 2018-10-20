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

    t_Mode getActiveMode(void);

    virtual void readMode(void);

    virtual ~Calculator(void);
};

class BasicCalc : public Calculator
{
public:
    BasicCalc(void);

    void readMode(void);

    ~BasicCalc(void);
};

class ScientificCalc : public BasicCalc
{
public:
    ScientificCalc(void);

    ~ScientificCalc(void);
};

class ProgrammerCalc : public Calculator
{
public:
    ProgrammerCalc(void);

    ~ProgrammerCalc(void);
};
