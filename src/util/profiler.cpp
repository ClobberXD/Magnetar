#include "profiler.h"

#include <iostream>

using namespace std::chrono;

/*
 * Profiler
 */

void Profiler::startTimer()
{
	startTime = high_resolution_clock::now();
}

double Profiler::stopTimer()
{
	return duration_cast<microseconds>(high_resolution_clock::now() - startTime).count();
}

/*
 * ScopeProfiler
 */

ScopeProfiler::ScopeProfiler(const std::function<void (double)> &fn)
	: _fn(fn)
{
	startTimer();
}

ScopeProfiler::~ScopeProfiler()
{
	_fn(stopTimer());
}
