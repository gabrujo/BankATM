#include "CAPersonal.h"

CAPersonal::CAPersonal(string f, string l) : PersonalAccount(f, l)
{

}

bool CAPersonal::Deposit(double checkAmount)
{
	return PersonalAccount::Deposit(checkAmount);
}

bool CAPersonal::Transfer(double amount, Account* receiverAccount)
{
	return PersonalAccount::Transfer(amount, receiverAccount);
}

bool CAPersonal::Withdraw(double amount)
{
	return PersonalAccount::Withdraw(amount);
}

void CAPersonal::ApplyInterest()
{
	PersonalAccount::ApplyInterest();
}

void CAPersonal::BalanceInquiry()
{
	PersonalAccount::BalanceInquiry();
	{
		cout << "Available for transfer and withdrawal: " << getBalance() << endl;
	}
}

void CAPersonal::display()
{
	PersonalAccount::display();
	cout << "Account type is Personal Checking Account " << endl;
}
