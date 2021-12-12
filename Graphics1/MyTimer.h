#pragma once
#include <chrono>
using namespace std::chrono;
class MyTimer
{
public:
	MyTimer();
	float Mark();
	float Peek()const;
private:
	steady_clock::time_point last;
};

