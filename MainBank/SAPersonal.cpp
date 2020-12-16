#include "SAPersonal.h"

SAPersonal::SAPersonal()
{
}

SAPersonal::SAPersonal(string fn, string ln) : PersonalAccount(fn, ln)
{
	PersonalAccount::setInterest(0.06);//interest 6%
	frozenamount = 0;
	depositInterest = 0.01;
}

bool SAPersonal::Deposit(double checkAmount)
{
	return PersonalAccount::Deposit(checkAmount);
}

bool SAPersonal::Transfer(double amount, Account* receiverAccount)
{
	return PersonalAccount::Transfer(amount, receiverAccount);
}

bool SAPersonal::Withdraw(double amount)
{
	return PersonalAccount::Withdraw(amount);
}

void SAPersonal::ApplyInterest()
{
	PersonalAccount::ApplyInterest();	
}

void SAPersonal::activateFrozen()
{
	if (frozenamount > 0)
	{
		cout << "Depositing the interest earned by leaving funds in the account for the specific time..." << endl;
		double earnedInterest = frozenamount * depositInterest;//apply interest
		cout << "You earned: " << earnedInterest << endl;
		bool success = PersonalAccount::Deposit(earnedInterest);
		if (success)
		{
			frozenamount = 0;
		}
		cout << endl;
	}
}


void SAPersonal::display()
{
	PersonalAccount::display();
	cout << "Account type is Personal Saving Account " << endl;
}
