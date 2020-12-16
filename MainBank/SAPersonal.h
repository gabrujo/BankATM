#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "PersonalAccount.h"
#ifndef SAPERSONAL_H_
#define SAPERSONAL_H_
using namespace std;

class SAPersonal: public PersonalAccount
{
private:
	double frozenamount;
	double depositInterest;
public:
	SAPersonal();
	SAPersonal(string fn, string ln);
	bool Deposit(double checkAmount);
	bool Transfer(double amount, Account * receiverAccount);
	bool Withdraw(double amount);
	void ApplyInterest();
	void activateFrozen();
	void display();
};
#endif

