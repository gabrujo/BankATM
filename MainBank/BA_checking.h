#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include "BusinessAccount.h"
# include "Account.h"
#ifndef BA_CHECKING_H_
#define BA_CHECKING_H_

using namespace std;


class BA_checking :public BusinessAccount {
	
	public:
		BA_checking(string company = "University of Bridgeport");
		bool Deposit(double checkAmount); //deposit check
		bool Transfer(double amount, Account* receiverAccount);
		bool Withdraw(double amount);
		void BalanceInquiry();
		void ApplyInterest();
		void display();
};
#endif