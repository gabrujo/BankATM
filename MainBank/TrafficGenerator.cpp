#include <iostream>
#include <string>
#include <tuple>
#include <queue>
#include <fstream>
#include <iterator>

#include "TrafficGenerator.h"
#include "Account.h"

#include "BA_savings.h"
#include "BA_checking.h"
#include "FCABusiness.h"
#include "HVCABusiness.h"

#include "CAPersonal.h"
#include "PersonalMoneyMarket.h"
#include "SAPersonal.h"
#include "PersonalCD.h"

using namespace std;

TrafficGenerator::TrafficGenerator(string file)
{
	parseFile(file);
	countTime = 0;
	AvSerTime = 0;
	/*transactionsToPercentile =
	{
			{40, "Deposit"},
			{80, "Withdraw"},
			{100, "Tranfer"}
	};*/
}

void TrafficGenerator::parseFile(string file)
{
	ifstream input(file);
	input >> customerBase;
	input >> initCustomersNum;
	input >> dynCustomersNum;
	int val1, val2;
	input >> val1 >> val2;
	serviceTimeRange = make_tuple(val1, val2);
	input >> multAccountPercentile;
	string typeName;
	input >> typeName;
	if (typeName == "Personal") {
		input >> persAccountPercentile;
	}
	input >> typeName >> typeName;//ignore Business line
	int pSum = 0;
	int bSum = 0;
	while (input.good())
	{
		input >> typeName;
		input >> val1 >> val2;
		if (val1 != 0)
		{
			pertypesToPercentile.insert(pair<int, string>(val1 + pSum, typeName));
			//pertypesToPercentile[val1 + pSum] = typeName;
		}
		if (val2 != 0)
		{
			bustypesToPercentile.insert(pair<int, string>(val2 + bSum, typeName));
		}
		pSum += val1;
		bSum += val2;
	}

	input.close();
}

Customer TrafficGenerator::generateCust()
{
	int serviceTime, multAccountcheck, numOfAccounts;
	int PorB, accountType;
	string accType;
	int range = get<1>(serviceTimeRange) - get<0>(serviceTimeRange) + 1;
	Account* pt;
	serviceTime = rand() % range + get<0>(serviceTimeRange);
	Customer cust(0, serviceTime);
	
	multAccountcheck = rand() % 101;
	if (multAccountcheck > multAccountPercentile)// one account
		numOfAccounts = 1;
	else //multiple accounts
		numOfAccounts = rand() % 3 + 2;//2-4 accounts

	for (int i = 0; i < numOfAccounts; i++) 
	{
		//generates one Account at a time
		PorB = rand() % 101;
		accountType = rand() % 101;
		if (PorB > persAccountPercentile)// business account
		{
			for (auto const& x : bustypesToPercentile)
			{
				if (accountType < x.first)
				{
					accType = x.second;
					break;
				}
			}
			if (accType == "Savings")
			{
				pt = new BA_savings();
				accType = "BSA";//abbreviation used to add accounts into Customer class
			}
			else if (accType == "Checking")
			{
				pt = new BA_checking();
				accType = "BCA";
			}
			else if (accType == "HighVolumeChecking")
			{
				pt = new HVCABusiness();
				accType = "BHVC";
			}
			else //ForeignCurrency
			{
				pt = new FCABusiness();
				accType = "BFC";
			}
		}
		else {
			for (auto const& x : pertypesToPercentile)
			{
				if (accountType < x.first)
				{
					accType = x.second;
					break;
				}
			}
			if (accType == "Savings")
			{
				pt = new SAPersonal();
				accType = "PSA";//abbreviation used to add accounts into Customer class
			}
			else if (accType == "Checking")
			{
				pt = new CAPersonal();
				accType = "PCA";
			}
			else if (accType == "MoneyMarket")
			{
				pt = new PersonalMoneyMarket();
				accType = "PMM";
			}
			else //CertificateOfDeposits
			{
				pt = new PersonalCD();
				accType = "PCD";
			}
		}
		if (cust.getAccount(accType) == nullptr)
		{
			cust.addAccount(accType, pt);
		}
		else {
			numOfAccounts++;//not add this account as it is repeatative and create one more
		}
	}
	return cust;
}

void TrafficGenerator::displayInfo()
{
	cout << "Customer Base: " << customerBase << endl;
	cout << "Initial Customer Number: " << initCustomersNum << endl;
	cout << "Dynamic Customer Number: " << dynCustomersNum << endl;
	cout << "Service time range is from " << get<0>(serviceTimeRange)<<" to "<< get<1>(serviceTimeRange)<< endl;
	cout << "Percentage of users with multiple accounts: " << multAccountPercentile << "%"<< endl;
	cout << "Percentage of personal accounts: " << persAccountPercentile << "%"<< endl;
	cout << "Personal account percentiles: " << endl;
	map<int, string>::iterator iter;
	for (iter = pertypesToPercentile.begin(); iter != pertypesToPercentile.end(); ++iter)
	{
		cout << (*iter).first << ": " << (*iter).second << endl;
	}
	cout << "Business account percentiles: " << endl;
	for (iter = bustypesToPercentile.begin(); iter != bustypesToPercentile.end(); ++iter)
	{
		cout << (*iter).first << ": " << (*iter).second << endl;
	}
}

queue<Customer>& TrafficGenerator::getInitTraffic() {
	//returns queue of 5 Customers
	queue<Customer> custs;
	return custs;
}


vector<Customer> TrafficGenerator::initCustomerBase()
{
    /* Use statistical values that were read from the file to generate and return 
    queue of inital Customers*/

	vector<Customer>allCustomers;
	for (int j = 0; j < customerBase; j++) {
		//generates one Customer at a time
		Customer cust = generateCust();
		allCustomers.push_back(cust);
	}
	return allCustomers;

}


