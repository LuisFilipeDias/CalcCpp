#pragma once
#include "common.h"
#include "logger.h"

struct Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

public:
    Timer();
    ~Timer();
};
