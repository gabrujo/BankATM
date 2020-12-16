#include "Customer.h"

Customer::Customer()
{
	custID = ID; // starts assigning IDs from 1 and goes up using static count currentID
	ID++;
	arrivalTime = 0;
	serviceTime = 0;
	exitTime = 0;
	timeLeft = serviceTime;
}

Customer::Customer(int aTime, int sTime)
{
	custID = ID; // starts assigning IDs from 1 and goes up using static count currentID
	ID++;
	arrivalTime = aTime;
	serviceTime = sTime;
	timeLeft = serviceTime;
}

void Customer::addAccount(string accountType, Account* accountObj)
{
	// Please follow this nomanclature for input string accountType
	// For Personal Savings - "PSA"
	// For Personal Checking - "PCA"
	// For Personal Money Market - "PMM"
	// For Personal Certifiation of Deposit - "PCD"
	// For Business Savings - "BSA"
	// For Business Checking - "BCA"
	// For Business High Volume Checking - "BHVC"
	// For Business Foreign Currency - "BFC"

	accountMap.insert({ accountType, accountObj });

}

Account* Customer::getAccount(string accountType)
{
	// Please follow this nomanclature for input string accountType
	// For Personal Savings - "PSA"
	// For Personal Checking - "PCA"
	// For Personal Money Market - "PMM"
	// For Personal Certifiation of Deposit - "PCD"
	// For Business Savings - "BSA"
	// For Business Checking - "BCA"
	// For Business High Volume Checking - "BHVC"
	// For Business Foreign Currency - "BFC"

	Account* accountReturn = nullptr;
	if (accountMap.find(accountType) != accountMap.end()) {
		accountReturn = accountMap[accountType];
	}
	return accountReturn;
}


void Customer::setarrivalTime(int aTime)
{
	arrivalTime = aTime;

}

int Customer::getarrivalTime()
{
	return arrivalTime;
}

void Customer::setserviceTime(int sTime)
{
	serviceTime = sTime;
}

int Customer::getserviceTime()
{
	return serviceTime;
}

void Customer::setexitTime(int eTime)
{
	exitTime = eTime;
}

int Customer::getexitTime()
{
	return exitTime;
}


void Customer::displayAccounts()
{
	cout << "Available accounts are:" << endl;
	for (auto const& x : accountMap)
	{
		cout << "Account: " << x.first << endl;
		cout << "Pointer: "<< x.second << endl;
	}

}
