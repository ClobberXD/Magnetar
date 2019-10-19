#pragma once

#include <functional>
#include <chrono>

class Profiler
{
public:
	void startTimer();
	double stopTimer();

protected:
	using _time = std::chrono::time_point<std::chrono::high_resolution_clock>;

private:
	_time startTime;
};

class ScopeProfiler : public Profiler
{
public:
	ScopeProfiler(const std::function<void (double)> &fn);
	~ScopeProfiler();

private:

	std::function<void (double)> _fn;
};
