#include "timer.h"

Timer::Timer() : start(std::chrono::steady_clock::now()) {}

void Timer::reset()
{
	start = std::chrono::steady_clock::now();
}

double Timer::elapsed() const
{
	const auto now = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(now - start).count() / 1000000000.0;
}