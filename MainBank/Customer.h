#pragma once
#include <map>
#include <algorithm>
#include "Account.h"

#ifndef CUSTOMER_h
#define CUSTOMER_h

using namespace std;
static int ID = 1;


class Customer {
private:
	int custID;
	map <string, Account*> accountMap; //Accout Type name is used for mapping to child account object
	int arrivalTime, serviceTime, exitTime, timeLeft;
public:
	Customer();
	Customer(int aTime, int sTime);
	void displayAccounts();
	void addAccount(string, Account*);
	Account* getAccount(string accountType);
	void setarrivalTime(int aTime);
	int getarrivalTime();
	void decrementTimeLeft() { timeLeft--; }
	void setserviceTime(int sTime);
	int getserviceTime();
	int getTimeLeft() { return timeLeft; }
	void setexitTime(int eTime);
	int getexitTime();
	int getID() { return custID; }
};
#endif
