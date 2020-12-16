#include "PersonalCD.h"

PersonalCD::PersonalCD(string fn, string ln) : PersonalAccount(fn, ln)
{
	PersonalAccount::setInterest(0.04);//interest 4%
	numWithdrawalAllowed = 3;
	numWithdrawalDone = 0;
	frozenamount = 0;
	depositInterest = 0.01;
	withdrawInterest = 0.03;
}

bool PersonalCD::Deposit(double checkAmount)
{
	activateFrozen();
	bool success = PersonalAccount::Deposit(checkAmount);
	if (success)
	{
		frozenamount = checkAmount;
	}
	cout << endl;
	return success;
}

bool PersonalCD::Transfer(double amount, Account* receiverAccount)
{
	bool success = false;
	if (amount > getBalance() - frozenamount)
	{
		cout << "Not enough available balance for the transfer" <<endl;
		BalanceInquiry();
	}
	else {
		success = PersonalAccount::Transfer(amount, receiverAccount);
	}
	cout << endl;
	return success;
}
	

bool PersonalCD::Withdraw(double amount)
{
	if ((int)amount % 10 != 0) {
		cout << " Amount for withdrawal must be a multiple of 10." << endl;
		return false;
	}

	//Withdrawals may be allowed on the interest but only a limited number.
	bool success = false;
	double fee = amount * withdrawInterest;
	cout << "Amount to be withdrawn: " << amount << endl;
	cout << "Fee for the withdraw transaction is: " << fee << endl;
	amount = amount + fee;//apply interest

	if (amount > getBalance() - frozenamount)
	{
		cout << "Not enough available balance for the withdraw" << endl;
		BalanceInquiry();
	}
	else {
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
			cout << "Cannot do withdrawal. Number of available withdrawals (" << numWithdrawalAllowed << ") exceeded." << endl;
		}
	}
	cout << endl;
	return success;
}

void PersonalCD::ApplyInterest()
{
	PersonalAccount::ApplyInterest();
}


void PersonalCD::activateFrozen()
{
	if(frozenamount > 0)
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



void PersonalCD::BalanceInquiry()
{
	PersonalAccount::BalanceInquiry();
	if (frozenamount > 0)
	{
		cout << "Available for transfer and withdrawal: " << getBalance() - frozenamount << endl;
		cout << "Temporary unavailable balance is: " << frozenamount << endl;
	}
}


void PersonalCD::display()
{
	PersonalAccount::display();
	cout << "Account type is Personal Certificates of Deposits" << endl; // we can use typedef later
}
