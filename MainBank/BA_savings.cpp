#include "BA_savings.h"

BA_savings::BA_savings(string name) : BusinessAccount(name) {
	BusinessAccount::setInterest(0.0);
}

bool BA_savings::Deposit(double checkAmount) {
	bool success = BusinessAccount::Deposit(checkAmount);
	cout << endl;
	return success;
}

bool BA_savings::Transfer(double amount, Account * receiverAccount) {
	bool success = true;
	BusinessAccount::Transfer(amount, receiverAccount);
	cout << endl;
	return success;
}

bool BA_savings::Withdraw(double amount) {
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

void BA_savings::ApplyInterest() {
	BusinessAccount::ApplyInterest();
}

void BA_savings::BalanceInquiry()
{
	BusinessAccount::BalanceInquiry();
	cout << "Available for transfer and withdrawal: " << getBalance() << endl;

}

void BA_savings::display()
{
	BusinessAccount::display();
	cout << "Account type is Business Saving " << endl;
}
