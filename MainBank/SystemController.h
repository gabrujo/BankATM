#ifndef	SYSTEMCONTROLLER_h
#define SYSTEMCONTROLLER_h
#include "ATM.h"
#include "Timingwheel.h"

class SystemController {
private:
	vector<ATM> atms;
	Timingwheel timingWheel;
	double AvSerTime;
	double countTime;
	int servedCust;
	ATM* getShortestATM();
	void print_status();
public:
	SystemController(int atmNum =-1, int maxDelay=-1);
	Timingwheel getTimingWheel() { return timingWheel; }
	void startSim(int simTime, int dynCust, vector<Customer>& base);
	void startSim2(int simTime, int dynCust, vector<Customer>& base);
	int getServed() { return servedCust; }
};
#endif