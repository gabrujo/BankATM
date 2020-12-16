#ifndef STATISTICS_H
#define STATISTICS_H

#include "SystemController.h"
#include "Timingwheel.h"

class StatisticsKeeper {
private:
	int durationOfSimulation, NoATMS, NoCostumers;
public:
	StatisticsKeeper();
	void report(Timingwheel obj, int dur, int atmNum);
};

#endif