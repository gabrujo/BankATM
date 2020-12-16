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
#include "Account.h"
#ifndef CAPERSONAL_H_
#define CAPERSONAL_H_


using namespace std;

class CAPersonal: public PersonalAccount //Modifiy according to parent class name given 
{
private:
	string transactionID;
	double depositeAmount;
	double withdrawAmount;
	double transferAmount;
public:
	CAPersonal(string fn="Kate", string ln="Green");
	bool Deposit(double checkAmount);
	bool Transfer(double amount, Account* receiverAccount);
	bool Withdraw(double amount);
	void ApplyInterest();
	void BalanceInquiry();
	void display();
};
#endif

