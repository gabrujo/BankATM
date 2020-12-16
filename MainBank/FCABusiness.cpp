#include "FCABusiness.h"

FCABusiness::FCABusiness(string name) : BA_checking(name)
{
	numWithdrawalDone = 0;
	numWithdrawalAllowed = 0;
	numTransferDone = 0;
	numTransferAllowed = 0;
	numDepositDone = 0;
	numDepositAllowed = 0;
}

bool FCABusiness::Deposit(double checkAmount)
{
	bool success = false;
	double finalDepositAmt = 0;
	double conversionAmt = 0;
	string foreignCurr;
	
	//User input for currency type
	cout << "Please enter type of currency you want to deposit (INR,AUD,CAD,EURO or JPY): ";
	cin >> foreignCurr;

	//Convert ForeignCurr to Upper case
	transform(foreignCurr.begin(), foreignCurr.end(), foreignCurr.begin(), ::toupper);

	//Deposit are limited (e.g. 3 per simulation).
	if (numDepositDone < numDepositAllowed)
	{
		if (foreignCurr == "USD")
			finalDepositAmt = checkAmount;
		else if (foreignCurr == "INR") {
			conversionAmt = mapOfCurrency[foreignCurr];
		}
		else if (foreignCurr == "AUD") {
			conversionAmt = mapOfCurrency[foreignCurr];
		}
		else if (foreignCurr == "CAD") {
			conversionAmt = mapOfCurrency[foreignCurr];
		}
		else if (foreignCurr == "EURO") {
			conversionAmt = mapOfCurrency[foreignCurr];
		}
		else if (foreignCurr == "JPY") {
			conversionAmt = mapOfCurrency[foreignCurr];
		}
		else{
			cout << "Invalid Foreign Currency, only INR, AUD, CAD, EURO or JPY can be deposited" << endl;
			return success;
		}

		finalDepositAmt = checkAmount / conversionAmt;
		success = BusinessAccount::Deposit(finalDepositAmt);
		if (success)
		{
			numTransferDone++;
		}
	}
	else
	{
		cout << "Cannot do Deposit. Number of available Deposits (" << numDepositAllowed << ") exceeded." << endl;
	}
	return success;
}


bool FCABusiness::Transfer(double amount, Account* receiverAccount)
{
	bool success = false;
	//Transfers are limited (e.g. 3 per simulation).
	if (numTransferDone < numTransferAllowed)
	{
		success = BusinessAccount::Transfer(amount, receiverAccount);
		if (success)
		{
			numTransferDone++;
		}
	}
	else
	{
		cout << "Cannot do Transfer. Number of available Transfers (" << numTransferAllowed << ") exceeded." << endl;
	}
	return success;
}

bool FCABusiness::Withdraw(double amount)
{
	bool success = false;
	//Withdrawals are limited (e.g. 3 per simulation).
	if (numWithdrawalDone < numWithdrawalAllowed)
	{
		success = BusinessAccount::Withdraw(amount);
		if (success)
		{
			numWithdrawalDone++;
		}
	}
	else
	{
		cout << "Cannot do withdrawal. Number of available withdrawals (" << numWithdrawalAllowed << ") exceeded." << endl;
	}
	return success;
}

void FCABusiness::ApplyInterest()
{
}


void FCABusiness::BalanceInquiry()
{
	//BusinessAccount::BalanceInquiry();
	cout << "Available Balance Foreign Checking Account: " << getBalance() << endl;
}

void FCABusiness::display()
{
	BusinessAccount::display();
	cout << "Account type is Foreign Currency Account " << endl;
}

