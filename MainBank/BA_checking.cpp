#include "BA_checking.h"

BA_checking::BA_checking(string name): BusinessAccount(name) {
	BusinessAccount::setInterest(0.0);
}

bool BA_checking::Deposit(double checkAmount)
{
	bool success = BusinessAccount::Deposit(checkAmount);
	cout << endl;
	return success;
}

bool BA_checking::Withdraw(double amount)
{
	if ((int)amount % 10 != 0) {
		cout << " Amount for withdrawal must be a multiple of 10." << endl;
		return false;
	}
	BusinessAccount::Withdraw(amount);
	bool success = false;
	cout << "Amount to be withdrawn: " << amount << endl;
	cout << endl;
	return success;
}


bool BA_checking::Transfer(double amount, Account * receiverAccount)
{
	bool success = true;
	BusinessAccount::Transfer(amount, receiverAccount);
	cout << endl;
	return success;
}

void BA_checking::ApplyInterest()
{
	BusinessAccount::ApplyInterest();
}

void BA_checking::BalanceInquiry()
{
	BusinessAccount::BalanceInquiry();
	cout << "Available for transfer and withdrawal: " << getBalance() << endl;	
}

void BA_checking::display()
{
	BusinessAccount::display();
	cout << "Account type is Business Checking " << endl;
}


