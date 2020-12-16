#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "Account.h"
#include "PersonalAccount.h"
#ifndef PERSONALMONEYMARKET_H_
#define PERSONALMONEYMARKET_H_

using namespace std;


class PersonalMoneyMarket : public PersonalAccount 
{
private:
	int numWithdrawalAllowed;//number of withdrawals per simulation
	double minBAlanceForInterest;
	double numWithdrawalDone;
public:
	PersonalMoneyMarket(string fn ="John", string ln ="Snow");
	bool Deposit(double checkAmount); //deposit check
	bool Transfer(double amount, Account* receiverAccount);
	bool Withdraw(double amount);
	void ApplyInterest();
	void display();
};
#endif