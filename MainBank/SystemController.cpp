#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
#include <random>
#include "SystemController.h"

using namespace std;

SystemController::SystemController(int atmNum, int maxDelay): timingWheel(Timingwheel(maxDelay))
{
	for (int i = 1; i <= atmNum; i++) {
		ATM temp(i);
		atms.push_back(temp);
	}
	AvSerTime=0;
	countTime=0;
	servedCust=0;
}

ATM* SystemController::getShortestATM()
{
	ATM* withShotestQueue = &atms.at(0);
	int currATMCustNum;
	int numOfCustInQueue = withShotestQueue->getCustNum();
	for (auto it = atms.begin() + 1; it !=atms.end(); ++it) 
	{
		currATMCustNum = it->getCustNum();
		if (currATMCustNum < numOfCustInQueue) {
			withShotestQueue = &(*it);
			numOfCustInQueue = currATMCustNum;
		}
	}
	return withShotestQueue;

}

void SystemController::print_status()
{
	/*Prints the status of the system to the screen 
	at each simulated instance.*/
	cout << timingWheel;
}

void SystemController::startSim(int simTime, int dynCust, vector<Customer>& base)
{
	/*Runs the whole simulation for given simTime*/
	int count = 0;
	Customer cust;
	int servTime;
	for (auto& atm : atms) {
		cust = base[count++];
		atm.addCust(cust);
		timingWheel.insert(&atm);
	}
	cout << endl << "************ T = 0 ************" << endl << timingWheel << endl;
	timingWheel.incrementCurrent();
	int newCust;
	ATM* ptShortestATM;
	bool ifPutWheel;
	cout << endl<< "Starting simulation..." << endl;
	for (int i = 1; i <= simTime; i++) {
		cout <<endl << "************ T = " << i <<" ************"<<endl;
		//Adds new customers
		if (count < base.size()) {
			newCust = rand() % (dynCust + 1);
			for (int j = 0; j < newCust; j++) {
				ptShortestATM = getShortestATM();
				cust = base[count++];
				cout << "Customer #" << cust.getID() << " arrived and got into queue for ATM #" << ptShortestATM->getNum() << endl;
				cust.setarrivalTime(i);
				ifPutWheel = ptShortestATM->addCust(cust);
				if (ifPutWheel) {
					timingWheel.insert(ptShortestATM);
				}
			}
		}
		timingWheel.schedule(i);
		timingWheel.clear_current_slot();
		print_status(); 
		timingWheel.incrementCurrent();
	}
}
