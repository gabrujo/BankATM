#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include<vector>

using namespace std;

Account::Account(double bal)
{
	//accountID starts assigning IDs from 1 and goes up using static count currentID
	accountID = currentID; 
	currentID++;
	balance = bal;
	interest = 0;
}

bool Account::Deposit(double checkAmount)
{
	//call this deposit from the child class to reuse the code

	//add transaction to history:
	Transaction trans(checkAmount, TransactionType::Deposit);
	history.push_back(trans); //need to get const

	cout << "Balance before the deposit: " << balance << endl;
	cout << "Amount to be deposited: " << checkAmount << endl;
	//do deposit:
	if (checkAmount > 0) {
		balance += checkAmount;
		cout << "Balance after deposit: " << balance << endl;
		return true;
	}
	else {
		cout << "Invalid amount" << endl;
		return false;
	}
}

bool Account::Transfer(double amount, Account* receiverAccount)
{
	//add transaction to history
	Transaction trans(amount, TransactionType::Transfer);
	history.push_back(trans);

	cout << "Balance before the transfer: " << balance << endl;
	cout << "Amount to be transfered: " << amount << endl;

	//check if receiver exists and amount is positive
	if (receiverAccount->accountID < currentID && amount>0) {
		if (balance >= amount) { //check that balance allows to transfer such amount
			balance -= amount;
			receiverAccount->balance += amount;
			cout << "Balance after transfer: " << balance << endl;
			return true;
		}
		else {
			cout << "Not enough money on your balance!" << endl;
			return false;
		}
	}
	else {
		cout << "Invalid amount or invalid account entered" << endl;
		return false;
	}

}

bool Account::Withdraw(double amount)
{
	//add transaction to history
	Transaction trans(amount, TransactionType::Withdraw);
	history.push_back(trans);

	cout << "Balance before the withdraw: " << balance << endl;

	//do withdraw
	if (amount>0) {
		if (balance >= amount) { //check that balance allows to transfer such amount
			balance -= amount;
			cout << "Balance after withdraw: " << balance << endl;
			return true;
		}
		else {
			cout << "Not enough money on your balance!" << endl;
			return false;
		}
	}
	else {
		cout << "Invalid amount entered" << endl;
		return false;
	}
}

void Account::ApplyInterest()
{
	balance += balance * interest;

}

void Account::display()
{
	cout << "Account ID: " << accountID <<endl;
}




