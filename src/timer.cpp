#include "timer.h"

Timer::Timer()
{
    start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    end = std::chrono::high_resolution_clock::now();

    duration = end - start;

    Logger::log((float)(duration.count()/1000.0f));
}
