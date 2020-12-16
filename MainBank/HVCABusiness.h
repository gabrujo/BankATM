#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "BA_checking.h"
using namespace std;

class HVCABusiness : public BA_checking 
{
private:
	double transacationFee;
public:
	HVCABusiness(string companyName="University of Bridgeport");
	bool Deposit(double checkAmount);
	double ComputeTrasactionFee(double checkAmount);
	bool Withdraw(double amount);
	bool Transfer(double amount, Account * receiverAccount);
	void ApplyInterest();
	void display();
};
