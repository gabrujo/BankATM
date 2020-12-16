#include "PersonalMoneyMarket.h"

PersonalMoneyMarket::PersonalMoneyMarket(string fn, string ln): PersonalAccount(fn, ln)
{
	PersonalAccount::setInterest(0.03);//interest 3%
	numWithdrawalAllowed = 3;
	numWithdrawalDone = 0;
	minBAlanceForInterest = 1000;
}

bool PersonalMoneyMarket::Deposit(double checkAmount)
{
	return PersonalAccount::Deposit(checkAmount);
}

bool PersonalMoneyMarket::Transfer(double amount, Account* receiverAccount)
{
	return PersonalAccount::Transfer(amount, receiverAccount);
}

bool PersonalMoneyMarket::Withdraw(double amount)//the only one needs modification here
{
	bool success = false;
	//Withdrawals are limited (e.g. 3 per simulation).
	if (numWithdrawalDone < numWithdrawalAllowed)
	{
		success = PersonalAccount::Withdraw(amount);
		if (success)
		{
			numWithdrawalDone++;
		}    
	}
	else 
	{
		cout << "Cannot do withdrawal. Number of available withdrawals ("<<numWithdrawalAllowed<<") exceeded." << endl;
	}
	return success;
}

void PersonalMoneyMarket::ApplyInterest()
{
	if (getBalance() > minBAlanceForInterest)
	{
		PersonalAccount::ApplyInterest();
	}
}

void PersonalMoneyMarket::display()
{
	PersonalAccount::display();
	cout << "Account type is Personal Money Market Account" << endl;
}
