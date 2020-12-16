#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <list>
#include "BA_checking.h"
#ifndef FCABUSINESS_H_
#define FCABUSINESS_H_


using namespace std;

class FCABusiness : public BA_checking 
{
private:
	int numWithdrawalDone;
	int numWithdrawalAllowed;
	int numTransferDone;
	int numTransferAllowed;
	int numDepositDone;
	int numDepositAllowed;
	map<string, int> mapOfCurrency = {
			{"INR",74.33},
			{"AUD",1.40},
			{"CAD",1.32},
			{"EURO",0.85},
			{"JPY",104.32},
	};
public:
	FCABusiness(string companyName = "University of Bridgeport");
	bool Deposit(double checkAmount);
	bool Transfer(double amount, Account * receiverAccount);
	bool Withdraw(double amount);
	void ApplyInterest();
	void BalanceInquiry();
	void display();
};
#endif
