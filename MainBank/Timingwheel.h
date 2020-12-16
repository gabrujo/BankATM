#ifndef TIMINGWHEEL_h
#define TIMINGWHEEL_h
#include "Partition.h"

using namespace std;
class Timingwheel
{
private:
	int size; //total number of slots in the Timingwheel
	Partition* slots; //dynamic array
	int current_slot;
	float waitCount, servTimeCount;
	float averageWaitingTime, averageServiceTime;
	int custCount;
public:
	Timingwheel(int maxDelay = 1);
	//~Timingwheel() { delete[] slots; }
	//Timingwheel(const Timingwheel& copy);
	//Timingwheel& operator=(const Timingwheel& p);
	float getAvgWaitTime() { return averageWaitingTime; }
	float getAvgServTime() { return averageServiceTime; }
	int getCustCount() { return custCount; }
	void insert(ATM* p1);
	void schedule(int simulationTime);
	void clear_current_slot(); //clears partition pointer and sets to null
	void incrementCurrent() { current_slot = (current_slot + 1) % size; }
	friend ostream& operator<<(ostream&, Timingwheel&);
};

#endif
