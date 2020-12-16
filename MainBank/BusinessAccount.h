#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <stdlib.h>
#include "Account.h"
#ifndef BUSINESSACCOUNT_H_
#define BUSINESSACCOUNT_H_

static int lastbusinessID = 1;

class BusinessAccount:public Account {
	
	private:
		int businessID;//will be later used to display account ID in the following format A1P1S1
		int EIN; //Employer Identification Number
		string CompanyName;
		int findEIN(); //An employer identification number (EIN) is a nine-digit number assigned by the IRS
	

	public:
		BusinessAccount(string company = "University of Bridgeport");
		string getCompanyName() { return CompanyName; }
};
#endif
