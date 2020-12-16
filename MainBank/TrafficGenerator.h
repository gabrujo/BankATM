#ifndef TRAFFICGENERATOR_h
#define TRAFFICGENERATOR_h

#include <map> 
#include <queue> 
#include <vector>
#include <iostream>
#include <string>

#include "Customer.h"


using namespace std;

class TrafficGenerator {
private:
	int customerBase;
	int initCustomersNum;
	int countTime;
	int dynCustomersNum;
	tuple<int, int> serviceTimeRange;
	int multAccountPercentile;
	int persAccountPercentile;//business account rate = 100 - perAccountRate
	double AvSerTime;
	map <int, string> pertypesToPercentile;
	map <int, string> bustypesToPercentile;
	//map <int, string> transactionsToPercentile;
	void parseFile(string file);
	Customer generateCust();
public:
	TrafficGenerator(string filename = "traffic.txt");
	void displayInfo();
	queue<Customer>& getInitTraffic();
	vector<Customer> initCustomerBase();
	int getDynCust() { return dynCustomersNum; }
	int maxServiceTime() { return get<1>(serviceTimeRange); }
};
#endif
